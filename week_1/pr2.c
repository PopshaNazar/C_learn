/* Se citesc de la tastatură un număr n și o matrice pătratică de dimensiune n conținând litere din
alfabet. Pe urmă se citește de la tastatură un cuvânt. Verificați dacă respectivul cuvânt se poate construi
parcurgând literele matricii pe verticală în sus sau în jos sau pe orizontală spre stânga sau spre dreapta. Afișați
toate pozițiile de unde trebuie începută parcurgerea, precum și sensul de parcurgere necesar pentru a construi
cuvântul.
Spre exemplu, dacă de la tastatură se introduce:
5
e r e m a
h e r e b
b m e r e
b a m e r
a e m r e
mere
pe ecran se va afișa:
De la linia 0 coloana 3 spre stânga.
De la linia 0 coloana 3 în jos.
De la linia 2 coloana 1 spre dreapta.
De la linia 3 coloana 2 în sus.
Nu are importanță ordinea în care sunt afișate soluțiile găsite. Dacă nu există soluție, se afișează “Nu există
soluție”. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_matrix(char **matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c", &matrix[i][j]);
}

int can_form_word(char **matrix, int n, char *word, int row, int col, int dirX, int dirY)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        int newRow = row + i * dirX, newCol = col + i * dirY;
        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || matrix[newRow][newCol] != word[i])
            return 0;
    }
    return 1;
}

void find_word_positions(char **matrix, int n, char *word)
{
    int found = 0, len = strlen(word);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == word[0])
            {
                if (can_form_word(matrix, n, word, i, j, 0, 1))
                {
                    printf("De la linia %d coloana %d spre dreapta.\n", i, j);
                    found = 1;
                }
                if (can_form_word(matrix, n, word, i, j, 0, -1))
                {
                    printf("De la linia %d coloana %d spre stânga.\n", i, j);
                    found = 1;
                }
                if (can_form_word(matrix, n, word, i, j, 1, 0))
                {
                    printf("De la linia %d coloana %d în jos.\n", i, j);
                    found = 1;
                }
                if (can_form_word(matrix, n, word, i, j, -1, 0))
                {
                    printf("De la linia %d coloana %d în sus.\n", i, j);
                    found = 1;
                }
            }
    if (!found)
        printf("Nu există soluție.\n");
}

void print_matrix(char **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c ", matrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int n;
    char **matrix, word[100];

    printf("n = ");

    scanf("%d", &n);

    matrix = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
        matrix[i] = (char *)malloc(n * sizeof(char));

    read_matrix(matrix, n);
    print_matrix(matrix, n);

    printf("the word: ");
    scanf("%s", word);
    find_word_positions(matrix, n, word);

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}
