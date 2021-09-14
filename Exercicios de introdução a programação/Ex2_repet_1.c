#include <stdio.h>


void main(){
	char op;
	int idade;	


	do{
		scanf("%i",&idade);
		if(idade >= 18){
			printf("Maior de idade!\n");
		}else{
			printf("Menor de idade!\n");
		}
		printf("Quer continuar?(s ou n)\n");
		getchar();
		scanf("%c",&op);
	}while(op == 's');


	return;
}