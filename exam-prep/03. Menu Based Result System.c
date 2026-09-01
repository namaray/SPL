// Exam Prep Q3 - Nested Conditions & Menu Logic
#include <stdio.h>

int main() {
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        float m;
        scanf("%f", &m);

        if (m < 0 || m > 100) {
            printf("Invalid marks\n");
        } else if (m >= 90) {
            float attendance;
            scanf("%f", &attendance);
            if (attendance >= 90)
                printf("Grade: A+\n");
            else
                printf("Grade: A\n");
        } else if (m >= 80) {
            printf("Grade: B\n");
        } else if (m >= 70) {
            printf("Grade: C\n");
        } else if (m >= 60) {
            printf("Grade: D\n");
        } else {
            printf("Grade: F\n");
        }
    } else if (choice == 2) {
        int year;
        scanf("%d", &year);

        if (year <= 0)
            printf("Invalid year\n");
        else if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            printf("Leap Year\n");
        else
            printf("Not a Leap Year\n");
    } else if (choice == 3) {
        char c;
        scanf(" %c", &c);

        if (c >= 'A' && c <= 'Z')
            printf("Uppercase\n");
        else if (c >= 'a' && c <= 'z')
            printf("Lowercase\n");
        else if (c >= '0' && c <= '9')
            printf("Digit\n");
        else
            printf("Special Character\n");
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
