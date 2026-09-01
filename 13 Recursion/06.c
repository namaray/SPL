#include <stdio.h>

// print even numbers going up
void evens(int cur, int end) {
    if (cur > end) return;
    printf("%d", cur);
    if (cur + 2 <= end) printf(", ");
    evens(cur + 2, end);
}

// print odd numbers going up
void odds(int cur, int end) {
    if (cur > end) return;
    printf("%d", cur);
    if (cur + 2 <= end) printf(", ");
    odds(cur + 2, end);
}

int main() {
    int start, end;
    scanf("%d %d", &start, &end);

    int firstEven = (start % 2 == 0) ? start : start + 1;
    int firstOdd  = (start % 2 == 1) ? start : start + 1;

    printf("Even Numbers: ");
    evens(firstEven, end);
    printf("\n");

    printf("Odd Numbers: ");
    odds(firstOdd, end);
    printf("\n");
    return 0;
}
