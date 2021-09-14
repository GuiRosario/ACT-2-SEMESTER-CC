#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int Vetor[15];
    int NovoVetor[15];
	int salvar;
    int cont;
	for(int i = 0;i < 15;i++){
		scanf("%i",&Vetor[i]);

	}

	for(int x = 0;x<15;x++){
		for(int c = x;c<15;c++){
			if(Vetor[x] > Vetor[c]){
				salvar = Vetor[c];
				Vetor[c] = Vetor[x];
                Vetor[x] = salvar; 
			}
		}
	}

    salvar = 14;
    cont = 0;
    while(salvar >=0){
        if(salvar % 2 != 0){
            NovoVetor[cont] = Vetor[salvar];
            cont++;
        }
        salvar--;
    }

    salvar = 0;
    while(salvar < 15){
        if(salvar % 2 == 0){
            NovoVetor[cont] = Vetor[salvar];
            cont++;
        }
        salvar++;
    }


    for(int a = 0;a < 15;a++){
        printf("[%i] ",NovoVetor[a]);
    }


	return 0;
}