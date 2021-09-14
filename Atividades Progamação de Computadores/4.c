#include <stdio.h>

int vabsoluto(int V){
    if(V < 0) V = V*-1;
    return V;
}


int main(){
    int V[5],R[5];
    for(int i = 0;i<5;i++){
        scanf("%i",&V[i]);
        R[i] = vabsoluto(V[i]);
        printf("%i\n",R[i]);
    }
}