#include <stdio.h>

int main(void) {
    int vet[15];
    int save;
    for(int ler = 0;ler < 15;ler++){
        scanf("%i",&vet[ler]);
    }
    for(int rep = 0;rep < 15;rep++){
        for(int org = 0;org < 14;org++){
            if(vet[org] > vet[org + 1]){
            save = vet[org];
            vet[org] = vet[org+1];
            vet[org+1] = save;
            }
        }      
    }

    for(int imp = 0;imp < 15;imp++){
        printf("%i ",vet[imp]);
    }
    printf("\n");

    return 0;
}