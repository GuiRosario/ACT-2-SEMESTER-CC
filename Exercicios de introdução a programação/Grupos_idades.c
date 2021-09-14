#include <stdio.h>
#include <stdlib.h>

int idades[5][13];

void main(){
	for(int x = 0;x < 5;x++){
		float media_idade = 0;
		int cont_idade = 0;

		for(int c = 0;c < 13;c++){
			scanf("%i",&idades[x][c]);
			media_idade = media_idade + idades[x][c];
		}
		media_idade = media_idade/13;
		for(int y = 0; y < 13;y++){
			if(idades[x][y] < media_idade){
				cont_idade++;
			}
		}
		printf("Existem %i pessoas abaixo da média no grupo %i",cont_idade,x+1);
	}

	return;
}

