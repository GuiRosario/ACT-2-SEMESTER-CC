#include <stdio.h>

int main(void) {
    int n;
    int nmaior;
    scanf("%i",&n);
    nmaior = n;
    do{
       scanf("%i",&n); 
        if(n > nmaior){
            nmaior = n;
        }
    }while(n != -1);
    printf("O maior numeor digitado foi:%i\n",nmaior);
    return 0;
}