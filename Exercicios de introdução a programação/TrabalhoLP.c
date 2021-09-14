#include <stdio.h>
#include <stdlib.h>

void main(){
	/*------------------------------DECLARAÇÂO DE VARIAVEIS------------------------------*/
	char nome[6][30][30],op;
	float notas[30][4][6],mediadenotasgeral,mediafinal;
	int faltas[30][6],contaluno,nalunosturma[6],naluno,nturma,salvanota0,contalunosnota0,contalunosmed8,contalunosubstitui;
	/*----------------------------------COLETA DE DADOS----------------------------------*/
	for(int turmas = 0;turmas < 6;turmas++){
		contaluno = 0;
		do{
			printf("\n\nDigite o nome do aluno %i da turma %i:",contaluno+1,turmas+1);
			scanf(" %s",&nome[turmas][contaluno][0]);
			for(int bimestre = 0;bimestre < 4;bimestre++){
				printf("\nDigite a nota do %iº bimestre do aluno:",bimestre+1);
				scanf("%f",&notas[contaluno][bimestre][turmas]);
			}		
			printf("\nDigite o numero de faltas do aluno:");
			scanf("%i",&faltas[contaluno][turmas]);
	/*----------------------------------VERIFICANDO A REPETIÇÂO--------------------------*/				
			printf("\nDeseja Adicionar mais alunos?(s ou n)");
			scanf(" %c",&op);
			contaluno++;
		}while(op != 'n');
		nalunosturma[turmas] = contaluno;
	}
	/*----------------------------------APRESENTAÇÂO DE RELATORIOS------------------------*/
	do{	
		mediadenotasgeral = 0;
		salvanota0 = 0;
		contalunosmed8 = 0;
		contalunosubstitui = 0;
		mediafinal = 0;
		printf("\nDeseja fazer a consulta por aluno ou por turma?(a ou t)");
		scanf(" %c",&op);
	/*---------------------------------------POR ALUNOS------------------------------------*/	
		if(op == 'a'){
			printf("\nDigite o Numero da turma: ");
			scanf("%i",&nturma);
			printf("\nDigite o Numero do aluno:");	
			scanf("%i",&naluno);
	/*-------------------------------VERIFICADOR DE NUMERO DO ALUNO------------------------*/			
			while(naluno-1 >= nalunosturma[nturma-1]){
				printf("\nNumero de aluno invalido!\n");
				printf("\nDigite o Numero do aluno:");	
				scanf("%i",&naluno);
			}
	/*-----------------------------------CALCULANDO MEDIA FINAL----------------------------*/
			printf("Nome:%s\n",nome[nturma-1][naluno-1]);	
			for(int bimestre = 0;bimestre < 4;bimestre++){
				printf("\nNota %iº bimestre: %.2f\n",bimestre+1,notas[naluno-1][bimestre][nturma-1]);
				mediafinal = mediafinal + notas[naluno-1][bimestre][nturma-1];
			}
			printf("\nMedia Final: %.2f\n",mediafinal/4);
			printf("\nFrequencia: %i faltas\n",faltas[naluno-1][nturma-1]);
	/*-----------------------------------TIPO DE APROVAÇÂO---------------------------------*/		
			if(faltas[naluno-1][nturma-1] > 10){
				printf("\nReprovado por Falta!\n");
			}else if(mediafinal/4 < 5){
				printf("\nReprovado por Nota!\n");
			}else if(mediafinal/4 > 7){
				printf("\nAprovado!\n");
			}else{
				printf("\nFara substitutiva!\n");
			}
	/*---------------------------------------POR TURMA-------------------------------------*/			
		}else{
			printf("\nDigite o Numero da turma: ");
			scanf("%i",&nturma);
			printf("\nNumero de alunos da turma: %i\n",nalunosturma[nturma-1]);
	/*-------------------------------------CONTANDO ALUNOS --------------------------------*/		
			for(int al = 0;al<nalunosturma[nturma-1];al++){
				mediafinal = 0;
				contalunosnota0 = 0;
				for(int bimestre = 0;bimestre<4;bimestre++){
					mediafinal = mediafinal + notas[al][bimestre][nturma-1];
					if(notas[al][bimestre][nturma-1] == 0){
						contalunosnota0 = 1;
					}
				}
				mediadenotasgeral = mediadenotasgeral+(mediafinal/4);
				salvanota0 = salvanota0 + contalunosnota0;
				if(mediafinal/4 > 8){
					contalunosmed8++;
				}
				if(mediafinal/4 > 5 && mediafinal/4 < 7){
					contalunosubstitui++;
				}
			}
	/*-------------------------------------IMPRIMINDO DADOS --------------------------------*/		
			printf("\nNumero de alunos com media final acima de 8: %i\n",contalunosmed8);
			printf("\nNumero de alunos com algum 0 em suas notas: %i\n",salvanota0);
			printf("\nNumero de alunos que farao substutiva: %i\n",contalunosubstitui);
			printf("\nMedia Geral da Turma: %.2f\n",mediadenotasgeral/nalunosturma[nturma-1]);
		}
	/*-------------------------------VERIFICANDO A REPETIÇÂO--------------------------------*/		
			printf("\nDeseja ver outro relatorio?(s ou n)");
			scanf(" %c",&op);
	}while(op != 'n');
	return;
}