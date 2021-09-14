#include <stdio.h>

void main(){
	int impar[5];
	int par[5];
	int n;
	int resetpar = 0;
	int resetimpar = 0;
	for(int c = 0;c < 5;c++){
		impar[c] = 0;
		par[c] = 0;
	}

	for(int x = 0; x < 15;x++){
		scanf("%i",&n);
		if(n % 2 == 0){
			if(par[resetpar] != 0){
				for(int z = 0;z < 5;z++){
					printf("par[%i] = %i\n",z,par[z]);
					par[z] = 0;
				}
				resetpar = 0;
				par[resetpar] = n;
				resetpar++;	
			}else{
				par[resetpar] = n;	
				resetpar++;
			}

		}else{
			if(impar[resetimpar] != 0){
				for(int z = 0;z < 5;z++){
					printf("impar[%i] = %i\n",z,impar[z]);
					impar[z] = 0;
				}
				resetimpar = 0;
				impar[resetimpar] = n;
				resetimpar++;	
			}else{
				impar[resetimpar] = n;
				resetimpar++;
			}

		}
	}

	for(int z = 0;z<5;z++){
		if(impar[z]!= 0){
			printf("impar[%i] = %i\n",z,impar[z]);
		}
	}

	for(int z = 0;z<5;z++){
		if(par[z]!= 0){
			printf("par[%i] = %i\n",z,par[z]);
		}
	}

	return;
}


