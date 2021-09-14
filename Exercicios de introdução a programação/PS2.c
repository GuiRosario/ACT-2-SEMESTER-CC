#include <stdio.h>
#include <stdlib.h>

void main(){
	int PS[5][20][4];
	char op;
	char esc;
	int totalvaci;
	int escvac;
	for(int z = 0;z<4;z++){
		for(int x = 0;x<5;x++){
			for(int c = 0;c<20;c++){
				printf("Vacinas Aplicadas no posto %i, no dia %i, do mês %i:",x,c+1,z+1);
				scanf("%i",&PS[x][c][z]);
			}
		}
	}
	return;
}
	int totalvacina;
	for(int mes = 0;mes<4;mes++){
		for(int dia = 0;dia<20;dia++){
			totalvacina = totalvacina + vacinas[2][dia][mes]
		}
	}

	int totalvacinajaneiro;
	for(int posto = 0;posto<4;posto++){
		for(int dia = 0;dia<20;dia++){
			totalvacina = totalvacina + vacinas[posto][dia][0];
		}
	}