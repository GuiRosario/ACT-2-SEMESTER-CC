#include <stdio.h>
#include <math.h>


float distancia(float x1,float y1,float x2,float y2){
    float calc,calc2;
    calc = ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
    calc2 = sqrt(calc);
    return calc2;

}


int main(){
    float x1,y1,x2,y2,res;
    scanf("%f %f %f %f",&x1,&x2,&y1,&y2);
    res = distancia(x1,x2,y1,y2);
    printf("A distancia entre os dois pontos é: %.2f",res);
return 0;
}