#include "LDouble.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct no{
  int info;
  struct no *prox, *ant;
};

struct no* TNo_createnfill(int info){
  struct no* novo = (struct no*) malloc(sizeof(struct no));
  if(novo){
    novo->info = info;
    novo->prox = NULL;
    novo->ant = NULL;
  }
  return novo;
}
struct double_linked{
  struct no *inicio;
  struct no *fim;
};

TDList* TDList_create(){
  TDList* nova = (TDList*) malloc(sizeof(TDList));
  if(nova){
    nova->inicio = NULL;
    nova->fim = NULL;
  }
  return nova;
}

void TDList_adini(TDList* l1,int inf){
  struct no* novo = (struct no*) malloc(sizeof(struct no));
  struct no* aux;
  novo->info = inf;
  if(novo){
    if(l1->inicio==NULL && l1->fim == NULL){
      l1->inicio = novo;
      l1->fim = novo;
    }else{
      aux = l1->fim;
      while(aux->ant!=NULL){
        aux = aux->ant;
      }
      aux->ant = novo;
      novo->prox = aux;
      l1->inicio = novo;
    }
  }
}

void TDList_adfim(TDList* l1,int inf){
  struct no* novo = (struct no*) malloc(sizeof(struct no));
  struct no* aux;
  novo->info = inf;
  if(novo){
    if(l1->inicio==NULL && l1->fim == NULL){
      l1->inicio = novo;
      l1->fim = novo;
    }else{
      aux = l1->inicio;
      while(aux->prox!=NULL){
        aux = aux->prox;
      }
      aux->prox = novo;
      novo->ant = aux;
      l1->fim = novo;
    }
  }
}

void TDList_destroy(TDList* list){
  while(list->inicio){
  if(list->fim == list->inicio){
    list->inicio = NULL;
    list->fim = NULL;
    free(list);
    return;
  }
  struct no* aux = (struct no*) malloc(sizeof(struct no));
  aux = list->fim;
  list->fim = aux->ant;
  free(aux);
  }
}

void TDList_print(TDList* list){
  if(list){
    struct no* aux = list->inicio;
    while(aux){
      printf("%d", aux->info);
      aux = aux->prox;
    }
    puts("");
  }
}

//Veja no LDouble.h para verificar os tipos de retorno
TDList* TDList_generate(char* charNum){
    TDList* novo = TDList_create();
    int valor;
    int tamanho = strlen(charNum);
    for(int i = 0;i<tamanho;i++){
    valor = charNum[i] - '0';
    if(valor < 0){
      break;
    }
    TDList_adfim(novo,valor);
    }
    return novo;
}

//Veja no LDouble.h para verificar os tipos de retorno
TDList* TDList_sum(TDList* l1, TDList* l2){
  TDList* novo = TDList_create();
  struct no* aux1 = l1->fim;
  struct no* aux2 = l2->fim;
  int soma;
  int conf = 0;
  int vai1 = 0;
  while(aux1->ant != NULL && aux2->ant != NULL){
    if(conf == 1){
      aux1 = aux1->ant;
      aux2 = aux2->ant;
    }
    soma = aux1->info + aux2->info + vai1;
    if(soma > 9){
      soma = soma - 10;
      vai1 = 1;
    }else{
      vai1 = 0;
    }
    TDList_adini(novo,soma);
    conf = 1;
  }
  if(aux1->ant == NULL && aux2->ant == NULL){
    return novo;
  }else if(aux1->ant == NULL){
    aux2 = aux2->ant;
    while(aux2->ant != NULL){
      TDList_adini(novo,aux2->info);
      aux2 = aux2->ant;
    }
    TDList_adini(novo,aux2->info);
    return novo;
  }else if(aux2->ant == NULL){
    aux1 = aux1->ant;
    while(aux1->ant != NULL){
      TDList_adini(novo,aux1->info);
      aux1 = aux1->ant;
    }
    TDList_adini(novo,aux1->info);
    return novo;
  }
  return NULL;
}
