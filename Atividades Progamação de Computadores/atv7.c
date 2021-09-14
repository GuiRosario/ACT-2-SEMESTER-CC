#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char frase[1000];
    char frasef[1000];
    char *pt;
    int cont = 0;
    printf("Digite uma frase:");
    scanf ("%[^\n]", frase);
    strcpy(frasef,frase);
    pt = strtok(frase," ");
    while(pt){
        cont++;
        pt= strtok(NULL, " ");
    }
    pt = strtok(frasef," ");
    char inv[cont][100];
    cont = 0;
    while(pt){
        strcpy(inv[cont],pt);
        cont++;
        pt = strtok(NULL, " ");
    } 
    for(int i = cont-1;i>=0;i--){
        printf("%s ",inv[i]);
    }

    return 0;
}