//011222131

#include <stdio.h>

int main()
{
    int r, c, i, j, a[100], b[100];
    scanf("%d", &r);

    for (i = 0; i < r; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &c);
    for (i = 0; i < c; i++)
    {
        scanf("%d", &b[i]);
    }

    for(i = 0; i < r; i++)
    {
        int isinB = 0;
        for(j=0; j<c; j++)
        {
            if(a[i]==b[j])
            {
                isinB = 1;
            }
        }

        if(!isinB)
        {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}
