#include "../Libs/ler.h"

void leitura( char* caminhoArquivo ){
    
    FILE *arq, *arqE;
    char *result;
    char Linha[1000];
    arq = fopen( caminhoArquivo, "r" );
    arqE = fopen("teste.txt","w");
    if ( arq == NULL ) {
        printf("\nARQUIVO NAO ENCONTRADO\n");
        return;
    }
    else {
        printf("\nLEITURA DE ARQUIVO FEITA COM SUCESSO!\n");
        while (!feof(arq))
        {
            result = fgets(Linha, 1000, arq);  
            fputs(Linha,arqE);
        }
        fclose( arq );
        fclose(arqE);
    }
}
