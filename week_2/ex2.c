/*Subiectul 2.2 Se citesc mai multe cuvinte din linia de comandă. Cu ajutorul pointerilor la funcții (un vector de
    pointeri la funcții) să se apeleze într-o structură repetitivă următoarele funcții. Să se afișeze rezultatele pentru
    fiecare cuvânt pe ecran și în fișierul text CUVINTE.TXT.
    a) Primește parametru un șir de caractere și returneză lungimea șirului.
    b) Primește parametru un șir de caractere și returneză numărul de vocale din text.
    c) Primește parametru un șir de caractere și returneză numărul de litere mari din text.
    Primește parametru un șir de caractere și returneză diferența codurilor ASCII ale primului caracter și al ultimului
    caracter.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int lungimea(const char *str)
{
    return strlen(str);
}

int numar_vocale(const char *str)
{
    int count = 0;
    char vocale[] = "aeiouAEIOU";
    for (int i = 0; str[i]; i++)
    {
        if (strchr(vocale, str[i]))
        {
            count++;
        }
    }
    return count;
}

int numar_litere_mari(const char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
    {
        if (isupper(str[i]))
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv)
{
    char *descriere[] = {
        "lungimea",
        "Numarul de vocale",
        "Numarul de litere mari"};

    int (*functii[])(const char *) = {lungimea, numar_vocale, numar_litere_mari};

    FILE *fisier = fopen("CUVINTE.TXT", "w");
    if (!fisier)
    {
        perror("eroare deschidere");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        printf("\nCuvant: %s\n", argv[i]);
        fprintf(fisier, "\nCuvant: %s\n", argv[i]);

        for (int j = 0; j < 3; j++)
        {
            int rezultat = functii[j](argv[i]);
            printf("%s: %d\n", descriere[j], rezultat);
            fprintf(fisier, "%s: %d\n", descriere[j], rezultat);
        }
    }

    return 0;
}