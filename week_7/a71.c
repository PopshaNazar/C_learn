#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int n;
    struct elem *urm;
} elem;

elem *new_nod(int n)
{
    elem *e = (elem *)malloc(sizeof(elem));
    if (!e)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->n = n;
    e->urm = NULL;
    return e;
}
elem *adaugaInceput(elem *lista, int n)
{
    elem *nod;
    nod = new_nod(n);
    nod->urm = lista;
    lista = nod;
    return lista;
}

elem *adaugaSvarsit(elem *lista, int n)
{
    elem *q, *nod;
    if (lista == NULL)
    {
        lista = new_nod(n);
    }
    else
    {
        for (q = lista; q->urm != NULL; q = q->urm)
            ;
        nod = new_nod(n);
        q->urm = nod;
    }
    return lista;
}
void eliberare(elem *lista)
{
    elem *p;
    while (lista)
    {
        p = lista->urm;
        free(lista);
        lista = p;
    }
}
void afisare(elem *lista)
{
    elem *p;
    for (p = lista; p != NULL; p = p->urm)
    {
        if (p->urm != NULL)
        {
            printf("%d-->", p->n);
        }
        else
        {
            printf("%d", p->n);
        }
    }
    printf("\n");
}

int egalitate(elem *lista1, elem *lista2)
{
    elem *p1 = lista1;
    elem *p2 = lista2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->n != p2->n)
        {
            return 0;
        }
        p1 = p1->urm;
        p2 = p2->urm;
    }
    if ((p1 == NULL) && (p2 == NULL))
    {
        return 1;
    }
    return 0;
}

int main()
{
    // elem *L1 = NULL;
    // L1 = adaugaInceput(L1, 13);
    // L1 = adaugaInceput(L1, 17);
    // L1 = adaugaSvarsit(L1, 99);

    elem *L2 = NULL;
    L2 = adaugaInceput(L2, 101);
    L2 = adaugaInceput(L2, 102);
    L2 = adaugaSvarsit(L2, 103);

    elem *L3 = NULL;
    L3 = adaugaInceput(L3, 101);
    L3 = adaugaInceput(L3, 102);
    L3 = adaugaSvarsit(L3, 103);

    afisare(L3);
    afisare(L2);

    printf("egalitate: %d", egalitate(L3, L2));
    eliberare(L3);
    eliberare(L2);
    return 0;
}