#include <stdio.h>

int main() {
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    char c;
    // read and show character by character until end of file
    while ((c = fgetc(fp)) != EOF)
        printf("%c", c);

    fclose(fp);
    return 0;
}
