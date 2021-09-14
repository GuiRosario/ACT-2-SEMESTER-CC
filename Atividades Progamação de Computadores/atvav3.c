#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
  FILE *arq;
  char Linha[1000];
  char Linha1[1000] = "";
  char *pt;
  int res;
  char p1[100];
  char p2[100];
  arq = fopen("myfile.txt", "rt");
  if (arq == NULL)
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }else{
    scanf("%s",p1);
    scanf("%s",p2);
    while(1){
      fgets(Linha,sizeof(Linha),arq);
      strcat(Linha1,Linha);
      if(feof(arq)){
          break;
      }   
    }
    pt = strtok(Linha1," ");
    fclose(arq);
    arq = fopen("myfile.txt","w");
    while(pt){
      res = strcmp(pt,p1);
      if(res == 0){
          fprintf(arq,"%s ",p2);
      }else{
          fprintf(arq,"%s ",pt);
      }
      pt = strtok(NULL, " ");
    }
  }
  fclose(arq);
  return;
}
