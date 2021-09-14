#include <stdio.h>

int sdivid(int x){
    int soma = 0;
    for(int i = x/2;i>0;i--){
        if(x%i == 0){
            soma = soma+i; 
        }
    }
    return soma;
}
int vabsoluto(int V){
    if(V < 0) V = V*-1;
    return V;
}

int main(){
    int V[5],R[5],soma;
    for(int i = 0;i<5;i++){
        scanf("%i",&V[i]);
        R[i] = vabsoluto(V[i]);
        soma = sdivid(R[i]);
        printf("soma:%i\n",soma);
    } 
}