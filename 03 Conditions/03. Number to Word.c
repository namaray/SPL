//011222131
#include <stdio.h>

int main() {
    char *words[10] = {"zero", "one", "two", "three", "four",
                       "five", "six", "seven", "eight", "nine"};
    int n;

    scanf("%d", &n);

    printf("%s\n", words[n]);

    return 0;
}
