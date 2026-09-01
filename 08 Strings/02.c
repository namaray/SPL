#include <stdio.h>

int main()
{
    char a[200], b[200];
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);

    int i = 0, j = 0;
    while (a[i] != '\0' && a[i] != '\n')
    {
        printf("%c", a[i]);
        i++;
    }
    while (b[j] != '\0' && b[j] != '\n')
    {
        printf("%c", b[j]);
        j++;
    }
    printf("\n");
    return 0;
}
