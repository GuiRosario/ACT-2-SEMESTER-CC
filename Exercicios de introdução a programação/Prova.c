#include <stdio.h>

void main(){
	int num_livro,maior_pedid,livro_seg,incen_fiscal;	
	int livro_fund = 0;
	int livro_medi = 0;
	int livro_sup = 0;
	int nincen_fiscal = 0;
	int cont_pedid = 0;
	int incen_fiscal20 = 0;
	float media_livro = 0;
	char op_fiscal;

	printf("Quantos livros teve esse pedido?\n");
	scanf("%i",&num_livro);
	maior_pedid = num_livro;
	do{
		incen_fiscal = 0;
		media_livro = media_livro + num_livro;
		cont_pedid++;
		for(int x = 1;x <= num_livro;x++){
			printf("Qual o segmento do livro?LIVRO NUMERO: %i (Fundamental,medio,superior => 1,2,3 respectivamente)\n",x);
			scanf("%i",&livro_seg);
			if(livro_seg == 1){
				livro_fund++;
			}else if(livro_seg == 2){
				livro_medi++;
			}else{
				livro_sup++;
			}
			printf("O livro teve incentivo fiscal?LIVRO NUMERO: %i (s ou n)\n",x);
			scanf(" %c",&op_fiscal);
			if(op_fiscal == 's'){
				incen_fiscal++;
			}else{
				nincen_fiscal++;
			}
		}
		if(incen_fiscal > 20){
			incen_fiscal20++;
		}
		if(num_livro > maior_pedid){
			maior_pedid = num_livro;
		}
		printf("Quantos livros teve esse pedido?\n");
		scanf("%i",&num_livro);
	}while(num_livro != -1);

	printf("Porcentagem de livros fundamental: %.2f\n",(livro_fund*100)/media_livro);
	printf("Porcentagem de livros medio: %.2f\n",(livro_medi*100)/media_livro);
	printf("Porcentagem de livros superior: %.2f\n",(livro_sup*100)/media_livro);
	printf("Total de livros que não receberam incentivo fiscal: %i\n",nincen_fiscal);
	printf("Media de livros por pedido no periodo: %.2f\n",media_livro/cont_pedid);
	printf("Quantos pedidos tiveram mais de 20 livros com incentivo fiscal: %i\n",incen_fiscal20);
	printf("Quantos livros tinha o maior pedido: %i\n",maior_pedid);

	return;
}