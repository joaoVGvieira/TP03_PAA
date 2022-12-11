#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
        case 0 :
            break;
        case 1 :
            func(); 
            break;
        case 2 :
            printf(
                "\n ______________Similaridade Entre Pares______________ \n");
            
            clock_t inicioBoyerMoore = clock();
            
            printf("|                                                    |\n");
            printf("|_________________Humano e Chimpanzé_________________|\n");
            //printf("|                      %.15lf                        |\n", similaridade);
            printf("|_________________Humano e Cachorro__________________|\n");
            //printf("|                      %.15lf                        |\n", similaridade);
            printf("|________________Chimpanzé e Cachorro________________|\n");
            //printf("|                      %.15lf                        |\n", similaridade);
            printf("|                                                    |\n");
            printf("|____________________________________________________|\n");

            break;

        default:
            break;
        }
    }while(opc!=0);
}
