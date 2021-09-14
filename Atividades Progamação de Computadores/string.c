#include <stdio.h>

void sigual(char *str1,char *str2){
    while(*str1){
        if(*str1 != *str2){
            printf("As strings são diferentes\n");
            return;
        }
        else{
            str1++;
            str2++;
        }
    }
    if(*str2 == '\0'){
        printf("As strings sao iguais\n");
    }else{
        printf("As strings são diferentes");
    }
}

int main(){
    char str1[50],str2[50];
    gets(str1);
    gets(str2);
    sigual(str1,str2);
}