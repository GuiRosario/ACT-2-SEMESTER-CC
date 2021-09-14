#include <stdio.h>									
#include<stdlib.h>																					
void posiciona(char **nav,int jogador);		
void mostratabuleiro(char **nav1);
void atira(char **nav1,char **nav2,char **tir1,char **tir2);

char CD(char coluna){
    int col;
    char letras[20] = {'A','B','C','D','E','F','G','H','I','J','a','b','c','d','e','f','g','h','i','j'};
    for(int i = 0;i<20;i++){
        if(coluna == letras[i]){
            if(i > 9) col = i-10;
            else col = i;
        }
    }
    return col;
}

int main() 														
{
	char **navios1,**navios2,**tiros1,**tiros2;
	int j,k;
	
	printf("Inicia Jogo \n\n");
	
	navios1=(char **)malloc(10*sizeof(char *));
	navios2=(char **)malloc(10*sizeof(char *));
	tiros1=(char **)malloc(10*sizeof(char *));
	tiros2=(char **)malloc(10*sizeof(char *));
	
		
	for(j=0;j<10;j++)
	{
		navios1[j]=(char *)malloc(10*sizeof(char));
		navios2[j]=(char *)malloc(10*sizeof(char));
		tiros1[j]=(char *)malloc(10*sizeof(char));
		tiros2[j]=(char *)malloc(10*sizeof(char));
		
		for(k=0;k<10;k++)
		{
			navios1[j][k]='-';
			navios2[j][k]='-';
			tiros1[j][k]='-';
			tiros2[j][k]='-';
		}
	}
	
	printf("Posiciona navios Jogador 1\n\n");
	posiciona(navios1,1);
	
	printf("\n");
	printf("Posiciona navios Jogador 2\n\n");
	posiciona(navios2,2);
	
	printf("\n\n");
	printf("Inicia os tiros\n");	
	atira(navios1,navios2,tiros1,tiros2);
	
	return 0;
}


void posiciona(char **nav,int jogador)
{
	int linha,lin,col,i=0,j,l,c,flag,sinal,sinal1,sinal2;
	char coluna,direcao,tiponav;
	
	printf("Entre com as coordenadas para posicionamento dos navios: Linha->1-10 Coluna->A-J");
	
	printf("Jogador %d\n",jogador);	
	mostratabuleiro(nav);
	
	while(i<5)
	{
		sinal=0;
		while(sinal!=1)
		{
			printf("Entre com a linha=");
			scanf("%d",&linha);
			if(linha<=10&&linha>=1)
				sinal=1;
			else
				printf("Linha invalida - Entre linha novamente\n");
		}
		
		sinal1=0;
		while(sinal1!=1)
		{
			printf("Entre com a coluna=");
			scanf("%s",&coluna);
			printf("\n");
			if(coluna=='A'||coluna=='a'||coluna=='B'||coluna=='b'||coluna=='C'||coluna=='c'||coluna=='D'||coluna=='d'||coluna=='E'||coluna=='e'||coluna=='F'||coluna=='f'||coluna=='G'||coluna=='g'||coluna=='H'||coluna=='h'||coluna=='I'||coluna=='i'||coluna=='J'||coluna=='j')
				sinal1=1;
			else
				printf("Coluna invalida - Entre coluna novamente\n");
		}
					
		lin=linha-1;

        col = CD(coluna);
										
		printf("Entre com a direcao: h-horizontal v-vertical\n");
		scanf("%s",&direcao);
		printf("\n");
		
		if(direcao=='h'||direcao=='H')				
		{
			flag=0;//Posicao horizontal
			
			sinal2=0;
			while(sinal2!=1)
			{
				printf("Entre com o tipo de navio: P-porta aviao G-navio de guerra C-cruzador S-submarino D-destruidor\n");
				scanf("%s",&tiponav);
				printf("\n");
				if(tiponav=='P'||tiponav=='p'||tiponav=='G'||tiponav=='g'||tiponav=='C'||tiponav=='c'||tiponav=='S'||tiponav=='s'||tiponav=='D'||tiponav=='d')
					sinal2=1;
				else
					printf("Navio invalido - Entre navio novamente\n");
			}
					
					
			if(tiponav=='P'||tiponav=='p')
				if(col>5)
					printf("Porta aviao ficou fora do tabuleiro so pode usar A-F\n");
				else
				{
					for(j=0;j<5;j++)
					{
						if(nav[lin][col+j]!='-')
							flag=1;
					}
						
					if(flag==1)
						printf("posicao ocupada por Navio\n");
					else
					{
						for(j=0;j<5;j++)
							nav[lin][col+j]='P';
								
						i=i+1;
						printf("Jogador %d\n",jogador);								
						mostratabuleiro(nav);
					}
				}
			else
				if(tiponav=='G'||tiponav=='g')
					if(col>6)
						printf("Navio de Guerra ficou fora do tabuleiro so pode usar A-G\n");
					else
					{
						for(j=0;j<4;j++)
						{
							if(nav[lin][col+j]!='-')
								flag=1;
						}
						
						if(flag==1)
							printf("posicao ocupada por Navio\n");
						else
						{
							for(j=0;j<4;j++)
								nav[lin][col+j]='G';
										
							i=i+1;
							printf("Jogador %d\n",jogador);	
							mostratabuleiro(nav);
						}
					}
				else
					if(tiponav=='C'||tiponav=='c')
						if(col>7)
							printf("Cruzador ficou fora do tabuleiro so pode usar A-H\n");
						else
						{
							for(j=0;j<3;j++)
							{
								if(nav[lin][col+j]!='-')
									flag=1;
							}
							
							if(flag==1)
								printf("posicao ocupada por Navio\n");
							else
							{
								for(j=0;j<3;j++)
							  		nav[lin][col+j]='C';
									
								i=i+1;
								printf("Jogador %d\n",jogador);
								mostratabuleiro(nav);
							}
						}
					else
						if(tiponav=='S'||tiponav=='s')
							if(col>7)
								printf("Submarino ficou fora do tabuleiro so pode usar A-H\n");
							else
								{
									for(j=0;j<3;j++)
									{
										if(nav[lin][col+j]!='-')
											flag=1;
									}
									
									if(flag==1)
										printf("posicao ocupada por Navio\n");
									else
									{
										for(j=0;j<3;j++)
											nav[lin][col+j]='S';
										
										i=i+1;
										printf("Jogador %d\n",jogador);
										mostratabuleiro(nav);
									}
								}
						else
							if(tiponav=='D'||tiponav=='d')
								if(col==9)
									printf("Destruidor ficou fora do tabuleiro so pode usar A-I\n");
								else
									{
										for(j=0;j<2;j++)
										{
											if(nav[lin][col+j]!='-')
												flag=1;
										}
										
										if(flag==1)
											printf("posicao ocupada por Navio\n");
										else
										{
											for(j=0;j<2;j++)
												nav[lin][col+j]='D';
											
											i=i+1;
											printf("Jogador %d\n",jogador);
											mostratabuleiro(nav);
										}
									}
		}
		else
			{
				flag=0;//Posicao vertical
				
				sinal2=0;
				while(sinal2!=1)
				{
					printf("Entre com o tipo de navio: P-porta aviao G-navio de guerra C-cruzador S-submarino D-destruidor\n");
					scanf("%s",&tiponav);
					printf("\n");
					if(tiponav=='P'||tiponav=='p'||tiponav=='G'||tiponav=='g'||tiponav=='C'||tiponav=='c'||tiponav=='S'||tiponav=='s'||tiponav=='D'||tiponav=='d')
						sinal2=1;
					else
						printf("Navio invalido - Entre navio novamente \n");
				}
				
				if(tiponav=='P'||tiponav=='p')
					if(lin>5)
						printf("Porta aviao ficou fora do tabuleiro so pode usar linha de 1-6\n");
					else
					{
						for(j=0;j<5;j++)
						{
							if(nav[lin+j][col]!='-')
								flag=1;
						}
								
						if(flag==1)
							printf("posicao ocupada por Navio\n");
						else
						{
							for(j=0;j<5;j++)
								nav[lin+j][col]='P';
								
							i=i+1;
							printf("Jogador %d\n",jogador);
							mostratabuleiro(nav);
						}
					}
				else
					if(tiponav=='G'||tiponav=='g')
						if(lin>6)
							printf("Navio de Guerra ficou fora do tabuleiro so pode usar linha 1=7\n");
						else
						{
							for(j=0;j<4;j++)
							{
								if(nav[lin+j][col]!='-')
									flag=1;
							}
								
							if(flag==1)
								printf("posicao ocupada por Navio\n");
							else
							{
								for(j=0;j<4;j++)
									nav[lin+j][col]='G';
									
								i=i+1;
								printf("Jogador %d\n",jogador);
								mostratabuleiro(nav);
							}
						}
					else
						if(tiponav=='C'||tiponav=='c')
							if(lin>7)
								printf("Cruzador ficou fora do tabuleiro so pode usar linha de 1-8\n");
							else
							{
								for(j=0;j<3;j++)
								{
									if(nav[lin+j][col]!='-')
										flag=1;
								}
								
								if(flag==1)
									printf("posicao ocupada por Navio\n");
								else
								{
									for(j=0;j<3;j++)
										nav[lin+j][col]='C';
										
									i=i+1;
									printf("Jogador %d\n",jogador);
									mostratabuleiro(nav);
								}
							}
						else
							if(tiponav=='S'||tiponav=='s')
								if(lin>7)
									printf("Submarino ficou fora do tabuleiro so pode usar linha de 1-8\n");
								else
								{
									for(j=0;j<3;j++)
									{
										if(nav[lin+j][col]!='-')
											flag=1;
									}
								
									if(flag==1)
										printf("posicao ocupada por Navio\n");
									else
									{
										for(j=0;j<3;j++)
											nav[lin+j][col]='S';
											
										i=i+1;
										printf("Jogador %d\n",jogador);
										mostratabuleiro(nav);
									}
								}
							else
								if(tiponav=='D'||tiponav=='d')
									if(lin==9)
										printf("Destruidor ficou fora do tabuleiro so pode usar linha de 1-9\n");
									else
									{
										for(j=0;j<2;j++)
										{
											if(nav[lin+j][col]!='-')
												flag=1;
										}
								
										if(flag==1)
											printf("posicao ocupada por Navio\n");
										else
										{
											for(j=0;j<2;j++)
												nav[lin+j][col]='D';
												
											i=i+1;
											printf("Jogador %d\n",jogador);
											mostratabuleiro(nav);
										}
									}
			}
		
		
	}
}

void mostratabuleiro(char **navio)
{
	int l,c;
	printf("   A B C D E F G H I J\n");
	for(l=0;l<10;l++)
	{
		printf("%d",l+1);
												
		if((l+1)!=10)
			printf("  ");
		else
			printf(" ");
													
		for(c=0;c<10;c++)
			printf("%c ",navio[l][c]);
											
		printf("\n");
	}
}


void atira(char **nav1,char **nav2,char **tir1,char **tir2)
{
	int linha11,linha21,linha31,lin11,lin21,lin31,col11,col21,col31,lin,col,cont,teste;
	int linha12,linha22,linha32,lin12,lin22,lin32,col12,col22,col32,sinal,sinal1;
	int afundoutudo=0,navafund1=0,navafund2=0;
	char coluna11,coluna21,coluna31,coluna12,coluna22,coluna32;
	
	while(afundoutudo!=1)
	{
		printf("jogador 1\n");
		mostratabuleiro(nav1);
		printf("\n");
		mostratabuleiro(tir1);
		printf("Navios Afundados = %d\n\n",navafund1);
		
		printf("Marque o tiro da seguinte forma: O-agua X-fogo A-afundou\n");
		
		printf("Entre com as coordenadas dos tres tiros\n\n");
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do primeiro tiro\n");
				printf("linha11=");
				scanf("%d",&linha11);
				if(linha11>=1&&linha11<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
				
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna11=");
				scanf("%s",&coluna11);
				printf("\n");
				if(coluna11=='A'||coluna11=='a'||coluna11=='B'||coluna11=='b'||coluna11=='C'||coluna11=='c'||coluna11=='D'||coluna11=='d'||coluna11=='E'||coluna11=='e'||coluna11=='F'||coluna11=='f'||coluna11=='G'||coluna11=='g'||coluna11=='H'||coluna11=='h'||coluna11=='I'||coluna11=='i'||coluna11=='J'||coluna11=='j')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
			
			lin11=linha11-1;
            col11 = CD(coluna11);
																	
			if((tir1[lin11][col11]=='A')||(tir1[lin11][col11]=='X')||(tir1[lin11][col11]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin11][col11]=='-')
					tir1[lin11][col11]='O';
				else
					tir1[lin11][col11]='X';
				teste=1;
			}
															
		}
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do segundo tiro\n");
				printf("linha21=");
				scanf("%d",&linha21);
				if(linha21>=1&&linha21<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
			
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna21=");
				scanf("%s",&coluna21);
				printf("\n");
				if(coluna21=='A'||coluna21=='a'||coluna21=='B'||coluna21=='b'||coluna21=='C'||coluna21=='c'||coluna21=='D'||coluna21=='d'||coluna21=='E'||coluna21=='e'||coluna21=='F'||coluna21=='f'||coluna21=='G'||coluna21=='g'||coluna21=='H'||coluna21=='h'||coluna21=='I'||coluna21=='i'||coluna21=='J'||coluna21=='j')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
			
			lin21=linha21-1;
            col21 = CD(coluna21);
													
			if((tir1[lin21][col21]=='A')||(tir1[lin21][col21]=='X')||(tir1[lin21][col21]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin21][col21]=='-')
					tir1[lin21][col21]='O';
				else
					tir1[lin21][col21]='X';
				teste=1;
			}
		}
		
		teste=0;
		while(teste==0)
		{
			sinal=0;
			while(sinal==0)
			{
				printf("Entre com a linha e a coluna do terceiro tiro\n");
				printf("linha31=");
				scanf("%d",&linha31);
				if(linha31>=1&&linha31<=10)
					sinal=1;
				else
					printf("linha invalida - Entre linha novamente\n");
			}
			
			sinal1=0;
			while(sinal1==0)	
			{
				printf("coluna31=");
				scanf("%s",&coluna31);
				printf("\n");
				if(coluna31=='A'||coluna31=='a'||coluna31=='B'||coluna31=='b'||coluna31=='C'||coluna31=='c'||coluna31=='D'||coluna31=='d'||coluna31=='E'||coluna31=='e'||coluna31=='F'||coluna31=='f'||coluna31=='G'||coluna31=='g'||coluna31=='H'||coluna31=='h'||coluna31=='I'||coluna31=='i'||coluna31=='J'||coluna31=='j')
					sinal1=1;
				else
					printf("Coluna invalida - Entre coluna novamente\n");
			}
					
			lin31=linha31-1;
            col31 = CD(coluna31);
													
			if((tir1[lin31][col31]=='A')||(tir1[lin31][col31]=='X')||(tir1[lin31][col31]=='O'))											
				printf("Posicao ocupada - tente novamente\n");
			else
			{
				if(nav2[lin31][col31]=='-')
					tir1[lin31][col31]='O';
				else
					tir1[lin31][col31]='X';
				teste=1;
			}
		}
		
       	cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='C'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==3)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='C')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
		
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='S'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==3)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='S')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
						
		cont=0;
		for(lin=0;lin<10;lin++)		
			for(col=0;col<10;col++)
				if(nav2[lin][col]=='D'&&tir1[lin][col]=='X')
					cont=cont+1;
		if(cont==2)
		{
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav2[lin][col]=='D')
						tir1[lin][col]='A';
			navafund1=navafund1+1;
		}
		
		printf("jogador 1\n");
		mostratabuleiro(nav1);
		printf("\n");			
		mostratabuleiro(tir1);
		printf("Navios Afundados = %d\n\n",navafund1);
		
		if(navafund1==5)
		{
			afundoutudo=1;
			printf("O jogador 1 e o vencedor\n");
		}
		
		
		if(afundoutudo!=1)
		{
			printf("jogador 2\n");
			mostratabuleiro(nav2);
			printf("\n");
			mostratabuleiro(tir2);
			printf("Navios Afundados = %d\n\n",navafund2);
			
			printf("Marque o tiro da seguinte forma: O-agua X-fogo A-afundou\n");
			
			printf("Entre com as coordenadas dos tres tiros\n");
			
			teste=0;
			while(teste==0)
			{
				sinal=0;
				while(sinal==0)
				{
					printf("Entre com a linha e a coluna do primeiro tiro\n");
					printf("linha12=");
					scanf("%d",&linha12);
					if(linha12>=1&&linha12<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna12=");
					scanf("%s",&coluna12);
					printf("\n");
					if(coluna12=='A'||coluna12=='a'||coluna12=='B'||coluna12=='b'||coluna12=='C'||coluna12=='c'||coluna12=='D'||coluna12=='d'||coluna12=='E'||coluna12=='e'||coluna12=='F'||coluna12=='f'||coluna12=='G'||coluna12=='g'||coluna12=='H'||coluna12=='h'||coluna12=='I'||coluna12=='i'||coluna12=='J'||coluna12=='j')
						sinal1=1;
					else
						printf("Coluna invalida - Entre coluna novamente\n");
				}
				
				lin12=linha12-1;
                col12 = CD(coluna12);
				if((tir2[lin12][col12]=='A')||(tir2[lin12][col12]=='X')||(tir2[lin12][col12]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin12][col12]=='-')
						tir2[lin12][col12]='O';
					else
						tir2[lin12][col12]='X';
					teste=1;
				}
			}
			
			teste=0;
			while(teste==0)
			{
				sinal=0;
				while(sinal==0)
				{
					printf("Entre com a linha e a coluna do segundo tiro\n");
					printf("linha22=");
					scanf("%d",&linha22);
					if(linha22>=1&&linha22<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna22=");
					scanf("%s",&coluna22);
					printf("\n");
					if(coluna22=='A'||coluna22=='a'||coluna22=='B'||coluna22=='b'||coluna22=='C'||coluna22=='c'||coluna22=='D'||coluna22=='d'||coluna22=='E'||coluna22=='e'||coluna22=='F'||coluna22=='f'||coluna22=='G'||coluna22=='g'||coluna22=='H'||coluna22=='h'||coluna22=='I'||coluna22=='i'||coluna22=='J'||coluna22=='j')
						sinal1=1;
					else
						printf("Coluna invalida - Entre coluna novamente\n");
				}
				
				lin22=linha22-1;
                col = CD(coluna22);
														
				if((tir2[lin22][col22]=='A')||(tir2[lin22][col22]=='X')||(tir2[lin22][col22]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin22][col22]=='-')
						tir2[lin22][col22]='O';
					else
						tir2[lin22][col22]='X';
					teste=1;
				}
			}
			
			teste=0;
			while(teste==0)
			{
				sinal=0;
				while(sinal==0)
				{
					printf("Entre com a linha e a coluna do terceiro tiro\n");
					printf("linha32=");
					scanf("%d",&linha32);
					if(linha32>=1&&linha32<=10)
						sinal=1;
					else
						printf("linha invalida - Entre linha novamente\n");
				}
				
				sinal1=0;
				while(sinal1==0)	
				{
					printf("coluna32=");			
					scanf("%s",&coluna32);
					printf("\n");
					if(coluna32=='A'||coluna32=='a'||coluna32=='B'||coluna32=='b'||coluna32=='C'||coluna32=='c'||coluna32=='D'||coluna32=='d'||coluna32=='E'||coluna32=='e'||coluna32=='F'||coluna32=='f'||coluna32=='G'||coluna32=='g'||coluna32=='H'||coluna32=='h'||coluna32=='I'||coluna32=='i'||coluna32=='J'||coluna32=='j')
						sinal1=1;
					else
						printf("Coluna invalida - Entre coluna novamente\n");
				}
						
				lin32=linha32-1;
                col32 = CD(coluna32);

				if((tir2[lin32][col32]=='A')||(tir2[lin32][col32]=='X')||(tir2[lin32][col32]=='O'))											
					printf("Posicao ocupada - tente novamente\n");
				else
				{
					if(nav1[lin32][col32]=='-')
						tir2[lin32][col32]='O';
					else
						tir2[lin32][col32]='X';
					teste=1;
				}
			}

           	cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='G'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==4)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='G')
							tir2[lin][col]='A';		
				navafund2=navafund2+1;
			}
			
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='C'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==3)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='C')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
			
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='S'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==3)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='S')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}
							
			cont=0;
			for(lin=0;lin<10;lin++)		
				for(col=0;col<10;col++)
					if(nav1[lin][col]=='D'&&tir2[lin][col]=='X')
						cont=cont+1;
			if(cont==2)
			{
				for(lin=0;lin<10;lin++)		
					for(col=0;col<10;col++)
						if(nav1[lin][col]=='D')
							tir2[lin][col]='A';
				navafund2=navafund2+1;
			}		
		
			printf("jogador 2\n");
			mostratabuleiro(nav2);
			printf("\n");			
			mostratabuleiro(tir2);
			printf("Navios Afundados = %d\n\n",navafund2);
			
			if(navafund2==5)
			{
				afundoutudo=1;
				printf("O jogador 2 e o vencedor\n");
			}
					
		}
			
		
	}
}