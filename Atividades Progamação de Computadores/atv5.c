#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

int compara_aposta(int *aposta, int *sorteio,int *val_certos,int na, int ns){
    int aux = -1;
    int* val;
    int n = 0;
    val = (int*)calloc(n,sizeof(int));
    for(int x = 0;x<na;x++){
        for(int i = 0;i<ns;i++){   
            aux = -1; 
            if(aposta[x] == sorteio[i]){
            aux = 0;    
                for(int c = 0;c<n;c++){
                    if(aposta[x] == val[c]){
                       aux = 1; 
                    }
                }
            }
            if(aux == 1){
                break;
            }else if(aux == 0){
                n++;
                val = (int*)realloc(val,n*sizeof(int));
                val[n-1] = aposta[x];
            }
        }
    }
    printf("Numeros acertados:");
    for(int i = 0;i<n;i++){
    printf("[%i] ",val[i]);
    }
    printf("\n");


    return n;
}

void sorteia_valores(int *sorteio,int n){
    srand(time(NULL));
    for(int i = 0;i<20;i++){
        sorteio[i] = rand() % 100; 
    }
}


void ler_aposta(int *aposta,int n){
    for(int i = 0;i<n;i++){
        printf("Informe o %iº valor(0 a 100):",i+1);
        scanf("%i",&aposta[i]);
    }
}

int main(){
    int n;
    int* aposta;
    int* sorteio;
    const int ns = 20;
    int na;
    int *val_certos;
    int nacert;
    printf("Digite a quantidade de numeros que deseja apostar!(1 a 20)\n");
    scanf("%i",&n);
    na = n;
    aposta = (int*)calloc(n,sizeof(int));
    sorteio = (int*)calloc(20,sizeof(int));
    ler_aposta(aposta,n);
    sorteia_valores(sorteio,n);
    nacert = compara_aposta(aposta,sorteio,val_certos,na,ns);
    printf("Quantidade de Números acertados: %i\n",nacert);
    printf("\n");
	return 0;
}