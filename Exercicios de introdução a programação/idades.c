/*
Universidade Federal do Tocantins
Aluno: Guilherme da Silva Rosario
Data: 16/04/2021

Ler a idade de 50 pessoas, mostrar a média das idades, 
o número de pessoas com idade abaixo da média, 
porcentagem de menores de idade e a idade do mais velho.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void main(){
/*---------------------------Habilitando a acentuação-------------------------*/	
	setlocale(LC_ALL, "Portuguese");
/*----------------------------Declaração de Variáveis-------------------------*/
	int idade[50],npam = 0,imv,clid,mi = 0;
	float midade,pmi,midaderes;
/*---------------------------Coleta de Dados----------------------------------*/
	printf("Idade 1:");
	scanf("%i",&idade[0]);
	imv = idade[0] = midade;
	if(idade[0] < 18) mi++;

	for(clid = 1;clid < 50;clid++){
		system("clear");
		printf("Idade %i:",clid+1);
		scanf("%i",&idade[clid]);
		midade += idade[clid];
		if(idade[clid] < 18) mi++;
		if(idade[clid] > imv) imv = idade[clid];
	}
	pmi = mi;
/*---------------Contando o Número de Pessoas com idade abaixo da média------*/
	midaderes = midade/50;
	for(clid = 0;clid<50;clid++){
		if(midaderes > idade[clid]) npam++;
	}
/*-----------------------------Imprimindo as saídas--------------------------*/
	system("clear");
	printf("|Média das idades:               %*.2f|\n",10,midaderes);
	printf("|Pessoas com idade abaixo da média:%*i|\n",10,npam);
	printf("|Porcentagem de menores de idade:%*.2f|\n",10,(pmi*100)/50);
	printf("|Idade do mais velho:              %*i|\n",10,imv);

	return;
}