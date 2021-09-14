#include <stdio.h>

int main(){
    char op;
    float M[12][12];
    float soma = 0;
    scanf(" %c",&op); 
    for(int L = 0;L<12;L++){
        for(int C = 0;C<12;C++){
            scanf("%f",&M[L][C]);
        }
    }

    for(int CL = 0;CL < 11;CL++){
        for(int CC = 1 + CL;CC < 12;CC++){
            soma = soma + M[CL][CC];
        }
    }
    
    if(op == 'S'){
        printf("%.1f\n",soma);
    }else{
        printf("%.1f\n",soma/66);
    }

return 0;
}