#include <stdio.h>

int main() {
    int day, month, year;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);
    
    if (month < 3) {
        month += 12;
        year--;
    }

    int h = (day + (13 * (month + 1)) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("The day of the week for %d-%d-%d is %s\n", day, month, year, days[h]);

    return 0;
}
