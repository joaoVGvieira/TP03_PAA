#include "../Libs/ler.h"
#include <string.h>

void leitura( char* caminhoArquivo ){
    
    FILE *arq, *arqE;
    char *result;
    char Linha[100000];
    int i=0;
    char registro[1000];
    int fim = 0, cont = -1;
    arq = fopen( caminhoArquivo, "r" );
    //arqE = fopen("teste.txt","w");
    if ( arq == NULL ) {
        printf("\nARQUIVO NAO ENCONTRADO\n");

        return;
    }
    else {
        printf("\nLEITURA DE ARQUIVO FEITA COM SUCESSO!\n");

        while (!feof(arq)){

            fscanf(arq, "%s", Linha);
            cont ++;
            for(int i = 0; i < 1000; i ++){
                if(Linha[i]== '\0') break;
                printf("%c", Linha[i]);
            }
            printf(" cont = %d\n", cont);
        }


        printf("Quantidade de registros %d", cont);

        fclose( arq );
        //fclose(arqE);
    }
    
}
