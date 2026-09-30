//011222131
#include <stdio.h>

int main() {
    int n, i, a[100], key, found = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &key);

    for (i = 0; i < n; i++)
        if (a[i] == key) found++;

    if (found == 0) {
        printf("NOT FOUND\n");
    } else {
        printf("FOUND at index position: ");
        int first = 1;
        for (i = 0; i < n; i++)
            if (a[i] == key) {
                if (!first) printf(", ");
                printf("%d", i);
                first = 0;
            }
        printf("\n");
    }
    return 0;
}
