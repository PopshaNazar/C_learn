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
    FILE *fin = fopen("mat.txt", "r");
    if (!fin)
    {
        printf("Nu s-a putut deschide fisierul\n");
        return 1;
    }

    int n;
    scanf("%d", &n);

    int **v = (int **)malloc(n * sizeof(int *));
    if (!v)
    {
        printf("Probleme la alocare\n");
        fclose(fin);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = (int *)malloc(n * sizeof(int));
        if (!v[i])
        {
            printf("Probleme la alocare\n");
            for (int j = 0; j < i; j++)
                free(v[j]);
            free(v);
            fclose(fin);
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(fin, "%d", &v[i][j]) != 1)
            {
                printf("Eroare la citire\n");
                for (int k = 0; k < n; k++)
                    free(v[k]);
                free(v);
                fclose(fin);
                return 1;
            }
        }
    }
    fclose(fin);

    printf("Matricea initiala:\n");
    afisare(v, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                v[i][j] = !v[i][j];
            }
        }
    }

    printf("\nMatricea modificata:\n");
    afisare(v, n);

    for (int i = 0; i < n; i++)
        free(v[i]);
    free(v);

    return 0;
}