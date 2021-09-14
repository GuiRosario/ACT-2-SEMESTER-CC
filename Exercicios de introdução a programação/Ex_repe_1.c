#include <stdio.h>


void main(){
	float n1,n2,media;


	for(int x = 1;x<=10;x++){
		scanf("%f %f",&n1,&n2);
		media = (n1+n2)/2;
		if(media >= 7){
			printf("Passou direto!");
		}else{
			printf("Nao passou direto!");
		}
		printf("Media Final: %.2f",media);
	}
	return;
}