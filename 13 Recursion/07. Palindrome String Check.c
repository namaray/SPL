#include <stdio.h>

int isPalindrome(char s[], int i, int j) {
    if (i >= j) return 1;               // met in the middle -> palindrome
    if (s[i] != s[j]) return 0;
    return isPalindrome(s, i + 1, j - 1);
}

int main() {
    char s[200];
    scanf("%s", s);

    int len = 0;
    while (s[len] != '\0') len++;

    if (isPalindrome(s, 0, len - 1)) printf("Palindrome\n");
    else                             printf("Not Palindrome\n");
    return 0;
}
