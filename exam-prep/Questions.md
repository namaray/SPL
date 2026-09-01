# SPL Lab - Exam Prep

Three practice questions built from the 45 problems in 01 Intro, 02 Operators and 03 Conditions.
Every sample output below came from actually running the solution file.

Compile with:

    gcc "01. Data Types and Format Specifiers.c" -o out -lm

The -lm flag is required for Q2 (math.h).


# Question 1 - Data Types and Format Specifiers

Solution: `01. Data Types and Format Specifiers.c`
From: Intro 04, 07, 08, 10-15


## Task

Write a program that stores a shop's daily record.

1. Define VAT as 0.15 using #define, and DISCOUNT as 0.05 using const float.

2. Using a single scanf, read an int item code, a float unit price, and a char
   category code. The second value on the line is a stock count that must be
   read and discarded, not stored.

3. Compute:

       total = price + price * VAT - price * DISCOUNT

4. Print the item code, the category character, then the total three times:
   to 2 decimal places, in exponential notation, and in a field width of 15.

5. Print the size in bytes of int, float and char.


## Input

    101 50 24.50 A


## Output

    Item Code: 101
    Category: A
    Total: 26.95
    Total: 2.695000e+01
    Total:           26.95
    Size of int = 4, float = 4, char = 1


## Concepts

- %*d for assignment suppression (read a value without storing it)
- #define vs const
- Format specifiers: %.2f, %e, and field width %15.2f
- sizeof


## Watch out

- sizeof returns size_t, so cast it to int before printing with %d.
- Test your scanf format string. A %c after a number often picks up the
  leftover space or newline instead of the character you wanted.


# Question 2 - Operators and math.h

Solution: `02. Operators and Math Functions.c`
From: Operators 01, 03, 07, 08, 12, 13, 14


## Task

Read two floating point numbers a and b, then print:

1. a + b, a - b, a * b

2. The quotient and remainder of a and b. The % operator does not work on
   floats, so cast to int first.

3. The larger of the two, using the ternary operator only. No if.

4. The value of P, to 4 decimal places:

       P = (2.5 * a^2 + sqrt(|b|)) / (1 + sin(a))

5. ceil(a / b), floor(a / b) and fabs(a - b).

If b is 0, print "Error: division by zero" in place of steps 2 and 5, but
still print steps 1, 3 and 4.


## Input 1

    7.5 2.0


## Output 1

    Sum: 9.5
    Difference: 5.5
    Product: 15
    Quotient: 3, Remainder: 1
    Max: 7.5
    P = 73.2916
    Ceil: 4, Floor: 3, Abs Diff: 5.5


## Input 2 - division by zero

    7.5 0


## Output 2

    Sum: 7.5
    Difference: 7.5
    Product: 0
    Error: division by zero
    Max: 7.5
    P = 72.5619


## Concepts

- Type casting with (int), and integer vs floating point division
- The % operator only accepting integer operands
- Ternary operator ? :
- math.h: pow, sqrt, sin, ceil, floor, fabs
- Guarding against division by zero


## Watch out

- Link the math library: gcc file.c -o out -lm
  Without it you get "undefined reference to sqrt".
- sin() takes radians, not degrees. To convert: rad = deg * M_PI / 180.0


# Question 3 - Nested Conditions and Menu Logic

Solution: `03. Menu Based Result System.c`
From: Conditions 04, 08, 09, 11, 13, 14


## Task

Write a menu driven student result system.

    1. Check Grade
    2. Check Leap Year
    3. Classify Character

Read the choice first, then handle it.


### Choice 1 - Check Grade

Read a mark m. If m < 0 or m > 100, print "Invalid marks".
Otherwise print the grade:

    m >= 90    A
    m >= 80    B
    m >= 70    C
    m >= 60    D
    else       F

If the grade is A, read a second input, the attendance percentage.
Print "Grade: A+" if attendance >= 90, otherwise "Grade: A".


### Choice 2 - Check Leap Year

Read a year. Reject years <= 0 with "Invalid year".
Otherwise print "Leap Year" or "Not a Leap Year".


### Choice 3 - Classify Character

Read a character and print "Uppercase", "Lowercase", "Digit" or
"Special Character".


### Any other choice

Print "Invalid choice".


## Sample runs

    Input           Output
    -----           ------
    1  95  92       Grade: A+
    1  95  70       Grade: A
    1  105          Invalid marks
    2  2024         Leap Year
    2  1900         Not a Leap Year
    3  @            Special Character
    7               Invalid choice


## Concepts

- if / else if ladders and nested conditions
- Input validation before processing
- Character range checks such as c >= 'A' && c <= 'Z'
- Leap year: (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)


## Watch out

- Order matters in an else if ladder. Check >= 90 before >= 80, never
  the other way around.
- Read the character with scanf(" %c", &c). The leading space skips the
  leftover newline from the previous scanf. Without it you read '\n' and
  always get "Special Character".
- 1900 is not a leap year. Divisible by 100 but not by 400. Classic trap.
