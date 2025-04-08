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

elem *inversare(elem *lista)
{
    elem *prev = NULL;
    elem *cur = lista;
    elem *next = NULL;

    while (cur != NULL)
    {
        next = cur->urm;
        cur->urm = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

int main()
{

    elem *L2 = NULL;
    L2 = adaugaInceput(L2, 101);
    L2 = adaugaInceput(L2, 102);
    L2 = adaugaSvarsit(L2, 103);
    afisare(L2);
    L2 = inversare(L2);
    afisare(L2);

    eliberare(L2);
    return 0;
}