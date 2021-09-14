#include <stdio.h>

float medias(char l,float a,float b,float c){
    float media;
    if(l == 'A'){
        media = (a + b + c)/3;
        return media;
    }else if(l == 'P'){
        media = ((a*5) + (b*3) + (c*2))/10;
        return media;
    }else{
        media = 3/((1/a)+(1/b)+(1/c));
        return media;
    }
}

int main(){
    float a,b,c,media;
    char l;
    scanf("%f %f %f %c",&a,&b,&c,&l);
    media = medias(l,a,b,c);
    printf("A media é igual a: %f",media);
}