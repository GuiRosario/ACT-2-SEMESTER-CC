#include <stdio.h>
#include <stdlib.h>

void main(){
	char nome[6][30][30];
	scanf(" %s",&nome[0][0][0]);
	scanf(" %s",&nome[1][0][0]);
	scanf(" %s",&nome[0][1][0]);
	printf("%s",nome[0][1]);
	printf("%s",nome[1][0]);
	return;
}