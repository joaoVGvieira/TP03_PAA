#include "../Libs/ler.h"

void leitura( char* caminhoArquivo ){
    
    FILE *arq, *arqE;
    char *result;
    char Linha[100];
    int i=0;
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
            result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            // acima a gente tem que ver qual valor que vamo usar para verificar a sequencia de caracterer lá
            // acho que é necesario usar essa variavel para armazenar essa a sequencia do tamanho que vamo definir ainda
            // fiz um teste criando um arquivo so pra ver se tava lendo tudo ok
            fputs(Linha,arqE);
        }
        fclose( arq );
        fclose(arqE);
    }
    
}
