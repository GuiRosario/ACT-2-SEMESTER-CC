#include <stdio.h>
#include <stdlib.h>

void main(){

	int idade[10];
	float freq[10][8];
	float nox;
	float mfreq;
	float medio_oxi[10];
	char op;
	int atleta;
	for(int h = 0;h<10;h++){
		medio_oxi[h] = 0;
	}
	for(int x = 0; x<10;x++){
		printf("Digite a idade do atleta %i:",x+1);
		scanf("%i", &idade[x]);
		for(int c = 0;c<8;c++){
			printf("Digite a frequencia cardiaca do atleta %i, na semana %i:",x+1,c+1);
			scanf("%f",&freq[x][c]);
			printf("Digite o nivel de oxigenio do atleta %i, na semana %i:",x+1,c+1);
			scanf("%f",&nox);
			medio_oxi[x] = nox + medio_oxi[x];	
		}	
	}

	do{
		printf("Qual atleta deseja ver o Relatorio?(1 a 10)");
		scanf("%i",&atleta);
		printf("Idade: %i\n",idade[atleta-1]);
		printf("Nivel medio de oxigenio no sangue: %.2f\n",medio_oxi[atleta-1]/8);
		mfreq = freq[atleta-1][0];
		for(int x = 1;x<8;x++){
			if(freq[atleta-1][x] > mfreq){
				mfreq = freq[atleta-1][x];
			}
		}
		printf("Maior Frequencia Cardiaca Registada: %.2f\n\n",mfreq);

		printf("Deseja ver Mais Algum Relatorio?(s ou n)");
		scanf(" %c",&op);
	}while(op != 'n');



	return;
}