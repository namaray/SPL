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

    int lines = 0;
    int c;                  // int, so it can also hold EOF
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '\n')
        {
            lines++;
        }
    }

    fclose(fp);
    printf("Number of lines: %d\n", lines);
    return 0;
}
