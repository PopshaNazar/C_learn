/*Aplicația 4.4: Folosind câmpuri pe biți, definiţi o structură pentru memorarea următoarelor informaţii despre
animale:
● numărul de picioare: număr întreg, minim 0 (ex. şarpe), maxim 1000 (ex. miriapod)
● greutatea în kg: număr real
● periculos pentru om: da/nu
● abrevierea ştiinţifică a speciei: şir de maxim 8 caractere
● vârsta maximă în ani: număr întreg, minim 0, maxim 2000
Unde este posibil, codificaţi informaţiile prin numere întregi de dimensiune cât mai mică, spre exemplu “da”=1,
“nu”=0. Definiţi structura în aşa fel încât să ocupe spaţiul minim de memorie posibil. Afişaţi spaţiul de memorie
ocupat, folosind operatorul sizeof. Folosind structura definită, citiţi de la tastatură informaţii despre un animal, iar
pe urmă afişaţi-le pe ecran.
Exemplu: valoare=147000, unitate:gram => 147 kilogram*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned int picioare : 8;
    unsigned int pericoulos : 1;
    unsigned int ani : 11;
    char nume[8];
    float g;
} Animal;

int main()
{
    Animal animal;

    __uint8_t aux;
    printf("nr picioare: ");
    scanf("%hhu", &aux);
    animal.picioare = aux;

    printf("este periculos? (1-da, 0-nu): ");
    scanf("%hhu", &aux);
    animal.pericoulos = aux;

    printf("nr ani: ");
    scanf("%hhu", &aux);
    animal.ani = aux;
    aux = 0;

    printf("nume: ");
    scanf("%s", animal.nume);

    printf("kg: ");
    scanf("%f", &animal.g);
    float kg = animal.g * 1000;

    printf("\nNume: %s, ani: %u, kg: %f, nrPicioare: %u, pericol: %u", animal.nume, animal.ani, kg, animal.picioare, animal.pericoulos);

    printf("\nsize: %ld", sizeof(animal));
    return 0;
}