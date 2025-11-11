#include <stdio.h>
#define SIZE 10

long directory[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        directory[i] = -1;
}

void linear_insert(long number) {
    int key = number % SIZE;
    int i = 0;

    while (directory[(key + i) % SIZE] != -1 && i < SIZE)
        i++;

    if (i == SIZE)
        printf("Hash table is full! Cannot insert %ld\n", number);
    else {
        int index = (key + i) % SIZE;
        directory[index] = number;
        printf("Inserted %ld at index %d (Linear Probing)\n", number, index);
    }
}

void quadratic_insert(long number) {
    int key = number % SIZE;
    int i = 0;

    while (directory[(key + (i * i)) % SIZE] != -1 && i < SIZE)
        i++;

    if (i == SIZE)
        printf("Hash table is full! Cannot insert %ld\n", number);
    else {
        int index = (key + (i * i)) % SIZE;
        directory[index] = number;
        printf("Inserted %ld at index %d (Quadratic Probing)\n", number, index);
    }
}

void double_insert(long number) {
    int h1 = number % SIZE;
    int h2 = 7 - (number % 7); 
    int i = 0;

    while (directory[(h1 + i * h2) % SIZE] != -1 && i < SIZE)
        i++;

    if (i == SIZE)
        printf("Hash table is full! Cannot insert %ld\n", number);
    else {
        int index = (h1 + i * h2) % SIZE;
        directory[index] = number;
        printf("Inserted %ld at index %d (Double Hashing)\n", number, index);
    }
}
void display() {
    printf("\n------ Telephone Directory ------\n");
    printf("Index\tNumber\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d\t%ld\n", i, directory[i]);
}

int main() {
    init();
    int ch, method;
    long number;

    do {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Insert a record\n");
        printf("2. Display hash table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter telephone number: ");
                scanf("%ld", &number);
                printf("\nChoose hashing technique:\n");
                printf("1. Linear Probing\n2. Quadratic Probing\n3. Double Hashing\n");
                scanf("%d", &method);
                switch (method) {
                    case 1:
                        linear_insert(number);
                        break;
                    case 2:
                        quadratic_insert(number);
                        break;
                    case 3:
                        double_insert(number);
                        break;
                    default:
                        printf("Invalid technique choice!\n");
                }
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid main menu choice!\n");
        }
    } while (ch != 3);

    return 0;
}
