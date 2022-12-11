#include <stdio.h>
#include <stdlib.h>
#include "Libs/ler.h"
int main()
{
    int opc;
    do
    {
        printf("\n");
        printf(
          " _________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| INICIAR = 1                                        |\n"
          "| ENCERRAR OPERACOES = 0                             |\n"
          "|____________________________________________________|\n\n");
        printf("DIGITE A OPERACAO DESEJADA: ");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1 :
            func(); 
            break;
        case 0:
            break;
        default:
            break;
        }
    }while(opc!=0);
}