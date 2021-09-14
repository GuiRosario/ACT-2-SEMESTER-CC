#include <stdio.h>

int main(){
    int v;
    int N[10];
    do{ 
        scanf("%i",&v);
    }while(v > 50);

    for(int pot = 0;pot < 10;pot++){
        if(pot > 0) v *= 2; 
        N[pot] = v;
        printf("N[%i] = %i\n",pot,N[pot]);
    }

return 0;
}