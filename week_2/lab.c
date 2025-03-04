#include <stdio.h>

// int *filtru(int *v, int n, int((*pf)(int n)))
// {
//     for (int i = 0; i < n; i++)
//     {
//         if ((*pf)(v[i]) != 1)
//         {
//             for (int j = i; j < n - 1; j++)
//             {
//                 v[j] = v[j + 1];
//             }
//         }
//         n = n - 1;
//     }
//     return v;
// }

// qsort: vectoru/ cate elemente/ dimensiunea unui element/ functie compare -> int(*compare)(const void *e1, const void *e2))

// int (*compare)(const void *e1, const void *e2)
// {
//     int *elem1 = (int *)e1;
//     int *elem2 = (int *)e2;
//     if ((*elem1) == (*elem2))
//         return 0;
//     if ((*elem1) > (*elem2))
//         return -1;
//     return 1;
// }

#include <stdio.h>
int f1(int a, int b)
{
    return a + b;
}
int f2(int a, int b)
{
    return a - b;
}
int main(void)
{
    int a = 7, b = 5;
    int (*pf)(int, int);                          // pf - pointer la o functie cu doi parametri de tip int, care returneaza o valoare de tip int
    pf = &f1;                                     // se seteaza pf cu adresa functiei f1
    printf("op(%d,%d)=>%d\n", a, b, (*pf)(a, b)); // se apelează functia pointata de pf cu argumentele a si b
    pf = &f2;
    printf("op(%d,%d)=>%d\n", a, b, (*pf)(a, b));
    return 0;
}
// int main()
// {
//     // v = filtru(v, n, conditie)
//     return 0;
// }