#include <stdio.h>


void main(){
	char simbol;
	int n,soma;
	soma = 0;
	do{
		scanf("%i",&n);
		getchar();
		scanf("%c",&simbol);
		soma = soma+n;
	}while(simbol == '+');

	printf("Soma: %i\n",soma);

	return;
}