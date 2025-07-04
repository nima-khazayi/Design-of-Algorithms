#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Multiplication(int** A, int** B, int** C, int na, int ma, int nb, int mb);
void Strassen(int** A, int** B, int** C, int na, int ma, int nb, int mb);
int** allocate_matrix(int rows, int cols);
void free_matrix(int** matrix, int rows);

int main() {
    int na, ma, nb, mb, choice;
    // Taking Arguments 
    printf("Enter the number of Rows for Matrix A: ");
    scanf("%d", &na);

    printf("Enter the number of Columns for Matrix A: ");
    scanf("%d", &ma);

    printf("Enter the number of Rows for Matrix B: ");
    scanf("%d", &nb);

    printf("Enter the number of Columns for Matrix B: ");
    scanf("%d", &mb);

    printf("Choose method of multiplication\n");
    printf("1. Classic method\n");
    printf("2. Strassen method\n");
    scanf("%d", &choice);

    // Initializing Matrices A & B
    int** A = allocate_matrix(na, ma);
    int** B = allocate_matrix(nb, mb);

    // Filling matrices A & B
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < ma; j++) {
            A[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < mb; j++) {
            B[i][j] = rand() % 10;
        }
    }

    // Measure execution time
    clock_t start, end;
    double cpu_time_used;

    // Check if multiplication is possible
    if (ma != nb) {
        printf("Multiplication of these two matrices with their dimensions is impossible!");
    } else {
        start = clock();
        int** C = allocate_matrix(na, mb); // Allocate result matrix
        if (choice == 1) {
            Multiplication(A, B, C, na, ma, nb, mb);
        } else {
            Strassen(A, B, C, na, ma, nb, mb);
        }
        end = clock();

        // Print final result matrix C
        printf("Resulting Matrix C:\n");
        for (int i = 0; i < na; i++) {
            for (int j = 0; j < mb; j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }

        // Print the execution time
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("CPU TIME ELAPSED: %f\n", cpu_time_used);

        free_matrix(C, na); // Free result matrix
    }

    // Free allocated memory
    free_matrix(A, na);
    free_matrix(B, nb);
}

int** allocate_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void Multiplication(int** A, int** B, int** C, int na, int ma, int nb, int mb) {
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < mb; j++) {
            C[i][j] = 0;
            for (int k = 0; k < nb; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void Strassen(int** A, int** B, int** C, int na, int ma, int nb, int mb) {
    if (na <= 2 || ma <= 2) {
        Multiplication(A, B, C, na, ma, nb, mb);
        return;
    }

    int half_na = na / 2;
    int half_ma = ma / 2;
    int half_nb = nb / 2;
    int half_mb = mb / 2;

    // Allocating submatrices
    int** A0 = allocate_matrix(half_na, half_ma);
    int** A1 = allocate_matrix(half_na, half_ma);
    int** A2 = allocate_matrix(half_na, half_ma);
    int** A3 = allocate_matrix(half_na, half_ma);
    int** B0 = allocate_matrix(half_nb, half_mb);
    int** B1 = allocate_matrix(half_nb, half_mb);
    int** B2 = allocate_matrix(half_nb, half_mb);
    int** B3 = allocate_matrix(half_nb, half_mb);
    
    // Dividing matrices A and B into submatrices
    for (int i = 0; i < half_na; i++) {
        for (int j = 0; j < half_ma; j++) {
            A0[i][j] = A[i][j];
            A1[i][j] = A[i][j + half_ma];
            A2[i][j] = A[i + half_na][j];
            A3[i][j] = A[i + half_na][j + half_ma];
        }
    }

    for (int i = 0; i < half_nb; i++) {
        for (int j = 0; j < half_mb; j++) {
            B0[i][j] = B[i][j];
            B1[i][j] = B[i][j + half_mb];
            B2[i][j] = B[i + half_nb][j];
            B3[i][j] = B[i + half_nb][j + half_mb];
        }
    }

    // Calculate C0, C1, C2, C3
    int** C0 = allocate_matrix(half_na, half_mb);
    int** C1 = allocate_matrix(half_na, half_mb);
    int** C2 = allocate_matrix(half_na, half_mb);
    int** C3 = allocate_matrix(half_na, half_mb);

    // C0 = A0 * B0 + A1 * B2
    Multiplication(A0, B0, C0, half_na, half_ma, half_nb, half_mb);
    int** temp1 = allocate_matrix(half_na, half_mb);
    Multiplication(A1, B2, temp1, half_na, half_ma, half_nb, half_mb);
    for (int i = 0; i < half_na; i++) {
        for (int j = 0; j < half_mb; j++) {
            C0[i][j] += temp1[i][j]; // Add results
        }
    }
    free_matrix(temp1, half_na);

    // C1 = A0 * B1 + A1 * B3
    Multiplication(A0, B1, C1, half_na, half_ma, half_nb, half_mb);
    temp1 = allocate_matrix(half_na, half_mb);
    Multiplication(A1, B3, temp1, half_na, half_ma, half_nb, half_mb);
    for (int i = 0; i < half_na; i++) {
        for (int j = 0; j < half_mb; j++) {
            C1[i][j] += temp1[i][j]; // Add results
        }
    }
    free_matrix(temp1, half_na);

    // C2 = A2 * B0 + A3 * B2
    Multiplication(A2, B0, C2, half_na, half_ma, half_nb, half_mb);
    temp1 = allocate_matrix(half_na, half_mb);
    Multiplication(A3, B2, temp1, half_na, half_ma, half_nb, half_mb);
    for (int i = 0; i < half_na; i++) {
        for (int j = 0; j < half_mb; j++) {
            C2[i][j] += temp1[i][j]; // Add results
        }
    }
    free_matrix(temp1, half_na);

    // C3 = A2 * B1 + A3 * B3
    Multiplication(A2, B1, C3, half_na, half_ma, half_nb, half_mb);
    temp1 = allocate_matrix(half_na, half_mb);
    Multiplication(A3, B3, temp1, half_na, half_ma, half_nb, half_mb);
    for (int i = 0; i < half_na; i++) {
        for (int j = 0; j < half_mb; j++) {
            C3[i][j] += temp1[i][j]; // Add results
        }
    }
    free_matrix(temp1, half_na);

    // Combine C0, C1, C2, C3 into C
    for (int i = 0; i < half_na; i++) {
        for (int j = 0; j < half_mb; j++) {
            C[i][j] = C0[i][j]; // C11
            C[i][j + half_mb] = C1[i][j]; // C12
            C[i + half_na][j] = C2[i][j]; // C21
            C[i + half_na][j + half_mb] = C3[i][j]; // C22
        }
    }

    // Free allocated memory
    free_matrix(A0, half_na);
    free_matrix(A1, half_na);
    free_matrix(A2, half_na);
    free_matrix(A3, half_na);
    free_matrix(B0, half_nb);
    free_matrix(B1, half_nb);
    free_matrix(B2, half_nb);
    free_matrix(B3, half_nb);
    free_matrix(C0, half_na);
    free_matrix(C1, half_na);
    free_matrix(C2, half_na);
    free_matrix(C3, half_na);
}
