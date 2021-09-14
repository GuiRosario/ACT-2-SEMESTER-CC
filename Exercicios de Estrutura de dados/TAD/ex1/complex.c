#include <stdio.h>
#include <stdlib.h>
#include "TAD1.h"

struct comp{
    float x,y;
};

Complex* creat(float x,float y){
    Complex* novo = malloc(sizeof(Complex));
    if(novo == NULL){  
        printf("Erro no Malloc\n");
        return NULL;
    }else{
        novo->x = x;
        novo->y = y;
        return novo;
    }
}

void del(Complex* nc){
    free(nc);
}

Complex* soma(Complex* nc1,Complex* nc2){
    Complex* novo = malloc(sizeof(Complex));
    if(novo == NULL){
            printf("Erro no Malloc\n");
            return NULL;   
    }else{
        novo->x = nc1->x + nc2->x;
        novo->y = nc1->y + nc2->y;
        return novo;
    }
}

Complex* sub(Complex* nc1,Complex* nc2){
    Complex* novo = malloc(sizeof(Complex));
    if(novo == NULL){
            printf("Erro no Malloc\n");
            return NULL;   
    }else{
        novo->x = nc1->x - nc2->x;
        novo->y = nc1->y - nc2->y;
        return novo;
    }    
}

void imp(Complex* nc){
    printf("%.1f + i%.1f\n",nc->x,nc->y);
}


