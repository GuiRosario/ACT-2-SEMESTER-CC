#include <stdio.h>

int eq(int a,int b,int c){
    int delta;

    delta = (b*b) - 4*a*c;
    return delta;
}



float fatorial(int n){
    int res = 1 ;
    do{
        res = res*(n);
        n--;
    }while(n >= 1 );
    return res;
}

float funcao(float n)
{
    int i;
    float res;
    res=0;
    for(i=1;i<=n;i++)
    {
      res=res+(1/i);
    }
    return res;
}

float CF(float temp){
    float F;
    F = (temp*1.8)+32;
    return F;    
}
float FC(float temp){
    float C;
    C = (temp-32)/1.8;

}

int vet(int V[],int t,int n){
    int cont = 0;
    for(int i = 0;i<t;i++){
        if(V[i] == n){
            cont++;
        }
    }
    return cont;
}

int main()
{  
    int t,cont,n;

    printf("Qual o tamanho do vetor?");
    scanf("%i",&t);
    int V[t];
    for(int i = 0;i<t;i++){
        scanf("%i",&V[i]);
    }
    printf("Qual valor deseja verificar no vetor?");
    scanf("%i",&n);
    cont = vet(V,t,n);
    printf("O valor %i, aparece %i vezes no vetor",n,cont);
}