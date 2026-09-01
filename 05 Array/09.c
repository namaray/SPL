//011222131
#include <stdio.h>

int main() {
    int n, i, count = 0;
    char a[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf(" %c", &a[i]);

    for (i = 0; i < n; i++) {
        char c = a[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            count++;
    }
    printf("Count: %d\n", count);
    return 0;
}
