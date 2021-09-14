#include <stdio.h>

int main(){
    int N;
    int contpar = 0;
    int contimpar = 0;
    int par[5];
    int impar[5];
    for(int pren = 0;pren < 15;pren++){
        scanf("%i",&N);
        if(N%2 == 0){
            par[contpar] = N;
            contpar++;
        }else{
            impar[contimpar] = N;
            contimpar++;
        }

        if(contpar == 5){
            for(int imp = 0;imp < 5;imp++){
                printf("par[%i] = %i\n",imp,par[imp]);
            }
            contpar = 0;
        }

        if(contimpar == 5){
            for(int imp = 0;imp < 5;imp++){
                printf("impar[%i] = %i\n",imp,impar[imp]);
            }
            contimpar = 0;
        }        
    }
        
    for(int imp = 0;imp < contimpar;imp++){
        printf("impar[%i] = %i\n",imp,impar[imp]);
    }          


    for(int imp = 0;imp < contpar;imp++){
        printf("par[%i] = %i\n",imp,par[imp]);
    } 
return 0;
}