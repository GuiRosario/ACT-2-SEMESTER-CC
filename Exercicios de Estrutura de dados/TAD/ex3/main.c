#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"
int main(){
    int n;
    Lista* l1 = creat();
    Lista* l2 = creat();
    Lista* l = creat();
    int V1[] = {1,2,3,4,5};
    int V2[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0;i<5;i++){
        inserir(l1,V1[i]);
    }
    for(int i = 0;i<10;i++){
        inserir(l2,V2[i]);
    }
    l = uni(l1,l2);
    n = maior(l1);
    //imp(l);
    ig(l1,l2);
    return 0;
}

