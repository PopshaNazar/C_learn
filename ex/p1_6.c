/*P1.6: Se da un string, care contine si numere pana la 6500,  oriunde in text. Sa se scrie o functie care returneaza un alt string, alocat dinamic, care inlocuieste numerele, scriindu-le pe 16 biti. (ex: “ana are 17 mere si pune13prune” devine “ana are 0000000000010001 mere si pune0000000000001101prune”)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#define CHUNK 50

void printBits(char *s, int d, int index)
{
    for (int i = sizeof(uint16_t) * 8 - 1; i >= 0; i--)
    {
        s[index] = ((d >> i) & 1) ? '1' : '0';
        index++;
    }
}

int main()
{
    char *s = malloc(CHUNK * sizeof(char));
    if (!s)
    {
        printf("erroare la alocare");
        return 1;
    }
    char c;
    int d;
    int index = 0;
    int size = CHUNK;

    while ((scanf("%c", &c)) != EOF)
    {
        if (isdigit(c))
        {
            scanf("%d", &d);
            if (index + 16 >= size)
            {
                size += CHUNK;
                char *temp = realloc(s, size * sizeof(char));
                if (!temp)
                {
                    printf("erroare la realocare");
                    free(s);
                    return 1;
                }
                s = temp;
            }
            printBits(s, d, index);
            index += 16;
        }
        else
        {
            if (index >= size - 1)
            {
                size += CHUNK;
                char *temp = realloc(s, size * sizeof(char));
                if (!temp)
                {
                    printf("erroare la realocare");
                    free(s);
                    return 1;
                }
                s = temp;
            }
            s[index] = c;
            index++;
        }
    }
    s[index] = '\0';
    printf("\n%s", s);

    free(s);
    return 0;
}
