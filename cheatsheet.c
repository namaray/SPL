/* ========================================================================
   SPL Lab - both cheatsheets, all code in one file

   Every code block from the two cheatsheet pages, in the same order:
     Midterm (sets 1-8):  https://namaray.github.io/SPL/cheatsheet.html
     Final   (sets 9-13): https://namaray.github.io/SPL/final-cheatsheet.html

   A reference to read and copy from, not a program. Most blocks are
   fragments, so this does not compile as a whole. Blocks that are not
   C at all are commented out.
   ======================================================================== */


/* ########################################################################
   MIDTERM CHEATSHEET - SETS 1 TO 8
   ######################################################################## */

/* ========================================================================
   THE SKELETON
   start every answer here
   ======================================================================== */

/* --- Program shell --- */
#include <stdio.h>

int main() {
    // declare, input, process, output
    return 0;
}

/* --- Compiling --- */
// gcc solution.c -o out
// ./out
//
// # only if you used math.h
// gcc solution.c -o out -lm

/* --- The four steps of nearly every problem --- */
int n, i;
scanf("%d", &n);          // 1. how many
for (i = 0; i < n; i++)   // 2. read them
    scanf("%d", &a[i]);
// 3. compute
printf("%d\n", result);   // 4. print

/* ========================================================================
   PRINTF AND SCANF
   set 01
   ======================================================================== */

/* --- Reading several values at once --- */
int a, b;  float x;  char op;

scanf("%d %d", &a, &b);
scanf("%f %c %f", &x, &op, &x);

/* --- Reading a char safely --- */
char c;
scanf(" %c", &c);   // note the leading space

/* --- Skipping an input (assignment suppression) --- */
// input: 101 50 24.50 A
// read the 50 but do not store it
scanf("%d %*d %f %c", &code, &price, &cat);

// input: number: 78 position: 4
// skip the words, keep the numbers
scanf("%*s %d %*s %d", &num, &pos);

/* --- Escape sequences --- */
// \n   newline          \t   tab
// \\   backslash        \"   double quote
// \'   single quote     \0   null character

/* ========================================================================
   DATA TYPES, CONST AND SCOPE
   set 01
   ======================================================================== */

/* --- Sizes --- */
printf("%d\n", (int)sizeof(int));

/* --- Constants — two ways --- */
#define VAT 0.15          // no semicolon, no type
const float DISCOUNT = 0.05;  // has a type

/* --- Global vs local scope --- */
int g = 10;          // global: visible everywhere

int main() {
    int g = 20;      // local hides the global
    printf("%d", g); // prints 20
}

/* --- bool --- */
#include <stdbool.h>
bool found = true;   // prints as 1 / 0 with %d

/* ========================================================================
   OPERATORS
   set 02
   ======================================================================== */

/* --- Integer division and modulus --- */
7 / 2      // 3   (int / int throws away the rest)
7 % 2      // 1   (the remainder)
7.0 / 2    // 3.5 (one float makes it float)
(float)7 / 2   // 3.5 (cast to force it)

/* --- Increment: pre vs post --- */
int a = 5;
printf("%d", a++);   // prints 5, then a becomes 6
printf("%d", ++a);   // a becomes 7, then prints 7

/* --- Compound assignment --- */
x += 3;   x -= 3;
x *= 3;   x /= 3;   x %= 3;

/* --- Ternary (one-line if) --- */
max = (a > b) ? a : b;
min = (a < b) ? a : b;

/* --- Relational and logical --- */
// ==  !=  <  >  <=  >=
//
// &&  and    ||  or    !  not

/* --- Precedence, high to low --- */
// ()
// !  ++  --  (cast)
// *  /  %
// +  -
// <  <=  >  >=
// ==  !=
// &&
// ||
// =  +=  -=

/* --- math.h --- */
// #include <math.h>      // compile with -lm
//
// sqrt(x)      pow(x, y)
// ceil(x)      floor(x)
// fabs(x)      // float absolute value
// abs(n)       // int, from stdlib.h
// sin(x) cos(x) tan(x)   // radians!

/* --- Quadratic roots --- */
d = b*b - 4*a*c;
if (d > 0) {
    r1 = (-b + sqrt(d)) / (2*a);
    r2 = (-b - sqrt(d)) / (2*a);
} else if (d == 0) {
    r1 = -b / (2.0*a);
} else {
    // imaginary roots
}

/* ========================================================================
   CONDITIONS
   set 03
   ======================================================================== */

/* --- The chain --- */
if (m >= 90)       printf("A\n");
else if (m >= 86)  printf("A-\n");
else if (m >= 82)  printf("B+\n");
else               printf("F\n");

/* --- Classifying a character --- */
if ((c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z'))  printf("Alphabet\n");
else if (c >= '0' && c <= '9') printf("Digit\n");
else                            printf("Special\n");

/* --- Leap year --- */
if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    printf("Yes\n");

/* --- Even / odd, positive / negative --- */
n % 2 == 0        // even (works for negatives too)
n > 0             // positive
n == 0            // zero is its own case - check it!

/* --- Menu with a submenu --- */
scanf("%d", &choice);
if (choice == 1)      printf("Addition: %g\n", a + b);
else if (choice == 4) {
    if ((int)b == 0) { printf("Error: Divisor is zero\n"); }
    else {
        scanf("%d", &sub);
        if (sub == 1) printf("Quotient: %d\n", (int)a / (int)b);
        else          printf("Remainder: %d\n", (int)a % (int)b);
    }
}

/* --- switch (alternative to a menu chain) --- */
switch (choice) {
    case 1: printf("Add\n");  break;
    case 2: printf("Sub\n");  break;
    default: printf("Invalid\n");
}

/* ========================================================================
   LOOPS
   set 04
   ======================================================================== */

/* --- The three forms --- */
for (i = 1; i <= n; i++) { }

while (i <= n) { i++; }

do { i++; } while (i <= n);   // runs at least once

/* --- break and continue --- */
if (g == x) { printf("Right\n"); break; }   // leave the loop
if (s[i] == ' ') continue;                  // skip to next turn

/* --- Comma-separated output --- */
for (i = 1; i <= n; i++) {
    printf("%d", i);
    if (i < n) printf(", ");   // no comma after the last
}
printf("\n");

/* --- Reading n values and accumulating --- */
float x, sum = 0;
for (i = 0; i < n; i++) {
    scanf("%f", &x);
    sum += x;
}
printf("%.2f\n", sum / n);

/* --- Alternating series 1 − 2 + 3 − 4 --- */
for (i = 1; i <= n; i++) {
    if (i % 2 == 1) sum += i;
    else            sum -= i;
}

/* --- Building 1, 12, 123, 1234 --- */
long term = 0;
for (i = 1; i <= n; i++) {
    term = term * 10 + i;
    sum += term;
}

/* --- Infinite loop with a sentinel --- */
while (1) {
    scanf(" %c", &c);
    if (c == 'A') break;
    printf("Input %d: %c\n", i++, c);
}

/* --- Taylor series for sin(x) --- */
term = x;  sum = x;
for (i = 1; i < 10; i++) {
    term = term * (-1) * x * x / ((2*i) * (2*i + 1));
    sum += term;
}

/* ========================================================================
   ARRAYS
   set 05
   ======================================================================== */

/* --- Declare, read, print --- */
int a[100], n, i;
scanf("%d", &n);
for (i = 0; i < n; i++) scanf("%d", &a[i]);

for (i = 0; i < n; i++) printf("%d ", a[i]);
printf("\n");

/* --- Print in reverse --- */
for (i = n - 1; i >= 0; i--) printf("%d ", a[i]);

/* --- Reverse in place --- */
for (i = 0; i < n / 2; i++) {   // only halfway!
    temp       = a[i];
    a[i]       = a[n-1-i];
    a[n-1-i]   = temp;
}

/* --- Max / min with index --- */
int max = a[0], maxi = 0;
for (i = 1; i < n; i++)
    if (a[i] > max) { max = a[i]; maxi = i; }

/* --- Even values vs even indexes --- */
if (a[i] % 2 == 0) sum += a[i];   // even VALUE

for (i = 0; i < n; i += 2) sum += a[i];   // even INDEX

/* --- Search, reporting every position --- */
int found = 0;
for (i = 0; i < n; i++) if (a[i] == key) found++;

if (found == 0) printf("NOT FOUND\n");
else {
    printf("FOUND at index position: ");
    int first = 1;
    for (i = 0; i < n; i++)
        if (a[i] == key) {
            if (!first) printf(", ");
            printf("%d", i);  first = 0;
        }
}

/* --- Insert at a position --- */
for (i = n; i > pos; i--)   // shift RIGHT, from the back
    a[i] = a[i-1];
a[pos] = num;
n++;

/* --- Delete at a position --- */
for (i = pos; i < n - 1; i++)   // shift LEFT, from the front
    a[i] = a[i+1];
n--;

/* --- Bubble sort (ascending) --- */
for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - 1 - i; j++)
        if (a[j] > a[j+1]) {
            temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
        }

/* --- Remove duplicates --- */
int b[100], bn = 0;
for (i = 0; i < n; i++) {
    int dup = 0;
    for (j = 0; j < bn; j++) if (b[j] == a[i]) dup = 1;
    if (!dup) b[bn++] = a[i];
}

/* --- Set operations — all three share one shape --- */
// INTERSECTION: in A and also in B
for (i = 0; i < n; i++) {
    int inB = 0;
    for (j = 0; j < m; j++) if (a[i] == b[j]) inB = 1;
    if (inB) printf("%d ", a[i]);
}

// DIFFERENCE A-B: in A but NOT in B   -> if (!inB)
// UNION: print all of A, then each B not already in A

/* ========================================================================
   NESTED LOOPS AND PATTERNS
   set 06
   ======================================================================== */

/* --- The shape of every pattern problem --- */
for (i = 1; i <= n; i++) {      // rows
    for (j = 1; j <= i; j++) {  // columns
        printf("*");
    }
    printf("\n");               // end of row - OUTSIDE inner loop
}

/* --- Right triangle / inverted --- */
// growing: 1 to i
for (j = 1; j <= i; j++)

// shrinking: i to n
for (j = i; j <= n; j++)

/* --- Pyramid: spaces then stars --- */
for (i = 1; i <= n; i++) {
    for (j = 1; j <= n - i; j++) printf(" ");   // leading spaces
    for (j = 1; j <= 2*i - 1; j++) printf("*"); // odd count
    printf("\n");
}

/* --- Numbers instead of stars --- */
printf("%d", j);          // 1 2 3 across
printf("%d", i);          // same number down a row
printf("%d", i + j - 1);  // 123 / 234 / 345

/* --- Distance-from-edge trick --- */
int width = 2*n - 1;
for (p = 0; p < width; p++) {
    int left = p + 1, right = width - p;
    int v = (left < right) ? left : right;  // 1,2,3,2,1
    if (v <= i) printf("%d", v);
    else        printf("_");
}

/* --- Multiplication table --- */
for (i = 1; i <= n; i++) {
    for (j = 1; j <= 10; j++)
        printf("%d x %d = %d\n", i, j, i*j);
    printf("\n");
}

/* ========================================================================
   2D ARRAYS
   set 07
   ======================================================================== */

/* --- Declare, read, print --- */
int a[50][50], r, c, i, j;
scanf("%d %d", &r, &c);

for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
        scanf("%d", &a[i][j]);

for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) printf("%d ", a[i][j]);
    printf("\n");           // newline per ROW
}

/* --- The position conditions --- */
// i == j              // main diagonal \
// i + j == n - 1      // other diagonal /
// i == 0 || i == n-1 ||
// j == 0 || j == n-1  // border
// i < j               // above the diagonal
// i > j               // below the diagonal

/* --- Transpose --- */
for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
        t[j][i] = a[i][j];      // indexes swapped

/* --- Symmetric check --- */
int symmetric = 1;
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        if (a[i][j] != a[j][i]) symmetric = 0;

/* --- Addition --- */
c[i][j] = a[i][j] + b[i][j];   // inside the double loop

/* --- Multiplication — three loops --- */
for (i = 0; i < r1; i++)
    for (j = 0; j < c2; j++) {
        c[i][j] = 0;            // reset before summing!
        for (k = 0; k < c1; k++)
            c[i][j] += a[i][k] * b[k][j];
    }

/* --- Row and column sums --- */
for (i = 0; i < r; i++) {
    sum = 0;                    // reset per row
    for (j = 0; j < c; j++) sum += a[i][j];
    printf("Row %d: %d\n", i, sum);
}
// for columns, swap the loops: j outside, i inside

/* ========================================================================
   STRINGS
   set 08 — done manually, no string.h
   ======================================================================== */

/* --- How this lab reads a string --- */
char s[200];
fgets(s, 200, stdin);     // reads the WHOLE line, spaces included

int len = 0;
while (s[len] != '\0' && s[len] != '\n') len++;   // this is strlen()

/* --- Why not scanf("%s") --- */
scanf("%s", s);        // stops at the first SPACE
fgets(s, 200, stdin);  // takes the whole line

/* --- Walking a string --- */
int i = 0;
while (s[i] != '\0' && s[i] != '\n') {
    printf("%c", s[i]);
    i++;
}

/* --- Case conversion by arithmetic --- */
if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';   // to upper
if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';   // to lower

/* --- Counting vowels --- */
if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
    c=='A'||c=='E'||c=='I'||c=='O'||c=='U') count++;

/* --- Counting words --- */
int count = 0, inWord = 0;
while (s[i] != '\0' && s[i] != '\n') {
    if (s[i] != ' ') {
        if (inWord == 0) { count++; inWord = 1; }
    } else inWord = 0;
    i++;
}

/* --- Palindrome (two pointers) --- */
int i = 0, j = len - 1, pal = 1;
while (i < j) {
    if (s[i] != s[j]) pal = 0;
    i++;  j--;
}

/* --- Reverse a string --- */
for (i = len - 1; i >= 0; i--) printf("%c", s[i]);
printf("\n");

/* --- Concatenate two strings --- */
i = 0; while (a[i] != '\0' && a[i] != '\n') printf("%c", a[i++]);
j = 0; while (b[j] != '\0' && b[j] != '\n') printf("%c", b[j++]);
printf("\n");

/* --- Most frequent character --- */
for (i = 0; i < len; i++) {
    if (s[i] == ' ') continue;
    count = 0;
    for (j = 0; j < len; j++)
        if (s[j] == s[i]) count++;
    if (count > best) { best = count; bestChar = s[i]; }
}

/* --- If you are allowed string.h --- */
// #include <string.h>
// strlen(s)        // length
// strcpy(a, b)     // copy b into a
// strcat(a, b)     // append b to a
// strcmp(a, b)     // 0 means equal

/* ========================================================================
   ALGORITHMS WORTH MEMORISING
   these keep coming back
   ======================================================================== */

/* --- Break a number into digits --- */
while (n != 0) {
    digit = n % 10;   // last digit
    n = n / 10;       // chop it off
}

/* --- Reverse a number --- */
rev = 0;
while (t != 0) {
    rev = rev * 10 + t % 10;
    t = t / 10;
}
if (rev == n) printf("Palindrome\n");

/* --- Factorial --- */
long f = 1;
for (i = 1; i <= n; i++) f *= i;

/* --- Fibonacci --- */
a = 1; b = 1;
for (i = 1; i <= n; i++) {
    printf("%d ", a);
    t = a + b;  a = b;  b = t;
}

/* --- Prime check --- */
int isPrime = 1;
if (n < 2) isPrime = 0;
for (i = 2; i < n; i++)
    if (n % i == 0) isPrime = 0;

/* --- GCD and LCM --- */
for (i = 1; i <= a && i <= b; i++)
    if (a % i == 0 && b % i == 0) gcd = i;

lcm = a / gcd * b;   // divide BEFORE multiplying

/* --- Power without pow() --- */
long p = 1;
for (i = 1; i <= y; i++) p *= x;

/* --- nCr --- */
long num = 1, den = 1;
for (i = 1; i <= r; i++) {
    num *= (n - i + 1);
    den *= i;
}
printf("%ld\n", num / den);

/* --- Power of two --- */
while (n > 0 && n % 2 == 0) n = n / 2;
if (n == 1) printf("Yes\n");

/* --- Swap two variables --- */
temp = a;  a = b;  b = temp;

/* ========================================================================
   TRAPS CHECKLIST
   read this last, before you hand in
   ======================================================================== */

/* --- Five-second checks --- */
// &      in every scanf?
// ;      after every statement?
// {}     matched, and around multi-line if bodies?
// i < n  not i <= n?
// \n     at the end of the output?
// = vs == in every condition?


/* ########################################################################
   FINAL EXAM CHEATSHEET - SETS 9 TO 13
   ######################################################################## */

/* ========================================================================
   FUNCTIONS
   set 09
   ======================================================================== */

/* --- Anatomy of a function --- */
int add(int a, int b);      /* prototype: goes above main */

int main()
{
    int s = add(3, 4);      /* call: s becomes 7 */
    printf("%d\n", s);
    return 0;
}

int add(int a, int b)       /* definition */
{
    return a + b;           /* send the answer back */
}

/* --- void, or return a value --- */
void greet(void)            /* does a job, gives nothing back */
{
    printf("Hello\n");
}

int square(int x)           /* gives a value back */
{
    return x * x;
}

greet();                    /* just call it */
int y = square(5);          /* keep the answer: 25 */

/* --- Pass by value vs pass by reference (swap) --- */
void swapValue(int a, int b)        /* gets COPIES */
{
    int t = a;  a = b;  b = t;      /* only the copies swap */
}

void swapRef(int *a, int *b)        /* gets ADDRESSES */
{
    int t = *a;  *a = *b;  *b = t;  /* the real variables swap */
}

swapValue(x, y);     /* x and y in main do NOT change */
swapRef(&x, &y);     /* x and y in main DO change - note the & */

/* --- Arrays go in by address --- */
void sortArray(int a[], int n)      /* no size inside [ ] */
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                t = a[j];  a[j] = a[j + 1];  a[j + 1] = t;
            }
}

sortArray(a, n);    /* pass the name: no [ ] and no & */

/* --- Return 1 or 0 for yes or no (IsPrime) --- */
int IsPrime(int n)
{
    int i;
    if (n < 2) return 0;            /* 0 and 1 are not prime */
    for (i = 2; i < n; i++)
        if (n % i == 0) return 0;   /* found a divisor: stop */
    return 1;
}

if (IsPrime(7)) printf("prime\n");

/* --- Functions that use other functions --- */
int GenNthPrime(int n)              /* the nth prime */
{
    int count = 0, num = 1;
    while (count < n)
    {
        num++;
        if (IsPrime(num)) count++;
    }
    return num;
}

/* GeneratePrime(N): print every i from 2 to N-1
   where IsPrime(i) is 1 */

/* --- Strings into functions --- */
int str_length(char s[])            /* our own strlen */
{
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

int find_substr(char a[], char b[])
{
    int i, j, la = str_length(a), lb = str_length(b);
    for (i = 0; i <= la - lb; i++)
    {
        j = 0;
        while (j < lb && a[i + j] == b[j]) j++;
        if (j == lb) return 1;      /* all of b matched */
    }
    return -1;                      /* not found */
}

/* --- 2D arrays into functions --- */
void ShowMatrix(int a[50][50], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) printf("%d ", a[i][j]);
        printf("\n");
    }
}

ShowMatrix(a, m, n);

/* --- Keep going until the input ends --- */
int gcd(int a, int b)
{
    int i, g = 1;
    for (i = 1; i <= a && i <= b; i++)
        if (a % i == 0 && b % i == 0) g = i;
    return g;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;       /* one function calls another */
}

while (scanf("%d %d", &a, &b) == 2)  /* stops at end of input */
{
    printf("GCD: %d\n", gcd(a, b));
    printf("LCM: %d\n", lcm(a, b));
}

/* --- Mean and standard deviation --- */
#include <math.h>                   /* compile with -lm */

float CalcMean(float a[], int n)
{
    int i;  float s = 0;
    for (i = 0; i < n; i++) s += a[i];
    return s / n;
}

/* inside Calc_Std_deviation: */
for (i = 0; i < n; i++)
    s += (a[i] - mean) * (a[i] - mean);
return sqrt(s / n);

/* --- Base conversion (base 2 to 16) --- */
len = 0;
while (number > 0)
{
    result[len++] = number % base;  /* digits come out backwards */
    number = number / base;
}

for (i = len - 1; i >= 0; i--)      /* so print them in reverse */
{
    if (result[i] < 10) printf("%d", result[i]);
    else                printf("%c", 'A' + result[i] - 10);   /* 10 is A */
}

/* ========================================================================
   STRUCTURES
   set 10
   ======================================================================== */

/* --- Declare, make a variable, use a dot --- */
struct student
{
    char  name[50];
    char  id[20];
    float cgpa;
};                          /* this semicolon is required */

struct student s;           /* a variable of that type */
s.cgpa = 3.5;               /* the dot reaches a member */

/* --- Starting values --- */
struct student s = {"Shakib Al Hasan", "101", 3.5};
/* same order as the members were declared */

printf("%s %s %.1f\n", s.name, s.id, s.cgpa);

/* --- Putting text into a member --- */
#include <string.h>

strcpy(s.name, "Shakib");   /* correct */
s.name = "Shakib";          /* will NOT compile */

/* --- Reading members from the keyboard --- */
scanf(" %[^\n]", s.name);  /* whole line, spaces allowed, no & */
scanf("%s", s.id);          /* one word, no & (it is an array) */
scanf("%f", &s.cgpa);       /* a number needs & */

/* --- An array of structures --- */
struct triangle
{
    int   triangle_id;
    float base, height;
};

struct triangle t[3];
for (i = 0; i < 3; i++)
    scanf("%d %f %f", &t[i].triangle_id, &t[i].base, &t[i].height);

/* --- Structures into and out of functions --- */
float area(struct triangle t)                       /* struct in */
{
    return (t.base * t.height) / 2;
}

struct student better(struct student a, struct student b)
{                                                   /* struct out */
    if (a.cgpa >= b.cgpa) return a;
    return b;
}

/* --- The biggest one in an array of structs --- */
int maxi = 0;
for (i = 1; i < 3; i++)
    if (area(t[i]) > area(t[maxi])) maxi = i;

printf("Area of %d = %g\n", t[maxi].triangle_id, area(t[maxi]));

/* --- An array inside a structure (Tigers) --- */
struct player
{
    char name[50];
    int  runs[3];           /* one for each match */
    int  wickets[3];
    int  points[3];
};

struct player p[2];
scanf("%d", &p[i].runs[m]);         /* player i, match m */
total = total + p[i].points[m];

/* ========================================================================
   POINTERS
   set 11
   ======================================================================== */

/* --- & and * --- */
int x = 5;
int *p = &x;        /* p holds the ADDRESS of x */

printf("%d", *p);   /* *p is the VALUE at that address: 5 */
*p = 10;            /* this changes x itself to 10 */

/* --- A pointer to an array --- */
int *p = a;         /* same as p = &a[0] */

*(p + i)            /* same as a[i] */

for (i = 0; i < n; i++)
    sum = sum + *(p + i);           /* sum without using a[i] */

/* --- Walking a string with a pointer --- */
char *p = s;
int len = 0;
while (*p != '\0')
{
    len++;
    p++;            /* move to the next character */
}

/* --- Swap with pointers --- */
int *px = &x, *py = &y;
int t = *px;
*px = *py;
*py = t;            /* x and y really are swapped */

/* --- Backwards through an array --- */
int *p = a;
for (i = n - 1; i >= 0; i--)
    printf("%d ", *(p + i));

/* ========================================================================
   FILES
   set 12
   ======================================================================== */

/* --- The four steps --- */
FILE *fp = fopen("sample.txt", "r");    /* 1. open */
if (fp == NULL)                         /* 2. check it opened */
{
    printf("File not found\n");
    return 0;
}
/* 3. read or write */
fclose(fp);                             /* 4. close */

/* --- The three modes --- */
// "w"     write: creates the file, or EMPTIES it if it exists
// "r"     read: the file must already exist
// "a"     append: adds to the end, keeps what is there

/* --- Writing lines --- */
FILE *fp = fopen("sample.txt", "w");
fprintf(fp, "1 Zahid\n");       /* just like printf, plus fp */
fprintf(fp, "2 Tanvir\n");
fclose(fp);

/* --- Reading item by item --- */
int  id;
char name[50];
while (fscanf(fp, "%d %s", &id, name) == 2)
{
    printf("%d %s\n", id, name);
}

/* --- Reading letter by letter, and counting lines --- */
int c;                              /* int, not char, to hold EOF */
int lines = 0;
while ((c = fgetc(fp)) != EOF)
{
    printf("%c", c);
    if (c == '\n') lines++;        /* every line ends in \n */
}

/* ========================================================================
   RECURSION
   set 13
   ======================================================================== */

/* --- Every recursive function has two parts --- */
int sum(int n)
{
    if (n == 0) return 0;           /* 1. base case: stop here */
    return n + sum(n - 1);          /* 2. call itself, smaller */
}

/* --- How sum(3) works it out --- */
// sum(3) = 3 + sum(2)
//        = 3 + 2 + sum(1)
//        = 3 + 2 + 1 + sum(0)
//        = 3 + 2 + 1 + 0
//        = 6

/* --- Fibonacci and factorial --- */
int fib(int i)
{
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fib(i - 1) + fib(i - 2);
}

int fact(int n)
{
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

/* --- Counting digits --- */
int countDigits(int n)
{
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);  /* chop one digit off */
}

/* --- Printing an array --- */
void printArray(int a[], int i, int n)
{
    if (i == n) return;             /* past the end: stop */
    printf("%d ", a[i]);
    printArray(a, i + 1, n);        /* the rest of the array */
}

printArray(a, 0, n);

/* --- Largest element --- */
int largest(int a[], int n)
{
    int rest;
    if (n == 1) return a[0];        /* one element left */
    rest = largest(a, n - 1);       /* biggest of the first n-1 */
    if (a[n - 1] > rest) return a[n - 1];
    return rest;
}

/* --- Palindrome from both ends --- */
int isPalindrome(char s[], int i, int j)
{
    if (i >= j) return 1;           /* met in the middle */
    if (s[i] != s[j]) return 0;
    return isPalindrome(s, i + 1, j - 1);
}

isPalindrome(s, 0, len - 1);

/* ========================================================================
   TRAPS CHECKLIST
   read this last, before you hand in
   ======================================================================== */

/* ========================================================================
   FINAL EXAM: QUESTIONS TO KNOW
   sets 09–13
   ======================================================================== */
