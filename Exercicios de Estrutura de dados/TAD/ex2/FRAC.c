#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"

struct frac{
    int num,den;
};

Frac* creat(int num,int den){
    Frac* novo = malloc(sizeof(Frac*));
    if(novo == NULL){
        printf("Erro no malloc\n");
        return NULL;
    }else{
        novo->num = num;
        novo->den = den;
    }
}

Frac* soma(Frac* f1,Frac* f2){
    Frac* novo = malloc(sizeof(Frac));
    if(novo == NULL){
        printf("Erro no malloc\n");
        return NULL;
    }else{
        novo->den = f1->den*f2->den;
        novo->num = (f1->num*f2->den) + (f1->den*f2->num);
        return novo;
    }
}
Frac* multi(Frac* f1,Frac* f2){
    Frac* novo = malloc(sizeof(Frac));
        if(novo == NULL){
        printf("Erro no malloc\n");
        return NULL;
    }else{
        novo->num = f1->num*f2->num;
        novo->den = f1->den*f2->den;
        return novo;
    }
}

void comp(Frac* f1,Frac* f2){
    float n1,n2;
    n1 = f1->num/f1->den;
    n2 = f2->num/f2->den;
    if(n1 == n2) printf("Sao iguais!\n");
    else printf("Sao diferentes!\n");
}

void imp(Frac* f1){
    printf("\n %i ",f1->num);
    printf("\n---\n");
    printf(" %i \n\n",f1->den);
}


