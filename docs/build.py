#!/usr/bin/env python3
"""
Builds the SPL Lab solutions website.

How it works
------------
1. Read the category list below (CATEGORIES).
2. For each category, find its .c files in the Solutions folder.
3. Read the matching question from questions.json.
4. Write one HTML page per category, plus index.html.

Everything is plain Python with no libraries to install:

    python3 import_questions.py   # lab manual (.docx) -> questions.json
    python3 build.py              # questions.json + .c files -> the website

The generated .html files land next to this script, so the whole
"website" folder can be published as-is (for example with GitHub Pages).
"""

import html
import json
from collections import Counter
from pathlib import Path

# --------------------------------------------------------------------------
# Settings
# --------------------------------------------------------------------------

# This script lives in Solutions/website/, so the solutions are one level up.
WEBSITE_DIR = Path(__file__).resolve().parent
SOLUTIONS_DIR = WEBSITE_DIR.parent

# Every category shown on the site, in course order.
# "id"     -> the page filename (id + ".html") and the questions.json key
# "folder" -> the folder name on disk
# "name"   -> the title shown to the reader
# "blurb"  -> one line describing the topic, shown on the homepage card
CATEGORIES = [
    {
        "id": "01-intro",
        "folder": "01 Intro",
        "name": "Intro",
        "blurb": "printf, scanf, variables, data types and format specifiers.",
    },
    {
        "id": "02-operators",
        "folder": "02 Operators",
        "name": "Operators",
        "blurb": "Arithmetic, logical and relational operators, casting and math.h.",
    },
    {
        "id": "03-conditions",
        "folder": "03 Conditions",
        "name": "Conditions",
        "blurb": "if, else if, else and menu driven branching.",
    },
    {
        "id": "04-loop",
        "folder": "04 Loop",
        "name": "Loops",
        "blurb": "for, while and do-while, series, factorials and number theory.",
    },
    {
        "id": "05-array",
        "folder": "05 Array",
        "name": "Arrays",
        "blurb": "One dimensional arrays: searching, sorting and set operations.",
    },
    {
        "id": "06-nested-loop",
        "folder": "06 Nested loop",
        "name": "Nested Loops",
        "blurb": "Loops inside loops, star patterns and number pyramids.",
    },
    {
        "id": "07-2d-array",
        "folder": "07 2d array",
        "name": "2D Arrays",
        "blurb": "Matrices: input, traversal, transpose and multiplication.",
    },
    {
        "id": "08-strings",
        "folder": "08 Strings",
        "name": "Strings",
        "blurb": "Character arrays, string.h functions and manual string handling.",
    },
]


# --------------------------------------------------------------------------
# Reading the solutions and the questions
# --------------------------------------------------------------------------


def load_questions():
    """Return the contents of questions.json, or an empty dict if missing."""
    path = WEBSITE_DIR / "questions.json"
    if not path.exists():
        print("! questions.json not found - run import_questions.py first")
        return {}
    return json.loads(path.read_text(encoding="utf-8"))


def problem_number(filename):
    """"04. Leap Year.c" -> "04";  "12.c" -> "12"."""
    return filename.split(".")[0].strip()


# Openings shared by nearly every statement. Trimming them leaves the part
# that actually tells one problem apart from the next.
COMMON_OPENERS = [
    "Write a program that will take n integer numbers into an array, and then",
    "Write a program that will take n integer numbers in an array, and then",
    "Write a program that will take n integers into an array, and then",
    "Write a program that will take",
    "Write a program that will",
    "Write a program that",
    "Write a program to",
    "Write a program",
]


def short_label(problem):
    """A compact label for the contents list at the top of a page."""
    if problem["title"]:
        return problem["title"]

    label = problem["statement"]
    for opener in COMMON_OPENERS:
        if label.startswith(opener):
            label = label[len(opener):].strip()
            break

    if not label:
        return "Problem " + problem["number"]

    # Cut to roughly one line, on a word boundary.
    if len(label) > 62:
        label = label[:62].rsplit(" ", 1)[0] + "..."
    return label[0].upper() + label[1:]


def sample_preview(problem):
    """First couple of lines of the expected output, as a one-line preview."""
    if not problem["samples"]:
        return ""
    lines = [ln for ln in problem["samples"][0].get("output", "").split("\n") if ln.strip()]
    if not lines:
        return ""
    preview = "  /  ".join(lines[:2])
    return preview[:40] + "..." if len(preview) > 40 else preview


def contents_labels(problems):
    """
    Labels for the "On this page" list.

    Whole categories sometimes share one statement - every nested-loop problem
    reads "print a pattern based on the input integer n". When a label would
    be a duplicate, show the start of the expected output instead, since that
    is what actually tells those problems apart.
    """
    labels = [short_label(p) for p in problems]
    seen = Counter(labels)

    final = []
    for problem, label in zip(problems, labels):
        if seen[label] > 1:
            preview = sample_preview(problem)
            if preview:
                label = preview
        final.append(label)
    return final


def collect_problems(category, questions):
    """Build the list of problems for one category."""
    folder = SOLUTIONS_DIR / category["folder"]
    saved = questions.get(category["id"], {})
    problems = []

    for path in sorted(folder.glob("*.c")):
        entry = saved.get(path.name, {})
        problems.append(
            {
                "number": problem_number(path.name),
                "filename": path.name,
                "title": entry.get("title", ""),
                "statement": entry.get("statement", ""),
                "difficulty": entry.get("difficulty", ""),
                "samples": entry.get("samples", []),
                "code": path.read_text(encoding="utf-8").rstrip("\n"),
            }
        )

    return problems


# --------------------------------------------------------------------------
# Writing the HTML
# --------------------------------------------------------------------------


def esc(text):
    """Escape &, < and > so the text is safe to drop inside HTML."""
    return html.escape(text, quote=False)


def page_shell(title, description, body, active_id=None):
    """Wrap page content in the shared header, navigation and footer."""
    links = []
    for category in CATEGORIES:
        current = ' aria-current="page"' if category["id"] == active_id else ""
        links.append(
            f'      <a href="{category["id"]}.html"{current}>{esc(category["name"])}</a>'
        )
    nav_links = "\n".join(links)

    return f"""<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>{esc(title)}</title>
  <meta name="description" content="{esc(description)}">
  <link rel="stylesheet" href="style.css">
</head>
<body>

  <header class="site-header">
    <a class="logo" href="index.html">SPL&nbsp;Lab</a>
    <nav class="site-nav">
{nav_links}
    </nav>
  </header>

  <main>
{body}
  </main>

  <footer class="site-footer">
    <p>SPL Lab solutions &middot; written in C &middot; compiled with gcc</p>
  </footer>

  <script src="app.js"></script>
</body>
</html>
"""


def difficulty_badge(difficulty):
    """The manual rates difficulty with 1 to 3 stars."""
    stars = difficulty.count("*")
    if not stars:
        return ""
    words = {1: "easy", 2: "medium", 3: "hard"}
    label = words.get(stars, "hard")
    return (
        f'<span class="difficulty difficulty-{stars}" title="{label}">'
        f'{"&#9733;" * stars}</span>'
    )


def render_homepage(all_problems):
    """Build the body of index.html: an intro plus one card per category."""
    total = sum(len(problems) for problems in all_problems.values())

    cards = []
    for category in CATEGORIES:
        count = len(all_problems[category["id"]])
        cards.append(
            f"""      <a class="category-card" href="{category["id"]}.html">
        <span class="category-number">{esc(category["id"][:2])}</span>
        <h2>{esc(category["name"])}</h2>
        <p>{esc(category["blurb"])}</p>
        <span class="count">{count} problems</span>
      </a>"""
        )

    return f"""    <section class="hero">
      <h1>SPL Lab Solutions</h1>
      <p class="lede">
        Every problem from the Structured Programming Language lab, with the
        question from the problem set and the full C solution side by side.
      </p>
      <p class="stats">{total} problems &middot; {len(CATEGORIES)} topics</p>
    </section>

    <section class="category-grid">
{chr(10).join(cards)}
    </section>
"""


def render_samples(samples):
    """Render the sample input/output pairs as a small table."""
    if not samples:
        return ""

    rows = []
    for sample in samples:
        rows.append(
            f"""            <tr>
              <td><pre>{esc(sample.get("input", ""))}</pre></td>
              <td><pre>{esc(sample.get("output", ""))}</pre></td>
            </tr>"""
        )

    return f"""        <div class="samples">
          <table>
            <thead>
              <tr><th>Sample input</th><th>Sample output</th></tr>
            </thead>
            <tbody>
{chr(10).join(rows)}
            </tbody>
          </table>
        </div>"""


def render_problem(problem):
    """Build the HTML for a single problem: question, samples, then code."""
    heading = esc(problem["number"])
    if problem["title"]:
        heading += ". " + esc(problem["title"])

    parts = [
        f'      <article class="problem" id="p{esc(problem["number"])}">',
        '        <header class="problem-header">',
        f"          <h2>{heading}</h2>",
        f"          {difficulty_badge(problem['difficulty'])}",
        f'          <code class="filename">{esc(problem["filename"])}</code>',
        "        </header>",
    ]

    if problem["statement"]:
        parts.append(f'        <p class="statement">{esc(problem["statement"])}</p>')
    else:
        parts.append('        <p class="statement missing">Question text missing.</p>')

    samples = render_samples(problem["samples"])
    if samples:
        parts.append(samples)

    parts.append(
        f"""        <div class="solution">
          <div class="solution-bar">
            <span>Solution</span>
            <button class="copy-button" type="button">Copy</button>
          </div>
          <pre class="code"><code>{esc(problem["code"])}</code></pre>
        </div>
      </article>"""
    )

    return "\n".join(parts)


def render_category_page(category, problems):
    """Build the body of one category page."""
    contents = "\n".join(
        f'        <li><a href="#p{esc(p["number"])}">'
        f'<span class="n">{esc(p["number"])}</span> {esc(label)}</a></li>'
        for p, label in zip(problems, contents_labels(problems))
    )
    rendered = "\n\n".join(render_problem(p) for p in problems)

    return f"""    <section class="category-intro">
      <h1>{esc(category["name"])}</h1>
      <p class="lede">{esc(category["blurb"])}</p>
      <p class="stats">{len(problems)} problems</p>
    </section>

    <nav class="contents">
      <h2>On this page</h2>
      <ol>
{contents}
      </ol>
    </nav>

    <section class="problem-list">
{rendered}
    </section>
"""


# --------------------------------------------------------------------------
# Main
# --------------------------------------------------------------------------


def main():
    questions = load_questions()

    # Read every category's problems once, up front.
    all_problems = {}
    for category in CATEGORIES:
        all_problems[category["id"]] = collect_problems(category, questions)

    # Homepage.
    index_html = page_shell(
        title="SPL Lab Solutions",
        description="C solutions to every SPL lab problem, with the questions.",
        body=render_homepage(all_problems),
    )
    (WEBSITE_DIR / "index.html").write_text(index_html, encoding="utf-8")
    print("wrote index.html")

    # One page per category.
    for category in CATEGORIES:
        problems = all_problems[category["id"]]
        page_html = page_shell(
            title=f"{category['name']} - SPL Lab Solutions",
            description=category["blurb"],
            body=render_category_page(category, problems),
            active_id=category["id"],
        )
        (WEBSITE_DIR / f"{category['id']}.html").write_text(page_html, encoding="utf-8")
        print(f"wrote {category['id']}.html ({len(problems)} problems)")

    total = sum(len(p) for p in all_problems.values())
    missing = sum(1 for p in all_problems.values() for item in p if not item["statement"])
    print(f"\n{total} problems on the site" + (f", {missing} missing questions" if missing else ""))


if __name__ == "__main__":
    main()
