#include <stdio.h>
#include "TCircularList.h"

int main(void) {
    int teste,M,N,resu;
    scanf("%i",&teste);
    for(int i = 0;i<teste;i++){
        scanf("%i %i",&N,&M);
        resu = EDMUNDO(N,M);
        printf("%i\n",resu);
    }
  return 0;
}

