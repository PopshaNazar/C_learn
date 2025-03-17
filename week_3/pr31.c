// #include <stdio.h>
// typedef struct
// {
//     int *colection;
//     int currentSize;
//     int maxSize;
//     // int varf;
// } Stiva;

// Stiva *createStack(int maxSize)
// {

//     Stiva *s = (Stiva *)malloc(sizeof(Stiva));
//     if (s == NULL)
//     {
//         printf("Error la creare stiva");
//         free(s);
//         return (1);
//     }
//     s->maxSize = maxSize;
//     s->currentSize = 0;
//     s->colection = (int *)malloc(maxSize * sizeof(int));
//     if (s->colection == NULL)
//     {
//         printf("Error la creare element");
//         free(s->colection);
//         return (1);
//     }

//     return s;
// }

// void push(Stiva *s, int item)
// {
//     if (s->currentSize == s->maxSize)
//     {
//         printf("Stiva este plina");
//     }
//     else
//     {
//         s->colection[s->currentSize++] = item;
//     }
// }

// int pop(Stiva *s)
// {
//     if (s->currentSize == 0)
//     {
//         printf("Stiva deja este goala, elementul nu a fost adaugat");
//         return 0;
//     }
//     else
//     {
//         // s->colection[s->currentSize] = NULL;
//         return s->colection[s->currentSize--];
//     }
// }

// void printStiva(Stiva s)
// {
//     if (s.currentSize == 0)
//         printf("stiva goala");
//     else
//     {
//         for (i = 0; i < s.currentSize; i++)
//         {
//             printf("elem[%d] = %d", i, s.colection[i]);
//         }
//     }
// }

// int main()
// {

//     Stiva *s = createStack(12);
//     push(s, 12);

//     free(s);
//     return 0;
// }