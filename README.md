# SPL

Solutions to the Structured Programming Language (SPL) lab problem set, in C.

**Website:** the solutions are also browsable as a site, with each question
shown next to its solution — <https://namaray.github.io/SPL/>

## Layout

| Folder | Topic | Problems |
| --- | --- | --- |
| `01 Intro` | printf, scanf, variables, data types | 15 |
| `02 Operators` | Arithmetic, logical, relational, casting, math.h | 15 |
| `03 Conditions` | if / else if / else, menu driven branching | 15 |
| `04 Loop` | for, while, do-while, series, number theory | 20 |
| `05 Array` | 1D arrays: search, sort, set operations | 21 |
| `06 Nested loop` | Star patterns and number pyramids | 18 |
| `07 2d array` | Matrices | 15 |
| `08 Strings` | Character arrays and string.h | 15 |
| `09 Function` … `13 Recursion` | Functions, structures, pointers, files, recursion | 63 |
| `exam-prep` | Practice questions combining earlier topics | 3 |
| `docs` | The website (see `docs/README.md`) | — |

The site currently covers topics 01–08.

## Building and running a solution

```bash
gcc "01 Intro/01. Hello World.c" -o hello && ./hello
```

Some solutions in `02 Operators` use `math.h` and need the maths library:

```bash
gcc "02 Operators/13. Trigonometric Expression.c" -o trig -lm && ./trig
```

Compiled binaries are not committed; `.gitignore` keeps the repository to
source files only.

## Rebuilding the site

```bash
cd docs
python3 build.py
```

See `docs/README.md` for how the questions are imported from the problem set.
