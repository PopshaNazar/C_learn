// /*Aplicația 2.2: Să se implementeze o funcție care primește ca parametri un vector de întregi, numărul elementelor
// din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție. Funcția
// va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu
// numărul de elemente rămas în vector. Să se testeze funcția cu un predicat care testează dacă un număr este
// negativ și să se afișeze vectorul rezultat.*/

// #include <stdio.h>

// int conditie(int n)
// {
//     if (n == 0)
//         return 1;
//     return 0;
// }

// void citire(int *v, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("v[%d]", i);
//         scanf("%d", &v[i]);
//     }
// }

// void afisare(int *v, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", v[i]);
//     }
// }

// void filtru(int *v, int *n, int((*pf)(int)))
// {
//     for (int i = 0; i < *n; i++)
//     {
//         if ((*pf)(v[i]) == 1)
//         {
//             for (int j = i; j < *n - 1; j++)
//                 v[j] = v[j + 1];
//             (*n)--;
//             i--;
//         }
//     }
// }

// int main()
// {
//     int n = 0;
//     int v[10];
//     scanf("%d", &n);

//     citire(v, n);
//     filtru(v, &n, conditie);
//     afisare(v, n);
//     return 0;
// }