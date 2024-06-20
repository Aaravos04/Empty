#include<stdio.h>

void main() {
    int line1, line2, line3, n, i;
    printf("Enter a number: ");
    scanf("%d", &n);

    line1 = (n + 1) / 4; line2 = n / 2, line3 = (n + 3) / 4;
    for (i = 0; i < line1; i++)
        printf("  * ");
    printf("\n");

    for (i = 0; i < line2; i++)
        printf(" *");
    printf("\n");

    for (i = 0; i < line3; i++)
        printf("*   ");
    printf("\n");
}