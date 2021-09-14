#include <stdio.h>

int main(){
    int x[10];
    
    for(int coleta = 0;coleta < 10;coleta++) scanf("%i",&x[coleta]);

    for(int sub = 0;sub < 10;sub++){
        if(x[sub] <= 0){
            x[sub] = 1;
        }

        printf("X[%i] = %i\n",sub,x[sub]);

    }

return 0;
}