#include <stdio.h>

int main() {
    char s[200];
    fgets(s, 200, stdin);

    int i = 0, sum = 0;
    while (s[i] != '\0' && s[i] != '\n') {
        if (s[i] >= '0' && s[i] <= '9')
            sum += s[i] - '0';   // character digit -> number
        i++;
    }
    printf("%d\n", sum);
    return 0;
}
