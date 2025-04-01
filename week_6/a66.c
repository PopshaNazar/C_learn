/*Aplicația 6.6: Să se scrie o funcție char *concat(int n,...) care primește un număr de șiruri de caractere și apoi
șirurile propriu-zise. Funcția va concatena într-un nou șir, alocat dinamic, conținuturile tuturor șirurilor date, cu câte
un spațiu între ele și va returna acest șir.
Exemplu: concat(3,”Ion”,”si”,”Ana”) => “Ion si Ana”*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CUVANT 50
char *concat(int nrArg, ...)
{
    va_list args;
    va_start(args, nrArg);
    char *rez = malloc(MAX_CUVANT * nrArg * sizeof(char));
    for (int i = 0; i < nrArg; i++)
    {
        strcat(rez, " ");

        strcat(rez, va_arg(args, char *));
    }
    va_end(args);
    return rez;
}
int main()
{
    char result[100];

    strcat(result, concat(3, "ana", "are", "sare"));
    printf("%s", result);
    return 0;
}