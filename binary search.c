#include <stdio.h>

int binary(int a[], int x, int n){
    int l=0, h=n-1, m;
    while(l<=h){
        m=(l+h)/2;
        if(a[m]==x) return m;
        if(a[m]>x) h=m-1;
        else l=m+1;
    }
    return -1;
}

int main(){
    int n, x, ch, position, recheck;
    printf("Enter number of students: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter roll numbers in ascending order:\n");
    for(int i=0; i<n; i++) 
		scanf("%d", &a[i]);

    do{
        printf("\n1. Binary Search\n2. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        if(ch==2) break;

        printf("Enter roll number to search: ");
        scanf("%d", &x);
        position = binary(a, x, n);

        if(position==-1)
            printf("Roll number not found!\n");
        else
            printf("Roll number found at position %d\n", position+1);

        printf("Check another number? (1=Yes / 0=No): ");
        scanf("%d", &recheck);
    } while(recheck==1);

    return 0;
}

