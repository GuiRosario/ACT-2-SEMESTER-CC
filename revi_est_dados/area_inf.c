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

    for(int CL = 11;CL > 6;CL--){
        for(int CC = 12-CL;CC < CL;CC++){
            soma = soma + M[CC][CL];
        }
    }
    
    if(op == 'S'){
        printf("%.1f\n",soma);
    }else{
        printf("%.1f\n",soma/30);
    }

return 0;
}