#include <stdio.h>

int par(int x){
    if(x%2 == 0) return 1;
    else return 0;
}

int main(){
    int x;
    scanf("%i",&x);
    printf("O valor é: %i",par(x));
}