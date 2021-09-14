#include<stdio.h>
#include "Queue.h"

int main(){
  int N;
  int id_origem;
  int id_destino;
  float valor;
  Queue* pix = Queue_create();
  scanf("%i",&N);
  while(1){
    scanf("%i %i %f",&id_origem,&id_destino,&valor);
    if(id_origem == 0 && id_destino == 0){
      break;
    }else{
        Queue_enqueue(pix,id_origem,id_destino,valor);
        if(Queue_full(pix,N)){
          while(!Queue_empty(pix)){
            Queue_dequeue(pix,&id_origem,&id_destino,&valor);
            printf("(%i, %i, %.2f),",id_origem,id_destino,valor);
          }
          printf("\n");
        }
      }
    } 
    if(!Queue_empty(pix)){
      while(!Queue_empty(pix)){
        Queue_dequeue(pix,&id_origem,&id_destino,&valor);
        printf("(%i, %i, %.2f),",id_origem,id_destino,valor);
      }
      printf("\n");  
    }
    Queue_destroy(pix);
    return 0;
}