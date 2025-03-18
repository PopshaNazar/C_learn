/*P1.3: Se da un tablou de numere intregi pe 16 biti fără semn. Sa se implementeze o functie char *arraytostr(uint16_t *array, int size) avand ca parametri tabloul si dimensiunea sa care returneaza un string alocat dinamic care sa contina numerele din tablou scrise în binar, separate prin spațiu. Se va aloca minimul necesar de memorie, iar pentru testare se va defini dimensiunea maxima a tabloului printr-un macro iar tabloul va fi populat cu numere aleatoare din intervalul [0, 500000]. Programul se va termina fara memory leaks.

De exemplu pentru tabloul {12, 200, 123, 1, 700} de dimensiune 5 stringul returnat va fi “0000000000001100 0000000011001000 0000000001111011 0000000000000001 0000001010111100” */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#define MAX 5

char *arraytostr(uint16_t *array, int size)
{
    char *str = malloc(size * 17 + 1);
    if (!str)
    {
        printf("Eroare la alocare\n");
        exit(1);
    }
    str[0] = '\0';

    for (int i = 0; i < size; i++)
    {
        char b[17];
        for (int k = 0; k < 16; k++)
        {
            b[15 - k] = ((array[i] >> k) & 1) ? '1' : '0';
        }
        b[16] = '\0';

        strcat(str, b);
        strcat(str, " ");
    }

    return str;
}

void set(uint16_t **array, int size)
{

    uint16_t *temp = realloc(*array, size * sizeof(uint16_t));
    if (temp == NULL)
    {
        printf("erroare la alocare");
        exit(1);
    }
    *array = temp;
    for (int i = 0; i < size; i++)
    {
        (*array)[i] = rand() % 5001;
    }
}

int main()
{
    srand(time(NULL));

    uint16_t *array = NULL;
    int size = MAX;
    set(&array, size);
    char *s = arraytostr(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("%s", s);

    free(array);
    return 0;
}