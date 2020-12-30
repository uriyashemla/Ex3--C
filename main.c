#include "isort.h"
#include <stdio.h>

#define SIZE 50

int main() {
    int arr[SIZE];
    printf("Enter 50 numbers for sorting :\n");
    for (int i = 0; i<SIZE ; i++){
        int x;
        scanf("%d",&x);
        *(arr+i) = x;
    }
    insertion_sort(arr,SIZE);
    printMe(arr,SIZE);
    return 0;
}