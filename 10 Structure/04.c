#include <stdio.h>

struct student {
    char name[50];
    char id[20];
    float cgpa;
};

int main() {
    struct student s = {"Shakib Al Hasan", "101", 3.5};
    printf("%s\n", s.name);
    printf("%s\n", s.id);
    printf("%.1f\n", s.cgpa);
    return 0;
}
