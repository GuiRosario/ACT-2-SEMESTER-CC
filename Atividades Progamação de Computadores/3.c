#include <stdio.h>

int potencia(int base, int expoente){
    int aux = 1;
    for(int i = 0;i < expoente;i++){
        aux = aux*base;
    }
    return aux;
}


int main(){
    int base,expoente,res;
    scanf("%i %i",&base,&expoente);
    res = potencia(base,expoente);
    printf("a potencia e: %i",res);
    return 0;
}