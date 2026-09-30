#include <stdio.h>

int number, base, result[100], len;

void Get_Number_And_Base() {
    scanf("%d %d", &number, &base);
}

void Convert_Number() {
    len = 0;
    if (number == 0) { result[len++] = 0; return; }
    while (number > 0) {
        result[len++] = number % base;   // store the digits (reversed)
        number /= base;
    }
}

void Show_Converted_Number() {
    int i;
    // digits above 9 become letters A..F
    for (i = len - 1; i >= 0; i--) {
        if (result[i] < 10) printf("%d", result[i]);
        else                printf("%c", 'A' + result[i] - 10);
    }
    printf("\n");
}

int main() {
    Get_Number_And_Base();
    if (base < 2 || base > 16) {
        printf("Base not within proper range!\n");
        return 0;
    }
    Convert_Number();
    Show_Converted_Number();
    return 0;
}
