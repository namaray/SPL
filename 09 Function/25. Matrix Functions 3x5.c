#include <stdio.h>

void InputMatrix(int a[3][5]) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++)
            scanf("%d", &a[i][j]);
}

void ShowMatrix(int a[3][5]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void ScalarMultiply(int a[3][5], int k) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++)
            a[i][j] *= k;
}

int main() {
    int a[3][5], k;
    InputMatrix(a);
    scanf("%d", &k);

    printf("Original:\n");
    ShowMatrix(a);
    ScalarMultiply(a, k);
    printf("Multiplied by %d:\n", k);
    ShowMatrix(a);
    return 0;
}
