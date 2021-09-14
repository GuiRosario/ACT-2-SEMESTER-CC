#include <stdio.h>

int main(){
    int T;
    int N[1000];
    int cont = 0;   
    scanf("%i",&T);
    int S[T];
    for(int pren = 0;pren < T;pren++) S[pren] = pren;
    for(int comp = 0;comp < 1000;comp++){
        if(comp%T == 0 && comp != 1 && comp != 0){
            cont = 0;
        }
        N[comp] = S[cont];
        
        cont++;
    }
    for(int imp = 0;imp < 1000;imp++){
        printf("N[%i] = %i\n",imp,N[imp]);
    }
return 0;
}