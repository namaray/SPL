#include <stdio.h>

struct student {
    char name[50];
    char id[20];
    float cgpa;
};

int main() {
    struct student s;
    scanf(" %[^\n]", s.name);   // read a full line (name may have spaces)
    scanf("%s", s.id);
    scanf("%f", &s.cgpa);

    printf("%s\n", s.name);
    printf("%s\n", s.id);
    printf("%.1f\n", s.cgpa);
    return 0;
}
