# SPL Lab Solutions - website

This folder is named `docs/` because GitHub Pages can serve a site from the
repository root or from `/docs`, and the solutions live in the root.

A static site with every problem from the SPL lab: the question from the
problem set, the sample input/output, and the full C solution.

134 problems across 8 topics (Intro through Strings).

## Files

| File | What it is |
| --- | --- |
| `index.html` | Homepage with one card per topic. **Generated** |
| `01-intro.html` … `08-strings.html` | One page per topic. **Generated** |
| `cheatsheet.html` | Revision page for topics 1-8. **Generated** |
| `cheatsheet-body.html` | The cheatsheet's content. Hand written |
| `cheatsheet.css` | Cheatsheet-only styling. Hand written |
| `style.css` | All the styling. Light and dark, in sections. Hand written |
| `app.js` | Syntax colouring + the Copy buttons. Hand written |
| `questions.json` | The questions, pulled out of the .docx problem set. **Generated** |
| `import_questions.py` | Reads the problem set .docx files, writes `questions.json` |
| `build.py` | Reads `questions.json` + the `.c` files, writes the HTML |

Only the files marked "generated" are rebuilt by the scripts. Editing
`style.css`, `app.js`, `cheatsheet.css` or `cheatsheet-body.html` never gets
overwritten.

## The cheatsheet

`cheatsheet.html` is built from `cheatsheet-body.html` wrapped in the same
header and footer as every other page, so the navigation stays in step. Its
styling is in `cheatsheet.css`, loaded after `style.css` and only on that page.
Every class there starts with `cs-` so it cannot collide with the rules that
style the problem pages. Amber callouts mark mistakes that cost marks, green
ones mark patterns worth memorising — the colour carries meaning, so keep that
distinction if you edit it.

To change the cheatsheet, edit `cheatsheet-body.html` and re-run `build.py`.

## Rebuilding

Nothing to install - both scripts use only the Python standard library.

```bash
python3 import_questions.py   # only needed if the problem set changes
python3 build.py              # after editing a .c file or a blurb
```

`build.py` reads the solutions straight from the folders one level up
(`../01 Intro`, `../02 Operators`, and so on), so fixing a bug in a `.c` file
and re-running `build.py` is enough to update the site.

## How the question text is matched to a solution

The problem set has one `.docx` per topic, laid out as a table:

```
SL | Problem statement | Difficulty
```

`import_questions.py` reads those rows in order and pairs question *N* with
solution file *N* (`01.c`, `02.c`, …). Every topic has exactly as many
questions as solution files, and the script prints a warning if that ever
stops being true.

The statement cell usually holds a nested "Sample input | Sample output"
table, which is pulled out separately so the site can show it as a table.

Two small clean-ups happen on the way in: a leading list number typed by hand
("4.") is stripped, and the manual's shorthand "WAP" is expanded to
"Write a program". Otherwise the wording is exactly as written in the manual,
including the `_` characters the manual uses to show spaces in patterns.

## Adding a topic

Add an entry to `CATEGORIES` in `build.py` and to `MANUALS` + `FOLDERS` in
`import_questions.py`, then re-run both scripts. Topics 09-13 (Function,
Structure, Pointer, File, Recursion) are not on the site yet.

## Publishing

The folder is plain HTML, CSS and JavaScript with no build step and no
dependencies, so it can be served as-is.

To switch it on: repository **Settings -> Pages**, set Source to
"Deploy from a branch", branch `main` and folder `/docs`. The site then
appears at `https://namaray.github.io/SPL/`.
