/*Aplicația 5.3: Se citesc m și n de la tastatură, iar apoi o matrice a[m][n] cu elemente de tip întreg. Să se scrie matricea într-un fișier binar, prima oară scriindu-se m și n, iar apoi elementele, așa cum sunt dispuse ele în memorie. Să se citească matricea din fișier într-o variabilă b și să se afișeze. + se citeste din fisier txt*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    int n;
    scanf("%d", &m);
    scanf("%d", &n);

    FILE *fin = fopen("numere.txt", "r");
    if (!fin)
    {
        printf("nu s a deschis fisierul");
        exit(-1);
    }
    FILE *fout = fopen("numere.bin", "wb");

    int b[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fread(&b[i][j], sizeof(int), 1, fin);
            // fscanf(fin, "%d", &b[i][j]);
            fwrite(&b[i][j], sizeof(int), 1, fout);
        }
    }
    fclose(fin);
    fclose(fout);

    // afisare
    fout = fopen("numere.bin", "rb");
    int a = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fread(&a, sizeof(int), 1, fout);
            printf("%2d  ", a);
        }
        printf("\n");
    }
    fclose(fout);
    return 0;
}