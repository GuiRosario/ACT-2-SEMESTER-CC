#include <stdio.h>

int main(){
    char op;
    double M[12][12];
    double soma = 0;
    scanf(" %c",&op); 
    for(int L = 0;L<12;L++){
        for(int C = 0;C<12;C++){
            scanf("%lf",&M[L][C]);
        }
    }

    for(int CL = 0;CL < 5;CL++){
        for(int CC = CL+1;CC < 11-CL;CC++){
            soma = soma + M[CL][CC];
        }
    }
    
    if(op == 'S'){
        printf("%.1lf\n",soma);
    }else{
        printf("%.1lf\n",soma/30);
    }

return 0;
}