//011222131
#include <stdio.h>

int main()
{
    int n, i, j, a[50][50], symmetric = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != a[j][i])
            {
                symmetric = 0;
            }
        }
    }

    if (symmetric)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
