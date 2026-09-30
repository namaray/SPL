#include <stdio.h>

struct student {
    char name[50];
    char id[20];
    float cgpa;
};

struct student better(struct student a, struct student b) {
    if (a.cgpa >= b.cgpa) return a;
    return b;
}

int main() {
    struct student a, b;
    scanf(" %[^\n]", a.name); scanf("%s", a.id); scanf("%f", &a.cgpa);
    scanf(" %[^\n]", b.name); scanf("%s", b.id); scanf("%f", &b.cgpa);

    struct student h = better(a, b);
    printf("%s\n%s\n%.1f\n", h.name, h.id, h.cgpa);
    return 0;
}
