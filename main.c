#include <stdio.h>
#include <stdlib.h>
#include "Libs/ler.h"
int main(){
    int opc;
    char nome_arquivo[1000];
    do
    {
        printf("\n");
        printf(
          " _________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| LER ARQUIVO = 1                                    |\n"
          "| ENCERRAR OPERACOES = 0                             |\n"
          "|____________________________________________________|\n\n");
        printf("DIGITE A OPERACAO DESEJADA: ");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1 :
            printf("\nDIGITE O NOME DO ARQUIVO DE ENTRADA: ");
            scanf(" %[^\n]s ",nome_arquivo);
            leitura(nome_arquivo);         
            break;
        case 0:
            break;
        default:
            break;
        }
    }while(opc!=0);
}