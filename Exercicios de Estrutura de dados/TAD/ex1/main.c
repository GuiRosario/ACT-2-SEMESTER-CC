#include <stdio.h>
#include "TAD1.h"

int main(){
    Complex* nc1 = creat(10,2);
    Complex* nc2 = creat(5,2);
    Complex* som;
    Complex* sb;
    som = soma(nc1,nc2);
    sb = sub(nc1,nc2);
    printf("nc1:");
    imp(nc1);
    printf("nc2:");
    imp(nc2);
    printf("soma:");
    imp(som);
    printf("sub:");
    imp(sb);
    return 0;
}