/*Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));*/
#include <stdio.h>
#include <stdarg.h>

int crescator(char tip, int nrArg, ...)
{
    va_list args;
    va_start(args, nrArg);

    int d[nrArg];
    double f[nrArg];

    for (int i = 0; i < nrArg; i++)
    {
        if (tip == 'd')
        {
            d[i] = va_arg(args, int);
        }
        if (tip == 'f')
        {
            f[i] = va_arg(args, int);
        }
    }
    // daca exista d
    if (d[1])
    {
        printf("e int\n");
        for (int i = 1; i < nrArg; i++)
        {
            if (d[i - 1] > d[i])
            {
                printf("nu e crescator");
                return 0;
            }
        }
    }
    // daca e f
    if (f[1])
    {
        printf("e float\n");
        for (int i = 1; i < nrArg; i++)
        {
            if (f[i - 1] > f[i])
            {
                printf("nu e crescator");
                return 0;
            }
        }
    }

    va_end(args);
    printf("e crescator");
    return 1;
}

int main()
{
    int n = crescator('d', 4, 1, 2, 3, 4);
    // int n = maxim(3, 1, 2, 4, 3);
    printf("%d", n);
    return 0;
}
