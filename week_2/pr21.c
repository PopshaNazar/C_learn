/*Aplicația 2.1: Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen. Fiecare rezultat
este definit prin (nume,nota). Se cere să se sorteze folosind qsort vectorul în ordinea notelor, notele cele mai mari
fiind primele. Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nume[15];
    int nota;
} Student;

void citire(Student *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("v[%d].nume: ", i);
        scanf("%s", v[i].nume);
        printf("v[%d].nota: ", i);
        scanf("%d", &v[i].nota);
    }
}

int compar(const void *a, const void *b)
{

    const Student *student1 = (const Student *)a;
    const Student *student2 = (const Student *)b;

    if (student1->nota == student2->nota)
    {
        return strcmp(student1->nume, student2->nume); // AICI
    }

    if (student1->nota > student2->nota)
        return -1;
    return 1;
}

void afisare(Student *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s: %d", v[i].nume, v[i].nota);
    }
}

int main()
{
    int n = 0;
    printf("n = ");
    scanf("%d", &n);
    Student v[n];

    citire(v, n);
    qsort(v, n, sizeof(Student), compar);
    afisare(v, n);
}