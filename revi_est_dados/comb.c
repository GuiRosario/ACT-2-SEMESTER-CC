#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%i",&N);
    char F1[N][51];
    char F2[N][51];
    int tamanhoF1;
    int tamanhoF2;
    int cont;
    char D[N][51];
    for(int i = 0;i < N;i++){
        scanf("%s %s",F1[i],F2[i]);
        tamanhoF1 = strlen(F1[i]);
        tamanhoF2 = strlen(F2[i]);
        cont = 0;
        for(int l = 0;l < 51;l++){
            D[i][l] = 0;
        }
        do{
            D[i][cont] = F1[i][cont/2];
            cont++;
            D[i][cont] = F2[i][cont/2];
            cont++;
        }while(cont/2 < (tamanhoF1) && cont/2 < (tamanhoF2));
        int save = cont/2;
        if(cont/2 == tamanhoF1 && cont/2 == tamanhoF2){
        }else if(cont/2 < tamanhoF1){
            for(int x = save;x<tamanhoF1;x++){
                D[i][cont] = F1[i][x];
                cont++;
            } 
   
        }else if(cont/2 < tamanhoF2){
             for(int x = save;x<tamanhoF2;x++){
                D[i][cont] = F2[i][x];
                cont++;
            }     
        }  
    }
    for(int imp = 0;imp < N;imp++){
        printf("%s\n",D[imp]);
    }  
return 0;
}