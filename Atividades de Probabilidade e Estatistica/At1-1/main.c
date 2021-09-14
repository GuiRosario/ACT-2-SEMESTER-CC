#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int arrend(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

float MaiorV(float D[],int t){
    float MaiorV;
    MaiorV = D[0];
    for(int i = 0;i<t;i++){
        if(D[i] > MaiorV){
            MaiorV = D[i];
        }
    }  

    return MaiorV;
}

float MenorV(float D[],int t){
    float MenorV;
    MenorV = D[0];
    for(int i = 0;i<t;i++){
        if(D[i] < MenorV){
            MenorV = D[i];
        }
    }
    return MenorV;
}

int fi(float D[],int t,float i,float f){
    int cont = 0;
    for(int x = 0;x<t;x++){
        if(D[x] >= i && D[x] < f){
            cont++;
        }
    }
    return cont;
}

float media(float D[],int t){
    float soma = 0;
    for(int i = 0;i<t;i++){
        soma = soma + D[i];
    }
    return soma/t;
}
float var(float D[],int t){
    float med = media(D,t);
    float soma = 0;
    for(int i = 0;i<t;i++){
        soma = soma + ((D[i] - med)*(D[i] - med));
    }
    return soma/t;
}
float dp(float D[],int t){
    return sqrt(var(D,t));
}
float CV(float D[],int t){
    return (dp(D,t)/media(D,t))*100;
}
float mediana(float D[],int t){
    float save;
    for(int i = 0;i<t;i++){
        for(int x = i;x<t;x++){
            if(D[i]>D[x]){
                save = D[i];
                D[i] = D[x];
                D[x] = save;
            }
        }
    }

    if(t%2 == 0){
        return (D[(t/2)-1] + D[(t/2)])/2;
    }else{
        return D[arrend(t/2)];
    }
}

float moda(float D[],int t){
    int cont[t];
    
    for(int i = 0;i<t;i++){
        cont[i] = 0;
        for(int x = 0;x<t;x++){
            if(D[i] == D[x]){
                cont[i]++;
            }
        }
    }
    int MaiorV;
    MaiorV = cont[0];
    for(int i = 0;i<t;i++){
        if(cont[i] > MaiorV){
            MaiorV = cont[i];
        }
    }  
    return D[MaiorV];
}


float amp(float D[],int t){
    return MaiorV(D,t) - MenorV(D,t);
}

void DF(float D[],int t,float amp){  
    float nc = sqrt(t);
    int flag = 0;
    float PMi;
    float sPMi = 0;
    float sfreq = 0;
    float mediafi;
    float P;
    float MD;
    float h = amp/(nc-1);
    int classes = 0;
    float maiorfreq;
    int cont = 0;
    float Modafi;
    float varfi;
    float dpfi;
    float CVfi;
    float svarfi = 0;
    float i = MenorV(D,t)-(h/2);
    float it = i;
    while(1){
        if(it>MaiorV(D,t)){
            break;
        }
        it = it+h;
        classes++;
    }
    printf("CLASSES: %i\n",classes);
    float centr[classes];
    float Vfreq[classes];
    if(t%2 == 0){
        P = (t/2 + ((t/2)+1))/2; 
    }else{
        P = arrend(t/2);
    }

    printf("|     RES     |   fi   |\n");
    while(1){
        float f = i + h;
        Vfreq[cont] =  fi(D,t,i,f);
        PMi = ((i+f)/2)*fi(D,t,i,f);
        centr[cont] = (i+f)/2;
        sPMi = PMi + sPMi;
        sfreq = sfreq + fi(D,t,i,f);
        if(sfreq >= P && flag == 0){
            MD = i + ((P - (sfreq - fi(D,t,i,f)))*(h/fi(D,t,i,f)));
            flag = 1;
        }
        printf("|%5.1f|--%5.1f|%5i   |\n",i,f,fi(D,t,i,f));
        i = f;
        if(i > MaiorV(D,t)){
            break;
        }
        cont++;
    }
    mediafi = sPMi/sfreq;
    for(int i = 0;i<classes;i++){
        varfi = ((centr[i]-mediafi)*(centr[i]-mediafi))*((Vfreq[i]*100)/t);
        svarfi = svarfi + varfi;
    }
    varfi = svarfi/100;
    dpfi = sqrt(varfi);
    CVfi = (dpfi/mediafi)*100;
    for(int i = 0;i<classes;i++){
        if(Vfreq[i] == MaiorV(Vfreq,classes)){
            Modafi = centr[i];
            break;
        }
    }
    printf("media distribuição de frequências: %.2f\n",mediafi);
    printf("mediana distribuição de frequências: %.2f\n",MD);
    printf("moda distribuição de frequências: %.2f\n",Modafi);
    printf("varianca distribuição de frequências: %.2f\n",varfi);
    printf("desvio padrao distribuição de frequências: %.2f\n",dpfi);
    printf("coeficiente de variaçao distribuição de frequências: %.2f\n",CVfi);
}


void main(){
    int t = 48;
    float Data[48] = {11.5,12.1,9.9,9.3,7.8,6.2,6.6,7.0,13.4,17.1,9.3,5.6,5.7,5.4,5.2,5.1,4.9,10.7,15.2,8.5,4.2,4.0,3.9,3.8,
3.6,3.4,20.6,25.5,13.8,12.6,13.1,8.9,8.2,10.7,14.2,7.6,
5.2,5.5,5.1,5.0,5.2,4.8,4.1,3.8,3.7,3.6,3.6,3.6};
    DF(Data,t,amp(Data,t));
    printf("media dados originais: %.2f\n",media(Data,t));
    printf("mediana dados originais: %.2f\n",mediana(Data,t));
    printf("moda dados originais: %.2f\n",moda(Data,t));
    printf("varianca dados originais: %.2f\n",var(Data,t));
    printf("desvio padrao dados originais: %.2f\n",dp(Data,t));
    printf("coeficiente de variaçao dados originais: %.2f\n",CV(Data,t));
    
    return;
}


