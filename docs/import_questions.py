#!/usr/bin/env python3
"""
Reads the lab manual (.docx files in the "Problem set" folder) and writes
questions.json, which build.py then turns into the website.

Run it whenever the manual changes:

    python3 import_questions.py

Each .docx is one big table:

    SL | Problem statement | Difficulty

The statement cell usually holds a nested 2-column table of
"Sample input | Sample output" pairs, which is pulled out separately.

Only the Python standard library is used: a .docx is a zip file with an
XML document inside, so zipfile + ElementTree is enough.
"""

import json
import re
import zipfile
from pathlib import Path
from xml.etree import ElementTree as ET

# The WordprocessingML namespace that prefixes every tag in document.xml.
W = "{http://schemas.openxmlformats.org/wordprocessingml/2006/main}"

WEBSITE_DIR = Path(__file__).resolve().parent
PROBLEM_SET_DIR = WEBSITE_DIR.parent.parent / "Problem set"

# Website category id -> the .docx file holding its questions.
# (The "06 Nested loop" file has a "(1)" in its name.)
MANUALS = {
    "01-intro": "01 Intro.docx",
    "02-operators": "02 Operators.docx",
    "03-conditions": "03 Conditions.docx",
    "04-loop": "04 Loop.docx",
    "05-array": "05 Array.docx",
    "06-nested-loop": "06 Nested loop (1).docx",
    "07-2d-array": "07 2d array.docx",
    "08-strings": "08 Strings.docx",
}

# Category id -> folder of .c solutions, so question N can be matched to file N.
FOLDERS = {
    "01-intro": "01 Intro",
    "02-operators": "02 Operators",
    "03-conditions": "03 Conditions",
    "04-loop": "04 Loop",
    "05-array": "05 Array",
    "06-nested-loop": "06 Nested loop",
    "07-2d-array": "07 2d array",
    "08-strings": "08 Strings",
}


# --------------------------------------------------------------------------
# Reading the Word XML
# --------------------------------------------------------------------------


def paragraph_text(p):
    """Text of a single <w:p>, keeping tabs and manual line breaks."""
    pieces = []
    for node in p.iter():
        if node.tag == f"{W}t":
            pieces.append(node.text or "")
        elif node.tag == f"{W}tab":
            pieces.append("\t")
        elif node.tag == f"{W}br":
            pieces.append("\n")
    return "".join(pieces)


def children_named(element, tag):
    """Direct children with the given tag (not the whole subtree)."""
    return [child for child in element if child.tag == tag]


def read_cell(tc):
    """
    A table cell as an ordered list of blocks.
    Each block is either ("text", str) or ("table", rows).
    """
    blocks = []
    for child in tc:
        if child.tag == f"{W}p":
            blocks.append(("text", paragraph_text(child)))
        elif child.tag == f"{W}tbl":
            blocks.append(("table", read_table(child)))
    return blocks


def read_table(tbl):
    """A table as a list of rows; each row is a list of cells."""
    return [
        [read_cell(tc) for tc in children_named(tr, f"{W}tc")]
        for tr in children_named(tbl, f"{W}tr")
    ]


def text_of(blocks):
    """Join just the text blocks of a cell, one per line."""
    return "\n".join(text for kind, text in blocks if kind == "text")


# --------------------------------------------------------------------------
# Turning the raw text into clean questions
# --------------------------------------------------------------------------


def tidy_statement(raw):
    """Collapse a statement to one clean paragraph."""
    lines = [line.strip() for line in raw.split("\n")]
    lines = [line for line in lines if line]
    if not lines:
        return ""
    # Drop a leading list number the manual sometimes types by hand: "4." / "5)".
    lines[0] = re.sub(r"^\d+\s*[.)]\s*", "", lines[0])
    text = re.sub(r"\s+", " ", " ".join(lines)).strip()
    # The manual writes "WAP" (write a program); spell it out for readability.
    return re.sub(r"^[Ww][Aa][Pp]\b", "Write a program", text)


def tidy_sample(raw):
    """Trim blank lines and trailing spaces from a sample input/output."""
    return "\n".join(
        line.rstrip() for line in raw.split("\n") if line.strip()
    )


def find_samples(blocks):
    """Pull the Sample input / Sample output pairs out of a statement cell."""
    samples = []
    for kind, value in blocks:
        if kind != "table":
            continue
        rows = value
        if not rows:
            continue
        header = " ".join(text_of(cell) for cell in rows[0]).lower()
        if "sample" not in header:
            continue
        for row in rows[1:]:
            if len(row) < 2:
                continue
            given = tidy_sample(text_of(row[0]))
            expected = tidy_sample(text_of(row[1]))
            if given or expected:
                samples.append({"input": given, "output": expected})
    return samples


def parse_manual(path):
    """Return the list of problems in one .docx, in document order."""
    with zipfile.ZipFile(path) as archive:
        root = ET.fromstring(archive.read("word/document.xml"))
    body = root.find(f"{W}body")

    problems = []
    for tbl in children_named(body, f"{W}tbl"):
        for row in read_table(tbl):
            if len(row) < 2:
                continue
            statement_cell = row[1]
            raw = text_of(statement_cell)
            if raw.strip().lower().startswith("problem statement"):
                continue  # the header row
            statement = tidy_statement(raw)
            if not statement:
                continue
            problems.append(
                {
                    "statement": statement,
                    "difficulty": text_of(row[2]).strip() if len(row) > 2 else "",
                    "samples": find_samples(statement_cell),
                }
            )
    return problems


def title_from_filename(filename):
    """"03. Escape Sequences.c" -> "Escape Sequences"; "07.c" -> ""."""
    stem = filename[:-2]
    return stem.split(". ", 1)[1] if ". " in stem else ""


# --------------------------------------------------------------------------
# Main
# --------------------------------------------------------------------------


def main():
    solutions_dir = WEBSITE_DIR.parent
    questions = {}

    for category_id, manual_name in MANUALS.items():
        manual_path = PROBLEM_SET_DIR / manual_name
        solution_files = sorted((solutions_dir / FOLDERS[category_id]).glob("*.c"))
        problems = parse_manual(manual_path)

        if len(problems) != len(solution_files):
            print(
                f"  ! {category_id}: {len(problems)} questions but "
                f"{len(solution_files)} solution files - check the pairing"
            )

        entries = {}
        # Question 1 pairs with solution file 1, question 2 with file 2, and so on.
        for path, problem in zip(solution_files, problems):
            entries[path.name] = {
                "title": title_from_filename(path.name),
                "statement": problem["statement"],
                "difficulty": problem["difficulty"],
                "samples": problem["samples"],
            }
        questions[category_id] = entries
        print(f"  {category_id}: {len(entries)} questions")

    out = WEBSITE_DIR / "questions.json"
    out.write_text(
        json.dumps(questions, indent=2, ensure_ascii=False) + "\n", encoding="utf-8"
    )
    total = sum(len(v) for v in questions.values())
    print(f"\nwrote questions.json ({total} questions)")


if __name__ == "__main__":
    main()
