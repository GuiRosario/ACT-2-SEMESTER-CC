#include <stdio.h>

int main(){
    int N;
    int mvalor;
    int mvalorp;
    scanf("%i",&N);
    int X[N];
    scanf("%i",&X[0]);
    mvalor = X[0];
    mvalorp = 0;
    for(int ler = 1;ler < N;ler++){
        scanf("%i",&X[ler]);
        if(X[ler] < mvalor){
            mvalor = X[ler];
            mvalorp = ler;

        }
    }
    printf("Menor valor: %i\nPosicao: %i\n",mvalor,mvalorp);
return 0;
}