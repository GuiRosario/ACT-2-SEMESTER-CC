#include <stdio.h>

int main(void) {
    int n;
    int cont = 0;
    scanf("%i",&n);

    for(int primo = 1;primo <= n;primo++){
        if(n%primo == 0){
            cont++;
        }
    }

    if(cont == 2){
        printf("O numero e primo!\n");
    }else{
        printf("O numero nao e primo!\n");
    }

    return 0;
}