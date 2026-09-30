#include <stdio.h>

int str_length(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

int find_substr(char a[], char b[]) {
    int i, j;
    int la = str_length(a), lb = str_length(b);
    for (i = 0; i <= la - lb; i++) {
        j = 0;
        while (j < lb && a[i + j] == b[j]) j++;
        if (j == lb) return 1;
    }
    return -1;
}

int main() {
    char a[200], b[200];
    scanf("%s %s", a, b);
    printf("%d\n", find_substr(a, b));
    return 0;
}
