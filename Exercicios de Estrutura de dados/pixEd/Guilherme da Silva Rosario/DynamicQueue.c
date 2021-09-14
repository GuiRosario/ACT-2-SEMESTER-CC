#include "Queue.h"
#include <stdlib.h>

typedef struct no{
  int id_origem;
  int id_destino;
  float valor;
  struct no* prox;

}TNo;
TNo* TNo_createNFill(int id_origem,int id_destino,float valor){
  TNo* novo = malloc(sizeof(TNo));
  if(novo){
    novo->id_origem = id_origem;
    novo->id_destino = id_destino;
    novo->valor = valor;
    novo->prox = novo;
  }return novo;
}

struct queue{
  TNo* end;
  int qty;
};

Queue* Queue_create(){
  Queue* nova = malloc(sizeof(Queue));
  if(nova){
    nova->end = NULL;
    nova->qty = 0;
  }
  return nova;
}
void Queue_destroy(Queue* fila){
  int a,b;
  float c; 
  while(!Queue_empty(fila)){
    Queue_dequeue(fila,&a,&b,&c);
  }
  free(fila);
}

int Queue_enqueue(Queue* fila, int id_origem,int id_destino,float valor){
  TNo* novo = TNo_createNFill(id_origem,id_destino,valor);
  if(!novo) return 0;
  if(fila->end == NULL)
    fila->end = novo;
  else{
      novo->prox = fila->end->prox;
      fila->end->prox = novo;
      fila->end = novo;
  } 
  fila->qty++;
  return 1;
}
int Queue_dequeue(Queue* fila, int* id_origem,int* id_destino,float* valor){
  if(Queue_empty(fila)) return 0;
  TNo* oldBegin = fila->end->prox;
  *id_origem = oldBegin->id_origem;
  *id_destino = oldBegin->id_destino;
  *valor = oldBegin->valor;
  fila->end->prox = oldBegin->prox;
  free(oldBegin);
  fila->qty--;
  if(fila->qty==0)
    fila->end = NULL;
  return 1;
}

int Queue_head(Queue* fila, int* id_origem,int* id_destino,float* valor){
  if(Queue_empty(fila)) return 0;
  TNo* oldBegin = fila->end->prox;
  *id_origem = oldBegin->id_origem;
  *id_destino = oldBegin->id_origem;
  *valor = oldBegin->valor;
  return 1;
}

int Queue_full(Queue* fila,int N){
  return fila->qty == N;
}
int Queue_empty(Queue* fila){
  return fila->end == NULL;
}
int Queue_qty(Queue* fila){
  return fila->qty;
}