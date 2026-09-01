//011222131

#include <stdio.h>

int main(){

    int a[50][50], i, j;
    int r, c;
    scanf("%d %d", &r, &c);

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");


    for(j=0; j<c; j++)
    {
        for(i=0; i<r; i++)
        {
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
}
