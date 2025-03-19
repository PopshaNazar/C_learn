/*P1.4:Se dau 2 vectori, cu nr necunoscut de elemente. Se face o functie de citire a vectorilor, după aia o funcție de sortare (in ordine crescătoare) a vectorilor. O funcție primește acei 2 vectori și returnează un alt vector alocat dinamic, (tot crescător trebuie sa fie) după următoarea regula: un număr special este acel număr a cărui suma a divizorilor (numărul respectiv nu se pune) este mai mare decât numărul. Vectorul rezultat conține numerele speciale din ambii vectori. Sa se afișeze și dimensiunea vectorului rezultat.  (Interclasare pe scurt). Programul se va termina fără memory leaks.
De ex:
pt nr 12: 1+2+3+4+6=16>12=> nr special
v1: 1 2 3 4 6 8 12 20 30
v2: 6 8 12 24 30 36
vectorul rezultat: 12 20 24 30 36
dimensiunea: 5*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

void citire(int **v, int size)
{
    int *temp = realloc(*v, size * sizeof(int));
    if (!temp)
    {
        printf("erroare alocare temp");
        free(*v);
        exit(1);
    }
    *v = temp;

    for (int i = 0; i < size; i++)
    {
        printf("v[%d] = ", i);
        scanf("%d", &(*v)[i]);
    }
}

void sort(int **v, int size)
{
    int aux = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if ((*v)[j] > (*v)[j + 1])
            {
                aux = (*v)[j];
                (*v)[j] = (*v)[j + 1];
                (*v)[j + 1] = aux;
            }
        }
    }
}

int *mySort(int *v1, int *v2, int size)
{
    int *v = (int *)malloc(sizeof(int) * size * 2);
    for (int i = 0; i < size; i++)
    {
        v[i] = v1[i];
        v[size + i] = v2[i];
    }

    sort(&v, size * 2);
    return v;
}

void afisare(int *v, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int *v1 = NULL;
    int *v2 = NULL;
    int size = MAX;
    citire(&v1, size);
    citire(&v2, size);

    sort(&v1, size);
    sort(&v2, size);

    afisare(v1, size);
    afisare(v2, size);
    int *v = mySort(v1, v2, size);
    afisare(v2, size);

    free(v1);
    free(v2);
    free(v);
}