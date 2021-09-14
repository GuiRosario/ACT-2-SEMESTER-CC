#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void positivo(int n){
    if(n > 0){
        printf("O numero e positivo!\n");
    }else{
        printf("O numero e negativo!\n");
    }
}

int divisores(int n){
    int metade = n/2;
    int soma = 0;
    for(int i = 1;i<=metade;i++){
        if(n % i == 0){
            soma = soma + i;
        }
    }
    return soma;
}


int main(){
    int N;
    int n;
    scanf("%i",&N);
    for(int i = 0;i<N;i++){
        scanf("%i",&n);
        positivo(n);
        printf("Soma dos divisores:%i\n",divisores(n));
    }
	return 0;
}