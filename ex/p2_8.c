/*P2.8: Se citeste dintr-un fisier csv datele despre cursul euro. Primul camp semnifica data si al doilea camp valoarea in euro. Sa se stocheze dinamic datele intr-o structura cat mai abstract posibila. Programul va folosi argumentele in linie de comanda : ./p fisier.in fisier.out data. Fisier.in  contine datele de intrare si va scrie in fisier.out informatia despre cursul euro, din data “data”, din argument in linie de comanda. Fisierul de test: https://staff.cs.upt.ro/~valy/pt/curs_euro.csv

Ex:
18.01.2022;4.9445
17.01.2022;4.9440
14.01.2022;4.9432
13.01.2022;4.9435
12.01.2022;4.9445
11.01.2022;4.9452

Daca se invoca ./p curs_euro.csv fisier.out 13.01.2022, programul va scrie in fisier.out  13.01.2022;4.9435*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK 10

typedef struct
{
    char data[10];
    float euro;
} Curs;

void stocare_fisier(FILE *fin, Curs **curs, int *current_size)
{
    int size = *current_size;

    while (fscanf(fin, "%9s;%f", (*curs)[*current_size].data, &(*curs)[*current_size].euro) == 2)
    {
        if (*current_size == size)
        {
            size += CHUNK;
            Curs *temp = realloc(*curs, size * sizeof(Curs));
            if (!temp)
            {
                printf("eroare realocare");
                free(*curs);
                exit(-1);
            }
            *curs = temp;
        }
        (*current_size)++;
    }
}

void cautare(FILE *fout, Curs *curs, char data[10], int current_size)
{
    for (int i = 0; i < current_size; i++)
    {
        if (strcmp(data, curs[i].data) == 0)
        {
            fprintf(fout, "%s;%f\n", curs[i].data, curs[i].euro);
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");
    char data[10];
    strcpy(data, argv[3]);

    int current_size = 0;
    Curs *curs = malloc(sizeof(Curs));

    stocare_fisier(fin, &curs, &current_size);
    cautare(fout, curs, data, current_size);

    fclose(fin);
    fclose(fout);

    free(curs);
    return 0;
}
