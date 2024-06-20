#include<stdio.h>
#define ROW 10
#define COL 20

int hall[ROW][COL];

void book(int low, int high) {
    const int total_seats = (high - low) * COL;
    int booked = 0, available, audience = 0, i, j;
    for (i = low; i < high; i++) {
        for (j = 0; j < COL; j++) {
            if (hall[i][j] == 1)
                booked++;
        }
    }

    available = total_seats - booked;
    if (available == 0) {
        printf("No seats available!\n");
        return;
    }

    do {
        if (audience > available)
            printf("\n%d seats not available!", audience);
        printf("\n%d seats available!\nEnter no. of audience (0: Cancel): ", available);
        scanf("%d", &audience);
        if (audience == 0)
            return;
    } while (audience > available);
    
    printf("\nAlloted seats:");
    for (i = low; i < high && audience; i++) {
        printf("\n");
        for (j = 0; j < COL && audience; j++) {
            if (hall[i][j] == 0) {
                audience--;
                hall[i][j] = 1;
                printf("%c%d ", i+65, j+1);
            }
        }
    }

    printf("\nBooking successful!\n");
}

int main() {
    int input, i, j;
    printf("*** Ticket Booking ***\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            hall[i][j] = 0;
    }

    while (1) {
        printf("\n1: Low; 2: Medium; 3: High;\nEnter your choice: ");
        scanf("%d", &input);

        switch (input) {
        case 1:
            book(0, 4);
            break;
        case 2:
            book(4, 7);
            break;
        case 3:
            book(7, 10);
            break;
        default:
            printf("\nProgram Terminated!");
            return 0;
        }
    }
}
