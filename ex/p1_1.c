/*P1.1: Se cere de la tastatura o valoare intreaga fara semn pe 32 de biti. Se cere ulterior un index in intervalul [1,24] pozitia 0 fiind bitul LSB. Daca bitul din stanga si cel din dreapta indexului au aceeasi valoare, sa se seteze bitul de la index cu valoarea respectiva. Daca nu, sa se puna bitul de la index paritatea pe biti (0-par, 1-impar). In final se va afisa in hexazecimal si in binar valoarea obtinuta pe intreaga dimensiune.*/

#include <stdio.h>
#include <stdint.h>

void print_bit(unsigned int n)
{
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int verif(uint32_t n, int p)
{
    uint32_t mask = 0x1;

    if (p <= 0 || p >= 31)
        return 0;

    uint32_t left_bit = (n >> (p + 1)) & mask;
    uint32_t right_bit = (n >> (p - 1)) & mask;

    return (left_bit == right_bit) ? 1 : 0;
}

int paritate(uint32_t n, int p)
{
    uint32_t bit = (n >> p) & 1; // Extrage bitul de pe poziția p
    print_bit(bit);
    return bit;
}

int main()
{
    uint32_t n;
    int p;

    printf("n = ");
    scanf("%u", &n); // Schimbat la %u pentru uint32_t

    printf("p = ");
    scanf("%d", &p);

    printf("Reprezentarea binara initiala a lui n:\n");
    print_bit(n);

    printf("\nVerificare: p+1 si p-1 sunt identice?\n");
    int k = verif(n, p);
    printf("%d\n", k);

    if (k == 1)
    {
        n |= (1 << p); // Setează bitul p la 1
    }
    else
    {
        n |= (paritate(n, p) << p); // Setează bitul p în funcție de paritate
    }

    printf("\nReprezentarea binara finala a lui n:\n");
    print_bit(n);
    printf("\n%x\n%d", n, n);

    return 0;
}
