#include "../Libs/ler.h"

void leitura( char* caminhoArquivo ){
    
    FILE *arq, *arqE;
    char *result;
    char Linha[1000];
    int i=0;
    arq = fopen( caminhoArquivo, "r" );
    //arqE = fopen("teste.txt","w");
    if ( arq == NULL ) {
        printf("\nARQUIVO NAO ENCONTRADO\n");

        return;
    }
    else {
        printf("\nLEITURA DE ARQUIVO FEITA COM SUCESSO!\n");
        while (!feof(arq))
        {
           fscanf(arq, "%s", Linha);
           //aqui chama alguma funçao
           //fprintf(arqE,"%s", Linha);
            
        }
        fclose( arq );
        //fclose(arqE);
    }
    
}
