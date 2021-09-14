#include <stdio.h>


int menor(int x, int y){
if(x > y){
    return y;
}else{
    return x;
}
}

int main(){
    int x,y,res;
    scanf("%i %i",&x,&y);
    res = menor(x,y);
    printf("O menor numero e: %i\n",res);
    return 0;  
}