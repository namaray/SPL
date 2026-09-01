//011222131
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n > 0) {
        while (n % 2 == 0){
            n = n / 2;
            }
        if (n == 1)
            printf("Yes\n");
        else
            printf("No\n");
    } else if (n == 0) {
        printf("Zero is not a valid input\n");
    } else {
        printf("Negative input is not valid\n");
    }
    return 0;
}
