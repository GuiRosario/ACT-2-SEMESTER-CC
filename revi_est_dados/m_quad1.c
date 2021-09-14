#include <stdio.h>

int main()
{
    int N;
    scanf("%i",&N);
    int calc;
    int M[101][101];
    while(N != 0){
        calc = N/2;
        if(N%2 != 0){
            calc++;
        }
        for(int req = calc;req>0;req--){
            for(int l = 0;l<N;l++){
                for(int c = 0;c<N;c++){
                    if(l == req - 1 || c == req - 1 || l == N-req || c == N-req){
                        M[l][c] = req; 
                    }
                }
            }
        }
        for(int l = 0;l<N;l++){
            for(int c = 0;c<N;c++){
                if(c == 0){
                    printf("%3i",M[l][c]);
                }else{
                    printf(" %3i",M[l][c]);
                }
            } 
            printf("\n");
        }
        printf("\n");
        scanf("%i",&N);      
    }

    return 0;
}