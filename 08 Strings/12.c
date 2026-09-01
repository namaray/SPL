#include <stdio.h>

int main() {
    char s[200], w[100];
    fgets(s, 200, stdin);
    fgets(w, 100, stdin);

    // length of the word (ignore the newline)
    int wl = 0;
    while (w[wl] != '\0' && w[wl] != '\n') wl++;

    int i = 0, count = 0;
    while (s[i] != '\0' && s[i] != '\n') {
        // try to match the word starting at position i
        int k = 0;
        while (k < wl && s[i + k] == w[k]) k++;

        // it is a full word if all letters matched and the borders are spaces
        if (k == wl &&
            (i == 0 || s[i - 1] == ' ') &&
            (s[i + wl] == ' ' || s[i + wl] == '\n' || s[i + wl] == '\0'))
            count++;
        i++;
    }
    printf("%d\n", count);
    return 0;
}
