/*
Subiectul 2.1 Să se scrie un program pentru tabelarea unor funcţii matematice. Programul trebuie să tabeleze
funcţiile (x*x*x+4)/(x*x+5), x+10 şi 2*x*x-1.
Tabelarea se va realiza pe intervalul [A,B] cu pasul P. Valorile A, B şi P se vor citi de la tastatură. Programul va
afişa valorile funcţiilor sub formă de tabel.
Trebuie să se folosească pointeri la funcţii. Scrieţi o funcţie generică pentru tabelarea unei funcţii matematice
oarecare. Această funcţie generică va avea un parametru de tip pointer la funcţie.
Folosind funcţia generică, tabelaţi cele patru funcţii matematice amintite mai sus
*/

#include <stdio.h>
#include <stdlib.h>

int fun1(int x)
{
    return (x * x * x + 4) / (x * x + 5);
}

int fun2(int x)
{
    return x + 10;
}

int fun3(int x)
{
    return 2 * x * x - 1;
}

void calc(int A, int B, int P, int((*pf1)(int)), int((*pf2)(int)), int((*pf3)(int)))
{
    printf("[  x  ] =   [f1]     [f2]   [f3]\n");

    for (int n = A; n <= B; n += P)
    {
        printf("|%5d| = |%5d|  |%5d|  %5d|\n", n, ((*pf1)(n)), ((*pf2)(n)), ((*pf3)(n)));
    }
}

int main()
{
    int A, B, P;
    printf("A= ");
    scanf("%d", &A);

    printf("B= ");
    scanf("%d", &B);

    printf("P= ");
    scanf("%d", &P);

    calc(A, B, P, fun1, fun2, fun3);
}