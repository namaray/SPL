#include <stdio.h>

int main() {
    FILE *fp = fopen("sample.txt", "a");   // "a" appends to the end

    fprintf(fp, "4 Rahim\n");
    fprintf(fp, "5 Karim\n");

    fclose(fp);
    printf("Lines appended to sample.txt\n");
    return 0;
}
