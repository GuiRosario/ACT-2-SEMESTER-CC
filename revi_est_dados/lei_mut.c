#include <stdio.h>
#include <string.h>

int main(){
    char C[51];
    int P;
    int t;
    int contR = 0;
    int contseqR = 0;
    int contW = 0;
    while (scanf("%s",C) != EOF){
            scanf("%i",&P);
            t = strlen(C); 
            contW = 0;
            contR = 0;
            for(int i = 0;i < t;i++){
                if(C[i] == 'R'){
                    contseqR = 0;
                    while(C[i] =='R'){
                        contseqR++;
                        i++;
                    }
                    if(contseqR > P){
                        if(contseqR%P == 0){
                            contR = contR + contseqR/P;
                        }else{
                            contR = (contR+1) + contseqR/P;
                        }
                    }else{
                        contR++;
                    }
                }
                if(C[i] == 'W'){
                    contW++;
                }
            }
            printf("%i\n",contR+contW);
        }
return 0;
}