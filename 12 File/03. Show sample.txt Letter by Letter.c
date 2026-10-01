//011222131
#include <stdio.h>

int main()
{
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    int c;                  // int, so it can also hold EOF
    // read and show character by character until end of file
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
    }

    fclose(fp);
    return 0;
}
