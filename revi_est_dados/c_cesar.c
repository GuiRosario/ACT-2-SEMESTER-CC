#include <stdio.h>
#include <string.h>

int main(){
    int N;
    scanf("%i",&N);
    char C[N][51];
    int P[N];
    int t;
    int loc;
    char abc[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for(int i = 0;i<N;i++){
        for(int init = 0;init < 51;init++){
            C[i][init] = 0;
        }
        scanf("%s",C[i]);
        scanf("%i",&P[i]);
        t = strlen(C[i]);
        for(int c = 0;c<t;c++){
            for(int alfa = 0;alfa < 26;alfa++){
                if(C[i][c] == abc[alfa]){
                    if(alfa - P[i] < 0){
                        loc = 26 + (alfa - P[i]);
                    }else{
                        loc = (alfa - P[i]);
                    }
                }
            }
            C[i][c] = abc[loc];
        }
        printf("%s\n",C[i]);
    }
return 0;
}