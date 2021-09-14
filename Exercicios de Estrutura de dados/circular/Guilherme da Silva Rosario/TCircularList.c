#include "TCircularList.h"
#include <stdio.h>
#include <stdlib.h>

struct no{
  int info;
  struct no* prox;
};
struct circular_list {
  struct no* inicio;
};

struct no* no_create(int info){
  struct no* novo = malloc(sizeof(struct no));
  if(novo){
      novo->info = info;
      //Cuidado com esta diferença!!
      novo->prox = novo;
  }return novo;
}

TCircularList* TCircularList_create(){
  TCircularList* nova = malloc(sizeof(TCircularList));
  if(nova){
    nova->inicio = NULL;
  }return nova;
}

int TCircularList_insert_begin(TCircularList* list, int info){
  struct no* novo = no_create(info);
  if(novo == NULL || list==NULL) return 0;
  if(list->inicio == NULL)
    list->inicio = novo;
  else{
    //Preciso encontrar o último elemento da lista!  
    struct no* aux = list->inicio;
    while(aux->prox != list->inicio)
      aux = aux->prox;

    novo->prox = list->inicio;
    list->inicio = novo;
    aux->prox = list->inicio;
  }
  return 1;
}

int TCircularList_insert_end(TCircularList* list, int info){
  struct no* novo = no_create(info);
  if(novo == NULL || list==NULL) return 0;
  if(list->inicio == NULL)
    list->inicio = novo;
  else{
    //encontrar o último elemento
    struct no* aux = list->inicio;
    while(aux->prox != list->inicio)
      aux = aux->prox;
    //fazer o ultimo elemento apontar para o novo 
    aux->prox = novo;
    //o novo elemento apontar para o inicio
    novo->prox = list->inicio;
  } return 1;
}


void TCircularList_print(TCircularList* list){
    if(list==NULL) return;
    struct no* aux = list->inicio;
    if(aux==NULL) return;
    int i=0;
    do{
      printf("[%d]-> ", aux->info);
      aux = aux->prox;
      //printf("i=%d\n", i);
    //}while(++i<5);
    }while(aux != list->inicio);
}

int EDMUNDO(int N,int M){
    TCircularList* Destacamento = TCircularList_create();
    for(int i = 1;i<=N;i++){
        TCircularList_insert_end(Destacamento,i);
    }
    struct no* aux = Destacamento->inicio;
    struct no* ant;
    while(aux != aux->prox){
    for(int x = 0;x<M-1;x++){
        aux = aux->prox;
    }      
    ant = aux;
    while(aux->prox != ant){
        aux = aux->prox;
    }
    aux->prox = ant->prox;
    free(ant);
    aux = aux->prox;
    }
    return aux->info;
}