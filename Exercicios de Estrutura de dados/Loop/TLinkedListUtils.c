#include "TLinkedListUtils.h"
#include "TLinkedList.h"
#include<stdio.h>
#include<stdlib.h>

int TLinkedList_hasLoop(TLinkedList* list){

  /*
  Segue um exemplo de acesso aos nós da lista. 
  Cuidado com o código abaixo, pois para listas com loops, 
  vai gerar um loop infinito imprimindo dados.
  TNo* aux = TLinkedList_getInicio(list);
  while(aux){
    printf("%d, ", aux->info);
    aux=aux->prox;
  }*/
  //Inicie o desenvolvimento por excluir a proxima linha 
  //Faça seu código aqui

  TNo* aux = TLinkedList_getInicio(list);
  TNo** p;
  p = (TNo*) malloc(sizeof(TNo));
  int i = 0; 
  while(aux->prox != NULL){
  p[i] = aux;
  aux = aux->prox;
  for(int x = 0;x<i;x++){
    if(p[x] == aux){
      return x + 1;
    }
  }

  i++;
  p = (TNo*) realloc(p,(i+1)*sizeof(TNo));
  }
  return 0;
}


