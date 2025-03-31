#include <stdio.h>
#include <stdlib.h>
int fun1(int x)
{
    return (x - 4) / (x + 4);
}
int fun2(int x)
{
    return x * 10;
}
int fun3(int x)
{
    return x * x + x + 1;
}
int fun4(int x)
{
    return 2 * x * x + x;
}

void tabelare(int A, int B, int((*fun1)(int)), int((*fun2)(int)), int((*fun3)(int)), int((*fun4)(int)))
{
    for (int i = A; i <= B; i++)
    {
        printf("for %3d| F1: %3d, F2: %3d, F3: %3d, F4: %3d\n", i, ((*fun1)(i)), ((*fun2)(i)), ((*fun3)(i)), ((*fun4)(i)));
    }
}
int main()
{
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);

    tabelare(A, B, fun1, fun2, fun3, fun4);
}