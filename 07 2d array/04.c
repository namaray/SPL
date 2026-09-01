#include <stdio.h>

int main()
{
    int n, i, j, a[50][50];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Major diagonal: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i][i]);
    }
    printf("\n");

    printf("Minor diagonal: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i][n - 1 - i]);
    }
    printf("\n");
    return 0;
}
