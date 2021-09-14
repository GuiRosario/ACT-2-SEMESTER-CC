#include <stdio.h>

int main(){
    int N[20];
    int save;
    for(int ler = 0;ler < 20;ler++){
        scanf("%i",&N[ler]);
    }

    for(int trocar = 0;trocar<10;trocar++){
        int save = N[trocar];
        N[trocar] = N[19-trocar];
        N[19-trocar] = save;
    }

    for(int imp = 0;imp<20;imp++){
        printf("N[%i] = %i\n",imp,N[imp]);
    }
return 0;
}