#include <stdio.h>
#include <stdlib.h>

void afisare(int **v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", v[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    FILE *fin = fopen("numere.txt", "r");
    if (!fin)
    {
        printf("nu s a deschis fisieru");
        return 0;
    }
    int **v = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        v[i] = (int *)malloc(sizeof(int) * n);
    }
    // int v[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fin, "%d", &v[i][j]);
        }
    }
    afisare(v, n);
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = v[i][i];
        for (int j = 0; j < n; j++)
        {

            v[i][j] = x;
        }
    }

    printf("rez:\n");
    afisare(v, n);
    for (int i = 0; i < n; i++)
    {
        free(v[i]);
    }
    free(v);
    return 0;
}