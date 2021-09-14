#include <stdio.h>
#include <string.h>

int main(){
    int N;
    int tamanho;
    int cont;
    scanf("%i",&N);
    getchar();
    char F[N][101];
    char D[N][101];
    for(int i = 0;i < N;i++){
        scanf("%[^\n]",F[i]);
        getchar();
        tamanho = strlen(F[i]);
        cont = 0;
        for(int x = 0;x <101;x++){
            D[i][x] = 0;
        }
        for(int x = (tamanho/2)-1;x >=0;x--){
            D[i][cont] = F[i][x];
            cont++;
        }
        for(int c = tamanho-1;c>=(tamanho/2);c--){
            D[i][cont] = F[i][c];
            cont++;
        }
        for(int imp = 0;imp < tamanho;imp++){
            printf("%c",D[i][imp]);
        }
        printf("\n");
    }

return 0;
}