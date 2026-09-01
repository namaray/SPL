#include <stdio.h>

int main() {
    FILE *fp = fopen("sample.txt", "w");   // "w" creates the file

    fprintf(fp, "1 Zahid\n");
    fprintf(fp, "2 Tanvir\n");
    fprintf(fp, "3 Akif\n");

    fclose(fp);
    printf("Data stored in sample.txt\n");
    return 0;
}
