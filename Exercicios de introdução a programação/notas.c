#include <stdio.h>
#include <stdlib.h>

int notas[3][30],alunosMAX[3],turma_maior_media,relatorio,esc_al,esc_turma;

float media_notas[3];
float  maior_media;
char op;

void main(){
	for(int a = 0; a < 3;a++){
		media_notas[a] = 0;
	}

	for(int x = 0;x < 3;x++){
		int cont_nalunos = 0;
		scanf("%i",&notas[x][0]);
		do{
			media_notas[x] = media_notas[x] + notas[x][cont_nalunos];
			cont_nalunos++;
			scanf("%i",&notas[x][cont_nalunos]);
		}while(notas[x][cont_nalunos] != -1 && cont_nalunos < 30);
		alunosMAX[x] = cont_nalunos;
	}

	maior_media = media_notas[0]/alunosMAX[0];
	for(int g = 0; g < 3 ;g++){
		media_notas[g] = media_notas[g] / alunosMAX[g];
		if(maior_media < media_notas[g]){
			turma_maior_media = g;
		}
	}

	do{
		printf("Deseja ver qual relatorio?(1,2,3,4)");
		scanf("%i",&relatorio);
		if(relatorio == 1){
			printf("Digite o numero do aluno e da turma que deseja ver:");
			scanf("%i",&esc_al);
			scanf("%i",&esc_turma);
			printf("O Aluno numero %i, da turma %i, obteve nota:%i\n",esc_al,esc_turma,notas[esc_turma-1][esc_al-1]);
		}
		else if(relatorio == 2){
			printf("Digite o numero da turma que deseja ver a media:");
			scanf("%i",&esc_turma);
			printf("A turma %i, obteve media:%.2f\n",esc_turma,media_notas[esc_turma-1]);
		}
		else if(relatorio == 3){
			printf("Digite o numero da turma que deseja ver os alunso com maior media:");
			scanf("%i",&esc_turma);
			for(int c = 0;c<alunosMAX[esc_turma - 1];c++){
				if(notas[esc_turma-1][c] > media_notas[esc_turma - 1]){
				printf("O aluno numero %i obteve nota acima da media de sua turma.\n",c+1);
				}
			}
		}
		else{
			printf("A turma %i obteve a maior media.\n",turma_maior_media+1);
		}

		printf("Deseja continuar vendo relatorios?(s ou n)");
		scanf(" %c",&op);
	}while(op != 'n');

	return;
}

