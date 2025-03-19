/*Subiectul 1: Să se imlementeze un program care gestionează un parc de automobile. Informaţiile relative la un
automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai putere între 1
și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile, datele sunt citite
de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
a) Introducerea unui automobil nou;
b) Ștergerea unui anumit automobil, al cărui cod e citit de la tastatură;
c) Afișarea întregii liste de automobile;
d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură; NU E
e) Ordonarea listei în funcție de anul fabricației, folosind qsort. NU E
Să se definească structura pentru o mașină cu ajutorul structurilor cu câmpuri pe biți astfel încât spațiul ocupat să
fie minim.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_AUTOMOBILE 100

typedef struct
{
    unsigned short cod : 13;
    unsigned short putere : 9;
    unsigned short an_fabricatie : 12;
    unsigned char locuri : 4;
    char marca[30];
    char culoare[20];

} Automobil;

Automobil parc[MAX_AUTOMOBILE];
int n = 0;

void introducereAutomobil()
{
    if (n < MAX_AUTOMOBILE)
    {
        Automobil a;
        unsigned short aux = 0;
        printf("Cod (1-9000): ");
        scanf("%hu", &aux);
        a.cod = aux;
        printf("Locuri (1-9): ");
        scanf("%hu", &aux);
        a.locuri = aux;
        printf("Putere (1-500): ");
        scanf("%hu", &aux);
        a.putere = aux;

        printf("marca: ");
        scanf("%s", a.marca);
        printf("Culoare: ");
        scanf("%s", a.culoare);
        printf("An fabricatie (1800-2017): ");

        scanf("%hu", &aux);
        a.an_fabricatie = aux;
        aux = 0;
        parc[n++] = a;
        printf("Introducere reusita!\n");
    }
    else
    {
        printf("Parcul este plin!\n");
    }
}

void stergereAutomobil()
{
    unsigned short cod;
    printf("Cod la masina de sters: ");
    scanf("%hu", &cod);

    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (parc[i].cod == cod)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < n - 1; i++)
        {
            parc[i] = parc[i + 1];
        }
        n--;
        printf("Masina cu codul %hu a fost stearsa!\n", cod);
    }
    else
    {
        printf("Masina cu codul %hu nu a fost gasita!\n", cod);
    }
}

void afisareAutomobile()
{
    if (n == 0)
    {
        printf("Nu sunt masini in parc!\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("Cod: %hu, Locuri: %hhu, Putere: %hu CP, Marca: %s, Culoare: %s, An: %hu\n",
                   parc[i].cod, parc[i].locuri, parc[i].putere, parc[i].marca, parc[i].culoare, parc[i].an_fabricatie);
        }
    }
}

void afisareAutomobileLocuri()
{
    unsigned char locuri;
    printf("Locuri cautate: ");
    scanf("%hhu", &locuri);

    int gasite = 0;
    for (int i = 0; i < n; i++)
    {
        if (parc[i].locuri == locuri)
        {
            printf("Cod: %hu, Locuri: %hhu, Putere: %hu CP, Marca: %s, Culoare: %s, An: %hu\n",
                   parc[i].cod, parc[i].locuri, parc[i].putere, parc[i].marca, parc[i].culoare, parc[i].an_fabricatie);
            gasite++;
        }
    }

    if (gasite == 0)
    {
        printf("Nu sunt masini cu %hhu locuri.\n", locuri);
    }
}

int main()
{
    int optiune;
    do
    {
        printf("\n1. Introducere\n2. Stergere\n3. Afisare\n4. Afisare dupa locuri\n5. Ordonare\n0. Iesire\nOptiune: ");
        scanf("%d", &optiune);

        switch (optiune)
        {
        case 1:
            introducereAutomobil();
            break;
        case 2:
            stergereAutomobil();
            break;
        case 3:
            afisareAutomobile();
            break;
        case 4:
            afisareAutomobileLocuri();
            break;
        case 5:
            printf("cod terminat\n");
            break;
        default:
            printf("ggresit\n");
        }
    } while (optiune != 0);

    return 0;
}
