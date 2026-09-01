# SPL

Solutions to the Structured Programming Language (SPL) lab problem set, in C.

**Read it online: <https://namaray.github.io/SPL/>** — every question shown next
to its solution, plus a [midterm cheatsheet](https://namaray.github.io/SPL/cheatsheet.html)
covering topics 1–8.

## Layout

| Folder | Topic | Problems | Read online |
| --- | --- | --- | --- |
| [`01 Intro`](01%20Intro) | printf, scanf, variables, data types | 15 | [Intro](https://namaray.github.io/SPL/01-intro.html) |
| [`02 Operators`](02%20Operators) | Arithmetic, logical, relational, casting, math.h | 15 | [Operators](https://namaray.github.io/SPL/02-operators.html) |
| [`03 Conditions`](03%20Conditions) | if / else if / else, menu driven branching | 15 | [Conditions](https://namaray.github.io/SPL/03-conditions.html) |
| [`04 Loop`](04%20Loop) | for, while, do-while, series, number theory | 20 | [Loops](https://namaray.github.io/SPL/04-loop.html) |
| [`05 Array`](05%20Array) | 1D arrays: search, sort, set operations | 21 | [Arrays](https://namaray.github.io/SPL/05-array.html) |
| [`06 Nested loop`](06%20Nested%20loop) | Star patterns and number pyramids | 18 | [Nested Loops](https://namaray.github.io/SPL/06-nested-loop.html) |
| [`07 2d array`](07%202d%20array) | Matrices | 15 | [2D Arrays](https://namaray.github.io/SPL/07-2d-array.html) |
| [`08 Strings`](08%20Strings) | Character arrays, walked manually (no `string.h`) | 15 | [Strings](https://namaray.github.io/SPL/08-strings.html) |
| [`09 Function`](09%20Function) … [`13 Recursion`](13%20Recursion) | Functions, structures, pointers, files, recursion | 63 | — |
| [`exam-prep`](exam-prep) | Practice questions combining earlier topics | 3 | — |
| [`docs`](docs) | The website itself (see [`docs/README.md`](docs/README.md)) | — | — |

The site covers topics 01–08. Topics 09–13 are in the repository but not on the
site yet.

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

GitHub Pages serves this repository from the `docs/` folder on `main`, so a
rebuilt page goes live as soon as it is pushed. See [`docs/README.md`](docs/README.md)
for how the questions are imported from the problem set.
