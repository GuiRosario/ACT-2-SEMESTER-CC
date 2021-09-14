#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int m[3][3];
    int determinante;
    for(int l = 0;l<3;l++){
        for(int c = 0;c<3;c++){
            scanf("%i",&m[l][c]);
        }
    }
    determinante = m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1] - (m[0][2]*m[1][1]*m[2][0] + m[0][0]*m[1][2]*m[2][1] + m[0][1]*m[1][0]*m[2][2]);

    printf("Determinante: %i",determinante);
    
	return 0;
}