#include <stdio.h>

int find_substr(char a[], char b[]) {
    int i, j;
    for (i = 0; a[i] != '\0'; i++) {
        j = 0;
        while (b[j] != '\0' && a[i + j] == b[j]) j++;
        if (b[j] == '\0') return 1;   // reached end of b -> full match
    }
    return -1;
}

int main() {
    char a[200], b[200];
    scanf("%s %s", a, b);
    printf("%d\n", find_substr(a, b));
    return 0;
}
