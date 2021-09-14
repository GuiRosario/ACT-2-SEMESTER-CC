#include <stdio.h>
#include <string.h>
int main() {
 //1- Qual a funcionalidade da linha a seguir? RES: A LINHA A SEGUIR CONCEDE ACESSO ARQUIVO "ex1_arq1.txt" , ESTE SENDO ABERTO EM MODO DE LEITURA DETERMINADO pelo "r", PODENDO SER ACESSADO ATRAVÈS DO PONTEIRO "arq".
 FILE *arq = fopen("ex1_arq1.txt", "r");
 char buffer[120];
 char *token;
 // 2- Qual a funcionalidade da linha a seguir? RES: ELE ESTA ALOCANDO NA VARIAVEL "busca" DE TIPO CHAR A STRING "lorem", COMO N FOI DETERMINAOD UM TAMANHO PARA ESSA VARIAVEL ELA TERA O TAMANHO DA STRING. 
 char busca[] = "lorem";
 int contagem = 0;
//3- Qual a funcionalidade do laço de repetição a seguir? RES: COMO WHILE(1) LOGO A PRIORE É UM LAÇO QUE NÂO POSSUI FIM, NA PROXIMA LINHA  FGETS ESTA GUARDANDO 120 CARACTERES DO PONTEIRO ARQ (QUE APONTA PARA O ARQUIVO) NA VARIAVEL BUFFER, NA PROXIMA LINHA EXISTE UMA CONDIÇÃO IF QUE SE A FUNÇÃO "feof" ("feof" É VERDADEIRA SE FGETS CHEGOU NO FIM DO ARQUIVO) FOR VERDADEIRA ELE EXECUTARA UM "break" QUE SAIRA DO LAÇO. 
 while(1) {
 fgets(buffer, 120, arq);
 if(feof(arq)) {
 break;
 }
 // 4- Qual a funcionalidade da linha a seguir? RES: "strtok" ESTA ACESSANDO A STRING BUFFER E SEGMENTANDO ELA EM CADA ESPAÇO QUE TIVER UM ".,!?" ESSAS SEGMENTAÇÕES ESTÃO SENDO SALVAS NA VARIAVEL TOKEN;
 token = strtok(buffer, " .,!?");
 //5- Qual a funcionalidade do laço de repetição a seguir? RES WHILE POSSUI A CONDIÇÃO DE "token != NULL" LOGO ENQUANTO TOKEN TIVER STRINGS E FOR DIFERENTE DE NULL ELE CONTINUARA O LAÇO, LOGO DEPOIS TEMOS UMA CONDIÇÃO QUE USA A FUNÇÃO "strcmp" QUE COMPARA DUAS STRINGS, CASO ELAS SEJAM IGUAIS ELA RETORNA 0, LOGO A CONDIÇÃO É QUE SE "token" E "busca" FOREM IGUAIS ELE IRA SOMAR 1 A VARIAVEL "contagem", E POR FIM TEMOS A FUNÇÂO "strtok" QUE RECEBE NULL LOGO APÒS RECEBER A ULTIMA SEGMENTAÇÂO, ASSIM FINALIZANDO O LOOP.
 while(token != NULL) {
 // se igual cont++
 if(strcmp(token, busca) == 0) {
 contagem++;
 }
 token = strtok(NULL, " .,!?");
 }
 }
//6- Qual a saída do código? RES: A SAIDA MOSTRA QUANTAS VEZES A STRING "lorem" QUE ESTAVA GUARDADA NA VARIAVEL "busca" ESTÁ ESCRITA NO ARQUIVO "ex1_arq1.txt".
 printf("ocorrencias de %s: %d\n", busca, contagem); 
 fclose(arq);
 return 0;
}