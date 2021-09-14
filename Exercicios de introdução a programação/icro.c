#include <stdio.h>
int main(){

//Declaração de variáveis:
char nomes[6][30][20];
int on=0, n_turma, n_aluno, tx, ay, nz, flag;
float alunos[6][30][5], turmas[6][5];

/*
Matriz das turmas:
[0]Quantidade de alunos 
[1]Alunos com média maior que 8 
[2]Alunos com alguma nota igual a 0 
[3]Alunos que farão substitutiva 
[4]Média da turma 

Matriz dos alunos:
[0]N1 
[1]N2 
[2]N3
[3]N4
[4]Frequencia
[5]Média
*/

//tx turma x
//ay alunos y
//nz notas z

for(tx=0;tx<=5;tx++)
{
    turmas[tx][0]=0;
    alunos[tx][ay][5]=0;

    printf("\n\nTurma %d", tx+1);
    for(ay=0;ay<=30;ay++)
    {
        printf("\nAluno %d\nNome: ", ay+1);
        scanf("%s", &nomes[tx][ay]);
        printf("\n\nInsira as 4 notas: ");

        for(nz=0;nz<=3;nz++)
        {
            printf("\nNota %d: ", nz+1);
            scanf("%f", &alunos[tx][ay][nz]);
            alunos[tx][ay][5]+=alunos[tx][ay][nz];
        }
        
        //Alunos com alguma nota igual a 0
        for(nz=0;nz<=3;nz++)
        {   
            if(alunos[tx][ay][nz]==0)
            {
                turmas[tx][2]++;
                break;
            }
        }

        //Média individual
        alunos[tx][ay][5]=alunos[tx][ay][5]/4;

        //Média da turma
        turmas[tx][4]+=alunos[tx][ay][5];

        //Qtd ALunos Med > 8
        if(alunos[tx][ay][5]>8)
        {
            turmas[tx][1]++;
        }

        //Frequencia individual
        printf("Insira o número de faltas: ");
        scanf("%f", &alunos[tx][ay][4]);

        //Qtd Substitutiva
        if(alunos[tx][ay][5]<7 && alunos[tx][ay][5]>=5 && alunos[tx][ay][4]<11)
        {
            turmas[tx][3]++;
        }

        //Quantidade de alunos
        turmas[tx][0]++;

        printf("Deseja adicionar outro aluno? \n[1]Siii!! [0]Não: ");
        scanf("%d", &flag);
        if(flag==0){break;}
    }

    //Média da turma calc
    turmas[tx][4]=turmas[tx][4]/turmas[tx][0];

}

//Relatório(s) final(is):
printf("\nQual relatório deseja imprimir?: \n\n[1]Turma \n[2]Alunos\n\nRelatório ");
scanf("%d", &on);

do
{
    if(on==1)
    {

        printf("\nRelatório por Turma\nInforme o número da turma: ");
        scanf("%d", &n_turma);

        printf("\nTurma %d (%.1f alunos): ", n_turma, turmas[n_turma-1][0]);
        printf("\nA média geral da turma é de %.2f", turmas[n_turma-1][4]);
        printf("\n%.1f alunos que tiveram a média final menor que 8", turmas[n_turma-1][1]);
        printf("\n%.1f alunos que tiraram 0 em alguma das notas", turmas[n_turma-1][2]);
        printf("\n%.1f alunos que terão que fazer a prova substitutiva", turmas[n_turma-1][3]);

    }
    else
    {
        printf("Relatório por Aluno\nInforme o número do aluno e de sua turma \nNúmero Aluno: ");
        scanf("%d", &n_aluno);
        printf("\nNúmero Turma: ");
        scanf("%d", &n_turma);

        printf("\nAluno %d (%s)", n_aluno, nomes[n_turma-1][n_aluno-1]);
        printf("\nBoletim:\n[N1: %.1f][N2: %.1f][N3: %.1f][N4: %.1f]", 
            alunos[n_turma-1][n_aluno-1][0], 
            alunos[n_turma-1][n_aluno-1][1], 
            alunos[n_turma-1][n_aluno-1][2],
            alunos[n_turma-1][n_aluno-1][3]);
        printf("\nMédia final: [Média %.1f]", alunos[n_turma-1][n_aluno-1][5]);
        printf("\n%f faltas", alunos[n_turma-1][n_aluno-1][4]);
        if(alunos[n_turma-1][n_aluno-1][4]>10)
        {
            printf("\nAluno reprovado por falta");
            break;
        }

        if(alunos[n_turma-1][n_aluno-1][5]<5)
        {
            printf("\nAluno reprovado por nota");
        }
        else
        {
            if(alunos[n_turma-1][n_aluno-1][5]>=7)
            {
                printf("\nAluno aprovado");
            }
            else
            {
                printf("\nAluno fará prova substitutiva");
            }
        }
        
    }

    printf("\nQual relatório deseja imprimir? [-1]para sair: \n\n[1]Turma \n[2]Alunos\n\nRelatório ");
    scanf("%d", &on);
}
while(on!=-1); 

return 0;
}