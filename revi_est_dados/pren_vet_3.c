#include <stdio.h>

int main(){
    double X;
    double N[100];
    scanf("%lf",&X);
    N[0] = X;
    for(int comp = 0;comp < 100;comp++){
        N[comp+1] = N[comp]/2;
    }
    for(int imp = 0;imp < 100;imp++){
        printf("N[%i] = %.4lf\n",imp,N[imp]);
    }
return 0;
}