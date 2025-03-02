/*Se citește de la tastatură o matrice cu n<=20 linii și coloane. Să se memoreze într-un vector suma
tuturor elementelor de pe fiecare linie și într-un alt vector, suma tuturor elementelor de pe fiecare coloană. Să se
afișeze cei doi vectori. Se vor utiliza pointeri atât pentru vectori cât și pentru matrici.*/

#include <stdio.h>

#define MAX 20

void read_matrix(int matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("matrix[%d][%d]: ", i, j);
            // scanf("%d", &matrix[i][j]);
            scanf("%d", (*(matrix + i) + j));
        }
    }
}

void sum(int matrix[MAX][MAX], int n, int row_sums[MAX], int col_sums[MAX])
{
    int r_sum = 0;
    int c_sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // r_sum += matrix[i][j];
            // c_sum += matrix[j][i];
            r_sum += *(*(matrix + i) + j);
            c_sum += *(*(matrix + j) + i);
        }
        // row_sums[i] = r_sum;
        // col_sums[i] = c_sum;
        *(row_sums + i) = r_sum;
        *(col_sums + i) = c_sum;

        r_sum = 0;
        c_sum = 0;
    }
}

void print_result(int matrix[MAX][MAX], int n, int row_sums[MAX], int col_sums[MAX])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // printf("%d", matrix[i][j]);
            printf("%3d", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    printf("row_sums: ");

    for (int i = 0; i < n; i++)
    {
        // printf("%d- ", row_sums[i]);
        printf("%d ", *(row_sums + i));
    }
    printf("\n");
    printf("col_sums: ");

    for (int i = 0; i < n; i++)
    {
        // printf("%d- ", col_sums[i]);
        printf("%d ", *(col_sums + i));
    }
}

int main()
{
    int n;
    int matrix[MAX][MAX];
    int row_sums[MAX];
    int col_sums[MAX];

    printf("enter the dimensions of the matrix(n <= 20): ");
    scanf("%d", &n);

    if (n > MAX || n <= 0)
    {
        printf("dimensions out of range!\n");
        return 1;
    }

    read_matrix(matrix, n);
    sum(matrix, n, row_sums, col_sums);
    print_result(matrix, n, row_sums, col_sums);

    return 0;
}