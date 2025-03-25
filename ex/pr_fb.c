/*Se considera un fisier binar ce contine numere intregi pe 4 bytes. Programul nu va cunoaste dimensiunea fisierului.
Sa se scrie un program ce citeste un astfel de fisier si scrie numerele citite intr-un alt fisier in format text hexazecimal
cu 8 cifre hexa cate unul pe rand.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define CHUNK 10

int main(int argc, char **argv)
{
    FILE *fin = fopen(argv[1], "rb");
    if (!fin)
    {
        printf("fin nu s a deschis");
    }
    FILE *fout = fopen("fout.txt", "w");
    if (!fout)
    {
        printf("fout nu s a deschis");
    }

    int *v = malloc(CHUNK * sizeof(int));
    int index = 0;
    int size = CHUNK;

    while (1)
    {

        if (index == size)
        {
            size += CHUNK;
            int *temp = realloc(v, size * sizeof(int));
            if (!temp)
            {
                printf("problema in realocare");
                free(v);
                exit(1);
            }
            v = temp;
        }
        int r = fread(&v[index], sizeof(int), 1, fin);
        if (r != 1)
        {
            break;
        }
        index++;
    }

    for (int i = 0; i < index; i++)
    {
        // fwrite(&v[i], sizeof(int), 1, fout);
        if ((i % 8) == 0)
        {
            fprintf(fout, "\n");
        }
        fprintf(fout, "%x ", v[i]);
    }

    fclose(fin);
    fclose(fout);
    free(v);
    return 0;
}