#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    char id[20];
    float cgpa;
};

int main() {
    struct student s;
    strcpy(s.name, "Shakib Al Hasan");
    strcpy(s.id, "101");
    s.cgpa = 3.5;

    printf("%s\n", s.name);
    printf("%s\n", s.id);
    printf("%.1f\n", s.cgpa);
    return 0;
}
