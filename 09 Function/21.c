#include <stdio.h>
#include <math.h>

int TakeInput(float a[]) {
    int n = 0;
    // read numbers until end of input
    while (scanf("%f", &a[n]) == 1) n++;
    return n;
}

float CalcMean(float a[], int n) {
    int i;
    float s = 0;
    for (i = 0; i < n; i++) s += a[i];
    return s / n;
}

float Calc_Std_deviation(float a[], int n) {
    int i;
    float mean = CalcMean(a, n), s = 0;
    for (i = 0; i < n; i++)
        s += (a[i] - mean) * (a[i] - mean);
    return sqrt(s / n);
}

int main() {
    float a[100];
    int n = TakeInput(a);
    printf("%.2f\n", Calc_Std_deviation(a, n));
    return 0;
}
