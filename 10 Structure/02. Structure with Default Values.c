#include <stdio.h>

struct student {
    char name[50];
    char id[20];
    float cgpa;
};

int main() {
    // a variable with "default" starting values
    struct student s = {"None", "0000", 0.0};
    printf("%s %s %.2f\n", s.name, s.id, s.cgpa);
    return 0;
}
