//011222131
#include <stdio.h>

int main() {
    int n, i, a[100], num, pos;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    // input looks like:  number: 78 position: 4  (words are skipped with %*s)
    scanf("%*s %d %*s %d", &num, &pos);

    // shift right to make room
    for (i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = num;
    n++;

    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
