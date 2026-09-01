#include <stdio.h>

int main() {
    FILE *fp = fopen("sample.txt", "r");   // "r" opens for reading
    if (fp == NULL) {
        printf("File not found\n");
        return 0;
    }

    int id;
    char name[50];
    // read each "number name" line
    while (fscanf(fp, "%d %s", &id, name) == 2)
        printf("%d %s\n", id, name);

    fclose(fp);
    return 0;
}
