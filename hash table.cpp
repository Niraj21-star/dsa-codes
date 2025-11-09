#include <stdio.h>
#define SIZE 10

int linear_probing(int a[], int key){
    int index = key % SIZE;
    int i = 0;
    while (a[(index + i) % SIZE] != -1 && i < SIZE)
        i++;
    if (i == SIZE) return -1; 
    return (index + i) % SIZE;
}

int main(){
    int a[SIZE], ch, key, index;
    for(int i=0; i<SIZE; i++) a[i] = -1;

    do{
        printf("\n1. Insert\n2. Display\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);

        if(ch == 1){
            printf("Enter telephone number (key): ");
            scanf("%d", &key);
            index = linear_probing(a, key);
            if(index == -1)
                printf("Hash table full!\n");
            else {
                a[index] = key;
                printf("Inserted %d at index %d\n", key, index);
            }
        }
        else if(ch == 2){
            printf("\nHash Table:\n");
            for(int i=0; i<SIZE; i++)
                printf("%d -> %d\n", i, a[i]);
        }
        else if(ch != 3)
            printf("Invalid choice!\n");
    }while(ch != 3);

    return 0;
}

