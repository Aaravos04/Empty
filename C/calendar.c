#include<stdio.h>
#include<conio.h>

int day(int date, int month, int year) {
    int year_cycle[] = {
        5, 0, 1, 2, 3, 5, 6, 0, 1, 3, 4, 5, 6, 1,
        2, 3, 4, 6, 0, 1, 2, 4, 5, 6, 0, 2, 3, 4
    };

    int result = year_cycle[year % 28], i;
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days_in_month[1] = 29;

    if(month < 1 || month > 12) 
        return -1;
    
    if(date < 1 || date > days_in_month[month - 1])
        return -1;

    for (i = 1; i < month; i++)
        result += days_in_month[i - 1];

    result += date - 1;
    return result % 7;
}

int main() {
    int date, month, year, result;
    char weekdays[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    printf("Enter Date: ");
    scanf("%d", &date);
    printf("Enter Month: ");
    scanf("%d", &month);
    printf("Enter Year: ");
    scanf("%d", &year);

    result = day(date, month, year);
    if(result == -1)
        printf("Error: Invalid Date! %d-%d-%d is not a valid date.\n", date, month, year);
    else
        printf("%d-%d-%d is %s.\n", date, month, year, weekdays[result]);
    getch();
    return 0;
}
