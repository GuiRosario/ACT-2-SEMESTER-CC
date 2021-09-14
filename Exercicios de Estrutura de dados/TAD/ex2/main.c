#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

int main(){
    Frac* f1 = creat(10,2);
    Frac* f2 = creat(25,3);
    Frac* sm = soma(f1,f2);
    Frac* m = multi(f1,f2);

    printf("f1:\n");
    imp(f1);
    printf("f2:\n");
    imp(f2);
    printf("soma:\n");
    imp(sm);
    printf("multi:\n");
    imp(m);
    comp(f1,f2);
    return 0;
}