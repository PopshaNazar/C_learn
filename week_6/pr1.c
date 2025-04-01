#include <stdio.h>
#include <stdlib.h>
// void maxim(char **v, int n, int m){
//     int counta = 0;
//     int countb = 0;
//     char a = v[0][0];
//     char v = v[0][1];

//     // for int(k =0; k<n; k++){
//     for(int i=0; i<n;i++){
//         for(int j=0; j<m; j++){
//             if()
//           }
//         }
//     // }   
// }
void afisare(char **v, int n, int m){
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            printf("%3c ", v[i][j]);
        }
        printf("\n");
    }
}
int main(){
    FILE *fin = fopen("matrice.txt", "r");
    if(!fin){
        printf("nu s a deschis fisieru");
        return 1;
    }
    int n, m;
    printf("n=");
    scanf("%d",&n);
    printf("m=");
    scanf("%d",&m);
    char **v = malloc(sizeof(char*)*n);
    if(!v){
        printf("probleme alocare");
        return 1;
    }
    for(int i=0; i<m; i++){
        v[i] = malloc(sizeof(char)*m);
        if(!v[i]){
            printf("probleme alocare");
            return 1;
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            fscanf(fin, "%c", &v[i][j]);
        }
    }

    afisare(v, n, m);
    fclose(fin);
    for(int i=0; i<m; i++){
        free(v[i]);
    }
    return 0;
}