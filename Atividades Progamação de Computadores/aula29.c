#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
    FILE *p;
    int n = 0;
    p = fopen("myfile.txt","w");
    
    if(p!= NULL)
    {
        fputs("exemplo de fopen",p);
    }
    return 0;
}
*/

/*
int main()
{
    FILE *p;
    int n = 0;
    p = fopen("myfile.txt","rb");
    
    if(p== NULL)
    {
        perror("Erro ao abrir o arquivo");
    }else{
        while(fgetc(p)!=EOF)
        {
            n++;
        }
    if(feof(p))
    {
        puts("Final do arquivo");
        printf("Total de bytes lidos:%i\n",n);
    }else{
        puts("Final do arquivo atingido");
        fclose(p);
        }
    }    
    return 0;
}
*/
/*
int main()
{
    FILE *p;
    char str[256];

    printf("Informe a string \n");
    fgets(str,256,stdin);
    p = fopen("myfile.txt","a");
    fputs(str,p);
    fclose(p);
    return 0;
}
*/
/*
int main()
{   
    FILE *p;    
    int n;
    char name[100];
    p = fopen("myfile.txt","w");
    for(n = 0;n<3;n++){
        puts("informe o nome\n");
        gets(name);
        fprintf(p,"Nome %i[%-10.10s]\n",n+1,name);
    }
    fclose(p);
    return 0;
}
*/
/*
int main()
{   
    FILE *p;    
    char str[80];
    float f;
    char name[100];
    p = fopen("myfile.txt","w+");
    fprintf("%f %s",3.1416,"PI");
    rewind(p);
    fscanf(p,"%f",&f);
    fscanf(p,"%s",str);
    fclose(p);
    printf("Lido do arquivo: %f e %s",f,str);
    return 0;
}
*/
/*
int main()
{   
    FILE *p;    
    char str[100];
    p = fopen("myfile.txt","r");
    if(p == NULL)
    {
        perror("Erro ao abrir o arquivo");
    }
    else{
        if(fgets(str,100,p) !=NULL)
        {
            puts(str);
            fclose(p);
        }
    }
    return 0;
}
*/
/*
int main()
{      
    freopen('myfile.txt',"w",stdout);
    printf("Redirecionamento do aquivo");
    fclose(p);
    return 0;
}
*/