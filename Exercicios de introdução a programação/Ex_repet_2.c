#include <stdio.h>


void main(){
	float n1,n2,media,mediag,maiorn;

	mediag = 0;
	maiorn = 0;

	for(int x = 1;x<=10;x++){
		scanf("%f %f",&n1,&n2);
		media = (n1+n2)/2;
		mediag = media + mediag;
		if(media >= 7){
			printf("Passou direto!\n");
		}else{
			printf("Nao passou direto!\n");
		}
		printf("Media Final: %.2f\n",media);
		if(media >= maiorn){
			maiorn = media;
		}
	}
		printf("Maior Nota: %.2f\n",maiorn);
		printf("Media geral da turma: %.2f\n",mediag/10);
	return;
}