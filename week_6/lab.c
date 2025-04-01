#include <stdio.h>
#include <stdarg.h>
#include <string.h>
int maxim(int nrArg, ...)
{
    va_list args;
    va_start(args, nrArg);

    int max = 0;
    for (int i = 0; i < nrArg; i++)
    {
        int x = va_arg(args, int);
        if (x > max)
            max = x;
    }

    va_end(args);
    return max;
}
// void print(char *command){
//     int len = strlen(command);
//     va_list args;
//     va_start(args, len);
//     for(int i=0; i<len; i++){
//         if(command[i]=='d')
//         {
//             int x = va_arg(args, int);
//             printf("%d", x);
//         }
//         if(command[i]=='f'){
//             double x = va_arg(args, int);
//             printf("%g", x);

//         }
//     }
//     va_end(args);
// }
int main()
{
    int n = maxim(3, 1, 2, 4, 3);
    printf("%d", n);
    return 0;
}