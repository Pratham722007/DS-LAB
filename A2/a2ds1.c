#include <stdio.h>
#include <stdlib.h>

void readMatrix(int* matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", (matrix + i * cols + j));
        }
    }
}

void multiplyMatrices(int* mat1, int* mat2, int* result, int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            *(result + i * c1 + j) = 0;
            for (int k = 0; k < c1; ++k) {
                *(result + i * c1 + j) += *(mat1 + i * c1 + k) * *(mat2 + k * c1 + j);
            }
        }
    }
}

void displayMatrix(int* matrix, int rows, int cols) {
    printf("Matrix elements are:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

int main() {
    int r1, c1;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r1, &c1);

    
    


    
    
    int* mat1 = (int*)malloc(r1 * c1 * sizeof(int));
    int* mat2 = (int*)malloc(r1 * c1 * sizeof(int));
    int* result = (int*)malloc(r1 * c1 * sizeof(int));

   
    printf("Enter elements of the first matrix:\n");
    readMatrix(mat1, r1, c1);
    printf("Enter elements of the second matrix:\n");
    readMatrix(mat2, r1, c1);

    multiplyMatrices(mat1, mat2, result, r1, c1, r1, c1);

    
    displayMatrix(result, r1, c1);

    
    free(mat1);
    free(mat2);
    free(result);

    return 0;
}
