#include <stdio.h>
#include <stdlib.h>

int main(){
	int idade,n_oxi,frq_card,m_frqcard,cont,cont_medoxi96,cont_idade16,cont_idade25;
	float med_oxi;
	cont = 0;
	cont_medoxi96 = 0;
	cont_idade25 = 0;
	cont_idade16 = 0;
	for(int x = 1;x < 11;x++){
		med_oxi = 0;
		cont = 0;
		printf("Qual a idade:");
		scanf("%i",&idade);
		printf("Registre o nivel de oxigenio!(-1 para sair):");
		scanf("%i",&n_oxi);
		do{
			med_oxi = med_oxi + n_oxi;
			cont++;
			printf("Registre o nivel de oxigenio!(-1 para sair):");
			scanf("%i",&n_oxi);
		}while(n_oxi != -1);
		printf("\n\n");
		printf("Registre a frequencia cardiaca da semana 1:");
		scanf("%i",&m_frqcard);
		for(int s = 2;s<9;s++){
			printf("Registre a frequencia cardiaca da semana %i:",s);
			scanf("%i",&frq_card);
			if(frq_card > m_frqcard) m_frqcard = frq_card;
		}
		if(med_oxi/cont < 96){
			cont_medoxi96++;
		}
		if(idade > 25){
			cont_idade25++;
		}else if(idade < 16);
			cont_idade16++;
		printf("\n\n");
		printf("Atleta Número:%i\n",x);
		printf("Media de Nivel Oxigenio no sangue:%.2f\n",med_oxi/cont);
		printf("Maior frequencia cardiaca registrada:%i\n",m_frqcard);
	}
	printf("\n\n");
	printf("\nQuantidade de Atletas com media de oxigenio no sangue abaixo de 96:%i",cont_medoxi96);
	printf("\nPorcentagem de atletas com mais de 25 anos:%i",(cont_idade25*100)/10);
	printf("\nPorcentagem de atletas com menos de 16 anos:%i",(cont_idade16*100)/10);


	return 0;
}