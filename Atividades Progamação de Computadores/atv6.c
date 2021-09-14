#include <stdio.h>
#include <stdlib.h>


int *maiorV(int *V,int n){
    if(n == 1){
        return (V);
    }else{
        if(V[n-1] > V[n-2]){
            V[n-2] = V[n-1];
            n--;
        }else{
            n--;
        }
        V = maiorV(V,n);
        return V;
    }
}


int main(){
    int n;
    int *maior;
    printf("Escolha o tamanho do vetor:");
    scanf("%i",&n);
    int *V = malloc(n*sizeof(int));
    for(int i = 0;i<n;i++){
        printf("Digite o %iº valor:",i+1);
        scanf("%i",&V[i]);
    }
    maior = maiorV(V,n);
    printf("Maior:%i",maior[0]);

    return 0;
}