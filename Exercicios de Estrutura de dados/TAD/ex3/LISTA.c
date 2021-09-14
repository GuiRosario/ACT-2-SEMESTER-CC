#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"
#define MAX 10

struct lista{
    int cont;
    int V[MAX];
};

Lista* creat(){
    Lista* novo = malloc(sizeof(Lista));
    novo->cont = 0;
    return novo;
}

void inserir(Lista* l1,int e){
int aux = 0;    
    if(l1 == NULL){
        printf("Lista nao alocada!\n");
        return;
    }else{
        for(int i = 0;i<l1->cont;i++){
            if(l1->V[i] == e){
                aux = 1;
            }
        }
        if(aux == 0){
            l1->V[l1->cont] = e;
            l1->cont++;
        }
    }
}

void del(Lista* l1, int e){
    int aux = 0;    
    int posi;
    if(l1 == NULL){

    }else{
        for(int i = 0;i<l1->cont;i++){
            if(l1->V[i] == e){
                aux = 1;
                posi = i;
                break;
            }
        }
        if(aux==1){
            for(int x = posi;x<l1->cont;x++){
                l1->V[x] = l1->V[x+1]; 
            }
        }
    }
}

Lista* inter(Lista* l1, Lista* l2){
    Lista* novo = creat();  
    if(l1 == NULL || l2 == NULL){
        printf("Lista nao alocada!\n");
        return NULL;
    }else{
        for(int i = 0;i<l1->cont;i++){
            for(int x = 0;x<l2->cont;x++){
                if(l1->V[i] == l2->V[x]){
                    inserir(novo,l1->V[i]);
                }
            }
        }
        return novo;
    }
}

Lista* difer(Lista* l1,Lista* l2){
    Lista* novo = creat();
    Lista* it = inter(l1,l2);
    int aux = 0;
    if(l1 == NULL || l2 == NULL){
        printf("Lista nao alocada!\n");
        return NULL;
    }else{
        for(int i = 0;i<l1->cont;i++){
            for(int x = 0;x<it->cont;x++){
                if(l1->V[i] == it->V[x]){
                    aux = 1;
                }
            }
            if(aux == 0){
                inserir(novo,l1->V[i]);
    
            }
            aux = 0;
        }

        for(int i = 0;i<l2->cont;i++){
            for(int x = 0;x<it->cont;x++){
                if(l2->V[i] == it->V[x]){
                    aux = 1;
                }
            }
            if(aux == 0){
                inserir(novo,l2->V[i]);
    
            }
            aux = 0;
        }    
        return novo;
    }    
}

Lista* uni(Lista* l1,Lista* l2){
    Lista* dif = creat();
    Lista* it = creat();
    Lista* novo = creat();
    dif = difer(l1,l2);
    it = inter(l1,l2);
    if(dif->cont + it->cont > 10){
        printf("Maior q o tamanho do vetor!\n");
        return NULL;
    }else{
        for(int i = 0;i<it->cont;i++){
            inserir(novo,it->V[i]);
        }
        for(int i = 0;i<dif->cont;i++){
            inserir(novo,dif->V[i]);
        }
        return novo;       
    }

}

void imp(Lista* l1){
    for(int i = 0;i<l1->cont;i++){
        printf("\n%i\n",l1->V[i]);
    }
}

int maior(Lista* l1){
    int aux;

    aux = l1->V[0];

    for(int i = 0;i<10;i++){
        if(aux < l1->V[i]){
            aux = l1->V[i];
        }
    }
    return aux;
}

int menor(Lista* l1){
    int aux;

    aux = l1->V[0];

    for(int i = 0;i<10;i++){
        if(aux > l1->V[i]){
            aux = l1->V[i];
        }
    }
    return aux;
}

void ig(Lista* l1,Lista* l2){
    Lista* it = creat();
    it = inter(l1,l2);
    if(it->cont == l1->cont && it->cont == l2->cont){
        printf("Sao iguais\n");
        return;
    }else{
        printf("Sao diferentes!\n");
        return;
    }
}

void tam(Lista* l1){
    printf("tamanho do conjunto: %i\n",l1->cont);

}

void cva(Lista* l1){

    if(l1 ->cont > 0){
        printf("O conjunto n e vazio!\n");
    }else{
        printf("O conjunto e vazio!\n");
    }


}