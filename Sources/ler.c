#include "../Libs/ler.h"
#include <string.h>
#include <limits.h>
#define NO_OF_CHARS 256

void leitura( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna)
{   
    printf("N abriu arquivo");
    FILE *arq;
    printf("1");
    char elemento[20000];
    printf("2");
    long int numOcorrencias = 0;
    printf("3");
    arq = fopen( caminhoArquivo, "r" );
    printf("4 ");
    while (!feof( arq )){

        fscanf( arq, "%s", elemento );
        numOcorrencias += pesquisaCoincidencia( elemento, padrao );
        //printf("%d ", pesquisaCoincidencia( elemento, padrao ));

    }
    printf("enotru print ");
    //printf("%ld\n",numOcorrencias);
    printf("vai fechar arquivo");
    fclose( arq );
    printf("fecha arquivo ");
    matrizOcorrencias[quaLinha][coluna] = numOcorrencias;
    printf("atualiza matriz");
}
    
int max( int a, int b ) { return ( a > b ) ? a : b; }

void badCharHeuristic( char *str, int size, int badchar[NO_OF_CHARS] )
{
    int i;
 
    for (i = 0; i < NO_OF_CHARS; i++)
         badchar[i] = -1;

    for (i = 0; i < size; i++)
         badchar[(int) str[i]] = i;
}

int pesquisaCoincidencia( char *txt,  char *pat)
{
    int m = strlen(pat);
    int n = strlen(txt);
 
    int badchar[NO_OF_CHARS];
 
    int cont=0;
    badCharHeuristic( pat, m, badchar );
 
    int s = 0;  
    while(s <= (n - m))
    {
        int j = m-1;
        while(j >= 0 && pat[j] == txt[s+j])
            j--;
        if (j < 0)
        {
            s += (s+m < n)? m-badchar[txt[s+m]] : 1;
            cont+=1;
           
        }
 
        else

            s += max(1, j - badchar[txt[s+j]]);
    }
    return cont;
}

void func()
{
    int qntCaracter;
    int qntElementos;
    int contElementos = 0;
    int contParecido = 0;
    char nucleos[4] = {'A','T','C','G'};
    printf("Digite a qnt de caracteres: ");
    scanf("%d", &qntCaracter);
    printf("Digie a qnt de elemntos: ");
    scanf("%d", &qntElementos);

    char* elemento = (char*)malloc(qntCaracter*sizeof(char)); // elemento atual verificado
    
    char** todosElementos = (char**)calloc(qntElementos , sizeof(char*)); // matriz com todos os elementos
    for (int  i = 0; i <qntElementos ; i++){
        todosElementos[i] = (char*) calloc(qntCaracter,sizeof(char));
    }

    // for(int i = 0; i < qntElementos; i ++){
    //     for(int j = 0; j < qntCaracter; j ++){
    //         printf("%c ", qntElementos[i][j]);
    //     }
    //     printf("\n");
    // }

    long int** matrizOcorrencias = (long int**)malloc(3 * sizeof(long int*)); // matriz de ocorrencia dos animais
    for ( int  i = 0; i <3 ; i++){
        matrizOcorrencias[i] = (long int*) malloc(sizeof(long int)*qntElementos);
    }
    
    while(qntElementos != contElementos){

        for(int j = 0; j < qntCaracter; j ++){ // gera elementos aleatorios
            elemento[j] = nucleos[rand()%4];
        }


         for(int i = 0; i < contElementos; i ++){ // verifica se o elemento ja existe 
                 contParecido = 0;
             for(int j = 0; j < qntCaracter; j++){
                if(elemento[j] == todosElementos[i][j]) contParecido ++;   
            }
            if( contParecido == qntCaracter ) break;
        }


        if( contParecido < qntCaracter ){ //adiciona o elemento caso n exista e chama a funcao
            for(int i = 0; i < qntCaracter; i++){
                todosElementos[contElementos][i] = elemento[i];
                
            }
            printf("\nPadrao = %s\n", elemento);

            leitura( "cachorro.txt", elemento, matrizOcorrencias, 0, contElementos);
            printf("Entra chimp");
            leitura( "chimp.txt", elemento, matrizOcorrencias, 1, contElementos);
            leitura( "humano.txt", elemento, matrizOcorrencias, 2, contElementos);
            contElementos ++;
        }
        
    }
    printf("\n");
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < contElementos; j ++){
            printf("%ld ", matrizOcorrencias[i][j]);
        }
        printf("\n");
    }

    free(matrizOcorrencias);

}
 