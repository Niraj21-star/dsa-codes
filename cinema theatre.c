#include <stdio.h>
#include <stdlib.h>

struct seat {
    int seat_no, status; // 0 = free, 1 = booked
    struct seat *next, *prev;
};

struct seat *head[10]; // 10 rows

// --- Create seats for 10 rows, 7 per row ---
void create() {
    for (int i = 0; i < 10; i++) {
        head[i] = NULL;
        struct seat *temp, *last = NULL;
        for (int j = 1; j <= 7; j++) {
            temp = (struct seat*)malloc(sizeof(struct seat));
            temp->seat_no = j;
            temp->status = 0;
            temp->next = temp->prev = NULL;
            if (head[i] == NULL)
                head[i] = temp;
            else {
                last->next = temp;
                temp->prev = last;
            }
            last = temp;
        }
    }
}

// --- Display Seats ---
void display() {
    printf("\n0 = Free, 1 = Booked\n");
    for (int i = 0; i < 10; i++) {
        struct seat *temp = head[i];
        printf("Row %d: ", i + 1);
        while (temp) {
            printf("%d(%d) ", temp->seat_no, temp->status);
            temp = temp->next;
        }
        printf("\n");
    }
}

// --- Book Seat ---
void book(int row, int seat) {
    struct seat *temp = head[row - 1];
    for (int i = 1; i < seat; i++)
        temp = temp->next;

    if (temp->status == 1)
        printf("Seat already booked!\n");
    else {
        temp->status = 1;
        printf("? Seat %d in Row %d booked!\n", seat, row);
    }
}

// --- Cancel Seat ---
void cancel(int row, int seat) {
    struct seat *temp = head[row - 1];
    for (int i = 1; i < seat; i++)
        temp = temp->next;

    if (temp->status == 0)
        printf("Seat is not booked!\n");
    else {
        temp->status = 0;
        printf("? Booking for Seat %d in Row %d cancelled!\n", seat, row);
    }
}

// --- Main Function ---
int main() {
    int ch, row, seat;
    create();

    do {
        printf("\n=== CINEMAX THEATER ===\n");
        printf("1. Display Seats\n2. Book Seat\n3. Cancel Booking\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: display(); break;
            case 2:
                printf("Enter Row (1-10): ");
                scanf("%d", &row);
                printf("Enter Seat (1-7): ");
                scanf("%d", &seat);
                book(row, seat);
                break;
            case 3:
                printf("Enter Row (1-10): ");
                scanf("%d", &row);
                printf("Enter Seat (1-7): ");
                scanf("%d", &seat);
                cancel(row, seat);
                break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 4);

    return 0;
}

