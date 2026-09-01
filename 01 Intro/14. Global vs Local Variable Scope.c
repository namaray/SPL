// 011222131
#include <stdio.h>

int var = 10;

int main() {

    printf("A. Global: %d\n", var);

    {
        int var = 20;
        printf("B. Local: %d\n", var);
    }

    printf("C. Global: %d\n", var);

    return 0;
}
