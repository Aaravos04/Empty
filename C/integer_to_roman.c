#include <stdio.h>

void printRoman(int number) {
    char ones[][4] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char tens[][4] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char huns[][4] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char thou[][4] = {"", "M", "MM", "MMM"};
    
    printf(
        "%s%s%s%s", 
        thou[number / 1000], 
        huns[number % 1000 / 100], 
        tens[number % 100 / 10], 
        ones[number % 10]
    );
}

int main() {
    int number;
    printf("Enter a Number: ");
    scanf("%d", &number);
    printRoman(number);
    return 0;
}
