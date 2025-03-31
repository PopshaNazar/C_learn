#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int numar : 13;
    unsigned char culoare[8];
} Carte;

int compare_color(const void *a, const void *b)
{
    const Carte *ca = (const Carte *)a;
    const Carte *cb = (const Carte *)b;
    return strcmp(ca->culoare, cb->culoare);
}

int compare_number(const void *a, const void *b)
{
    const Carte *ca = (const Carte *)a;
    const Carte *cb = (const Carte *)b;
    return (int)(ca->numar - cb->numar);
}

int main()
{
    Carte *v = malloc(5 * sizeof(Carte));
    if (!v)
    {
        printf("Probleme la alocare\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Culoare pentru carte %d: ", i + 1);
        scanf("%7s", v[i].culoare);

        printf("Numar pentru carte %d: ", i + 1);
        unsigned short temp;
        scanf("%hu", &temp);
        v[i].numar = temp;
    }

    qsort(v, 5, sizeof(Carte), compare_color);
    printf("\nSortate dupa culoare:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Culoare: %-7s Numar: %hu\n", v[i].culoare, v[i].numar);
    }

    qsort(v, 5, sizeof(Carte), compare_number);
    printf("\nSortate dupa numar:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Culoare: %-7s Numar: %hu\n", v[i].culoare, v[i].numar);
    }

    free(v);
    return 0;
}