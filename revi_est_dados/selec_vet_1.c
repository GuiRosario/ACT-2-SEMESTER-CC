#include <stdio.h>

int main(){
    float A[100];

    for(int col = 0;col < 100;col++){
        scanf("%f",&A[col]);
    }
    for(int imp = 0;imp < 100;imp++){
        if(A[imp] <= 10){
            printf("A[%i] = %.1f\n",imp,A[imp]);
        }      
    }
return 0;
}