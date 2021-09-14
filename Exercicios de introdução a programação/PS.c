#include <stdio.h>
#include <stdlib.h>

void main(){
	int PS[5][20];
	char op;
	char esc;
	int totalvaci;
	int escvac;
	for(int x = 0;x<5;x++){
		for(int c = 0;c<20;c++){
			printf("Vacinas Aplicadas no posto %i, no dia %i:",x,c+1);
			scanf("%i",&PS[x][c]);
		}
	}

	do{
		totalvaci = 0;	
		printf("Qual o tipo de relatorio gostaria de ver?(p(posto),d(dia),m(mes)\n");
		scanf(" %c",&esc);
		if(esc == 'p'){
			printf("Digite o numero do posto que deseja ver:(0 a 4)");
			scanf("%i",&escvac);
			for(int x=0;x<20;x++){
				totalvaci = totalvaci + PS[escvac][x];
			}
			printf("Neste postos foram aplicadas %i vacinas.\n",totalvaci);
		}else if(esc == 'd'){
			printf("Digite o dia que deseja ver:");
			scanf("%i",&escvac);
			for(int x=0;x<5;x++){
				totalvaci = totalvaci + PS[x][escvac-1];
			}
			printf("Neste dia foram aplicadas %i vacinas.\n",totalvaci);
		}else{
			for(int x = 0;x<5;x++){
				for(int c = 0;c<20;c++){
					totalvaci = totalvaci + PS[x][c];
				}
			}
			printf("No mês de janeiro foram aplicadas %i vacinas.\n",totalvaci);
		}	

		printf("Deseja ver mais algum relatorio?(s ou n)");
		scanf(" %c",&op);
	}while(op != 'n');





	return;
}