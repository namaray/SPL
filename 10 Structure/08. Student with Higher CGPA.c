#include <stdio.h>

struct student {
    char name[50];
    char id[20];
    float cgpa;
};

int main() {
    struct student a, b;
    scanf(" %[^\n]", a.name); scanf("%s", a.id); scanf("%f", &a.cgpa);
    scanf(" %[^\n]", b.name); scanf("%s", b.id); scanf("%f", &b.cgpa);

    struct student higher = (a.cgpa >= b.cgpa) ? a : b;
    printf("%s\n%s\n%.1f\n", higher.name, higher.id, higher.cgpa);
    return 0;
}
