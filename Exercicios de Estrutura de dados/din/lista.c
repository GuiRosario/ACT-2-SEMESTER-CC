#include <stdio.h>
#include <stdlib.h>
#include "LE.h"


struct no{
    int dado;
    struct lista* prox;
};

typedef struct no No;

struct lis{
    No* inicio;
};

No* creat_no(int info){
    No* novo = malloc(sizeof(No));
    novo->dado = info;
    novo->prox = NULL;
}


Lista* creat(){
    Lista* novo = malloc(sizeof(Lista));
    novo->inicio = NULL;
    return novo;
}

int in_end(Lista* l1,int info){
    No* novo = creat_no(info);
    
    if(l1->inicio == NULL){
        l1->inicio = novo;
        return 1;
    }else{
        No* aux = l1->inicio;
        while(aux->prox != NULL){
            aux = aux->prox; 
        }
        aux->prox = novo;
        return 1;
    }
}


















