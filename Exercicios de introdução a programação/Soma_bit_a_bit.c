#include <stdio.h>

void main(){
	char result = 'x';
	char letra = 'h';
	char nome[8] = "bolagola";
	int posi[8];
	int s;
	int p;
	p = 1;
	char carac;

	for(int x = 0;x<8;x++){
		s = letra & p;
		if(s == p){
			posi[7 - x] = 1;
		}else{
			posi[7 - x] = 0;
		}
		p = p*2;
	}
	printf("Codigo:");
	for(int x = 0;x<8;x++){
		printf("%i",posi[x]);	
	}
	printf("\n");	

	for(int x = 0;x<8;x++){
		if(posi[7-x] == 1){
			nome[7-x] = nome[7-x] | 1;
		}else{
			nome[7-x] = nome[7-x] & 254;
		}
	}
	printf("%s\n",nome);

	p = 1;
	for(int x = 0;x<8;x++){
		if(nome[7-x] & 1 == 1){
			result = result | p;
		}else{
		  	result = result & 255 - p;
		}
		p = p*2;
	}

	printf("Mensagem:%c",result);

	return;
}