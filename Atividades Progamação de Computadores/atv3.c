#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opp(float v){
    int i;
    printf("Escolha uma opção de pagamento:\n");
    printf("(1) A vista\n");
    printf("(2) Em duas vezes\n");
    if(v > 100) printf("(3) De três a dez vezes\n");
    scanf("%i",&i);
    return i;
}

void prest(int i,float v){
float calc;
int x;
    switch (i)
    {
    case 1:
        printf("Valor a vista: %.2f\n",v*0.90);
        break;
    case 2:
        printf("Duas prestações de: %.2f\n",v/2);
        break;
    case 3:
        printf("Em quantas vezes deseja parcelar?(3 a 10)\n");
        scanf("%i",&x);
        v = v/x;
        for(int c = 0;c<x;c++){
            printf("Parcela %i: %.2f\n",c+1,v);
            v = v*1.03;
        }
        break;
    }


}

int main(){
    float v;
    int i;
    scanf("%f",&v);
    i = opp(v);
    prest(i,v);
	return 0;
}