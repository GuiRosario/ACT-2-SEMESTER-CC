#include <stdio.h>


void main(){
	char op;
	int idade,cont;	
	float media;
	cont = 0;

	do{
		scanf("%i",&idade);
		media = idade + media;
		if(idade >= 18){
			printf("Maior de idade!\n");
		}else{
			printf("Menor de idade!\n");
		}
		printf("Quer continuar?(s ou n)\n");
		getchar();
		scanf("%c",&op);
		cont++;
	}while(op == 's');
	printf("Media das idades = %.2f\n",media/cont);

	return;
}