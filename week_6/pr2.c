#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// int a(int x, int(*f)(int)){
//     int rez = (*f)(x); //+int((*g)(int));
//     return rez;
// }
int d(int x){
    return sin(x)+pow(2,x);
}
int e(int x){
    return pow(3,x);
}
int f(int x){
    return x;
}
int g(int x){
    return 1+2*x+pow(3*x, 2)+pow(4*x, 3);
}
void calculeaza(int x, int(*d)(int), int(*e)(int),int(*f)(int), int(*g)(int)){

    printf("x= %d", i);
    printf("d(x)=%d", (*d)(x));
}
int main(){
    int x;
    printf("x=");
    scanf("%d", &x);
    // int rez = a(x, f(int));
    int rez;
    rez = calculeaza(x, &d(x), &e(x), &f(x), &g(x));
    printf("%d", rez);

    return 0;
}