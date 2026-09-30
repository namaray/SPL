#include <stdio.h>

void sign(int n) {
    if (n > 0)      printf("positive\n");
    else if (n < 0) printf("negative\n");
    else            printf("zero\n");
}

int main() {
    int n;
    scanf("%d", &n);
    sign(n);
    return 0;
}
