/*Să se creeze o structură care reține următoarele informații despre un student: nume (maxim 20 de
caractere), nota. Să se citească un element din structură și să se afișeze pe ecran.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nume[20];
    int nota;
} Student;

int main()
{
    Student student;
    scanf("%s", student.nume);
    scanf("%d", &student.nota);

    printf("%s : %d", student.nume, student.nota);
    return 0;
}