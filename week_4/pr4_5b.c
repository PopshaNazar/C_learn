/*Aplicația 4.1: Să se codifice cu ajutorul structurilor cu câmpuri pe biți informațiile despre un fișier: nume (șir de
maxim 15 caractere), dimensiunea acestuia (int - număr de octeți, maxim 1024 octeți), tipul acestuia (.txt - 0, .doc
- 1, .xls – 2), tipul fisierului (normal – 0, read-only – 1). Să se citească informația despre un fișier, și să se afișeze
pe ecran.
Aplicația 4.2: Cu ajutorul structurii de la problema mai sus să se salveze într-un vector de structuri declarat static
informații despre mai multe fișiere (maxim 10). Să se citească de la tastatură informațiile despre fișiere și să se
salveze în fișierul memorie.txt.
Aplicația 4.3: Modificați problema de mai sus astfel încât vectorul de structuri să fie alocat dinamic.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    unsigned char nume[15];
    unsigned int octeti : 11;
    unsigned int format : 2;
    unsigned int tipb : 1;
} Fisier;

void adaugare(Fisier **fisier, int *size)
{
    size++;
    Fisier *temp = realloc(*fisier, *size * sizeof(Fisier));
    if (!temp)
    {
        printf("nu a reusit realocarea");
        free(*fisier);
        exit(1);
    }

    printf("nume: ");
    scanf("%s", (*fisier)[*size].nume);

    // unsigned int aux = 0;
    // printf("octeti: ");
    // scanf("%d", &aux);
    // fisier.octeti = aux;

    // printf("formatul (.txt - 0, .doc - 1, .xls - 2): ");
    // scanf("%d", &aux);
    // fisier.format = aux;

    // printf("tipul fisierului(normal - 0, read-only - 1)): ");
    // scanf("%d", &aux);
    // fisier.tipb = aux;
}
int main()
{
    int size = 0;
    Fisier *fisier = NULL;
    adaugare(&fisier, &size);
    adaugare(&fisier, &size);
    adaugare(&fisier, &size);

    // printf("%s", fisier.nume);
    // if (fisier.format == 0)
    //     printf(".txt");
    // if (fisier.format == 1)
    //     printf(".doc");
    // if (fisier.format == 2)
    //     printf(".xls");

    // printf("\n nr de octeti: %d", fisier.octeti);
    // if (fisier.tipb == 0)
    //     printf("\n fisier normal");
    // if (fisier.tipb == 1)
    //     printf("\n fisier read-only");
    return 0;
}