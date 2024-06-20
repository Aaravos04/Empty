#include <stdio.h>

int main() {
    int i, j, n, val;
    printf("Enter a number: ");
    scanf("%d", &n);

    int arr[n];
    arr[0] = n;
    for (i = n - 1, j = 1; i >= 0; i--, j++)
        arr[j] = arr[j - 1] + i;
    
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            val = j % 2 ?
                  arr[j-1] + i - n :
                  arr[j-1] - i + j;
            printf("%d\t", val);
        }
        
        printf("\n");
    }

    return 0;
}
