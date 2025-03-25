/*P1.1: Se cere citirea de la intrarea standard a unei linii de text de lungime nedefinită și procesarea acesteia prin
eliminarea tuturor caracterelor non-litera, cu excepția primului caracter non-litera care apare imediat după un cuvânt
Input:Ioane!!!,Ana    are , mere.
Output:Ioane!Ana are mere.
Programul se va termina fara memory leaks.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CHUNK 10

void stergere(char *s, int *index)
{

    for (int i = 1; i < *index; i++)
    {
        if (!isalpha(s[i - 1]) && (!isalpha(s[i])))
        {
            for (int j = i + 1; j < *index; j++)
            {
                s[j - 1] = s[j];
            }
            (*index)--;
            i--;
        }
    }
    s[*index] = '\0';
}
int main()
{
    char *s = (char *)malloc(CHUNK * sizeof(char));
    if (!s)
    {
        printf("erroare alocare");
        exit(-1);
    }
    char c;
    int size = 0;
    int index = 0;

    while (1)
    {
        if (index == size - 1)
        {
            size += CHUNK;
            char *temp = realloc(s, size * sizeof(char));
            if (!temp)
            {
                printf("erroare realocare");
                free(s);
                exit(-1);
            }
            s = temp;
        }
        if (scanf("%c", &c) == EOF)
            break;
        s[index] = c;
        index++;
    }
    s[index] = '\0';

    stergere(s, &index);

    printf("\n%s\n", s);
    free(s);
    return 0;
}