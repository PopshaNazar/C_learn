/*P1.10: Se da un fisier care contine dictionar de cuvinte de forma cuvant_EN=cuvant_RO. pe fiecare linie. Nu se stie numarul liniilor, dar fiecare are maxim 100 de caractere. Sa se scrie o functie care verifica daca un cuvant in engleza exista in dictionar. Daca da, returneaza traducerea in romana, iar daca nu, returneaza "nu a fost gasit".
Nu se tine cont de literele mari/mici cand se cauta in dictionar. */

#include <stdio.h>
#include <stdlib.h>

#define CHUNK 10

typedef struct
{
    char en[98];
    char ro[98];
} Cuvant;

void citire(FILE *file, Cuvant **cuvant, int *current_size)
{
    int size = CHUNK;
    // while (fscanf(file, "%s=%s", (*cuvant)[*current_size].en, (*cuvant)[*current_size].ro) == 2)
    char buffer[100];
    while (fscanf(file, "%s", buffer) == 1)
    {
        if (*current_size == size - 1)
        {
            size += CHUNK;
            Cuvant *temp = realloc(*cuvant, size * sizeof(Cuvant));
            if (!temp)
            {
                printf("Nu a reusit realocarea");
                free(*cuvant);
                exit(1);
            }
            *cuvant = temp;
        }
        (*current_size)++;
    }

    for (int i = 0; i < *current_size; i++)
    {
        printf("!%s!=!%s!\n", (*cuvant)[i].en, (*cuvant)[i].ro);
    }
}

int main()
{
    FILE *fin = fopen("dictionar.txt", "r");
    if (!fin)
    {
        printf("Eroare la deschiderea fisierului");
        return 1;
    }

    Cuvant *cuvant = malloc(CHUNK * sizeof(Cuvant));
    if (!cuvant)
    {
        printf("Alocarea initiala a esuat");
        fclose(fin);
        return 1;
    }

    int current_size = 0;
    citire(fin, &cuvant, &current_size);

    free(cuvant);
    fclose(fin);
    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAA");

    return 0;
}