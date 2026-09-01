#include <stdio.h>

// pass by reference: using addresses, the real variables change
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
    printf("Value in func:    %d    %d\n", *a, *b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Value in main:   %d    %d\n", a, b);
    return 0;
}
