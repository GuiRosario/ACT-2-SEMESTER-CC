#include <stdio.h>

int main(void) {
    int T;
    long long int F[61];
    F[0] = 0;
    F[1] = 1;
    scanf("%i",&T);
    int N[T];

    for(int coleta = 0;coleta < T;coleta++){
        do{
            scanf("%i",&N[coleta]);
    

        }while(N[coleta] > 60 || N[coleta] < 0);
        
    }

    for(int calc = 0;calc < T;calc++){
         for(int fibo = 2;fibo <= N[calc];fibo++){  
             F[fibo] = F[fibo-1] + F[fibo-2];    
         }
         printf("Fib(%i) = %lld\n",N[calc],F[N[calc]]);
    }

    return 0;
}