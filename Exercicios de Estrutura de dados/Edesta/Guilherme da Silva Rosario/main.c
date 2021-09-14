#include<stdio.h>
#include "Stack.h"
int main(){
  char esc;
  int info;
  int posi;
  Stack* estp = Stack_create();
  Stack* ests = Stack_create();
  scanf("%c %i",&esc,&info);
  while(esc != '0'){
    if(esc == 'i'){
      if(Stack_push(estp,info)){
      }else{
        printf("overflow\n");
      }
    }else{      
      while(Stack_pop(estp,&posi)){
        printf("%i,",posi);
        if(posi!=info){
          Stack_push(ests,posi);
        }else{
          break;
        } 
      }
      if(posi != info){
        printf("underflow\n");
      }else{
        printf("\n");
      }
    }
    while(Stack_pop(ests,&posi)){
      Stack_push(estp,posi);
    }
    scanf(" %c %i",&esc,&info);
  }
  return 0;
}