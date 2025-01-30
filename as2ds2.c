#include <stdio.h>
#include <stdlib.h>

struct Arrays {
    int *arr1;
    int *arr2;
};

void replaceOddPositions(int *arr1, int *arr2, int n) {
    for(int i = 0; i < n; i++) {
      *(arr2 + i) = *(arr1 + i);
        if(i % 2 != 0 && i > 0 && i < n - 1) {
       *(arr2 + i) = *(arr1 + (i - 1)) * *(arr1 + (i + 1));
        }
    }
}

int main() {
    struct Arrays arrays;
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    arrays.arr1 = (int *)malloc(n * sizeof(int));
    arrays.arr2 = (int *)malloc(n * sizeof(int));

    if(arrays.arr1 == NULL || arrays.arr2 == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter the elements of the first array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", arrays.arr1 + i);
    }

    replaceOddPositions(arrays.arr1, arrays.arr2, n);

    printf("Second Array (Output):\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arrays.arr2 + i));
    }

    free(arrays.arr1);
    free(arrays.arr2);

    return 0;
}
