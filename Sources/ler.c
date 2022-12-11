#include "../Libs/ler.h"
#include <string.h>
#include <limits.h>
#define NO_OF_CHARS 256

int leitura( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna)
{
    FILE *arq;
    char elemento[30000];
    long int numOcorrencias = 0;
    arq = fopen( caminhoArquivo, "r" );

    while (!feof( arq )){

        fscanf( arq, "%s", elemento );
        numOcorrencias += pesquisaCoincidencia( elemento, padrao );
        printf("%d ", pesquisaCoincidencia( elemento, padrao ));

    }

    printf("%ld\n\n",numOcorrencias);
    
    fclose( arq );

    matrizOcorrencias[quaLinha][coluna] = numOcorrencias;
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
    
    char** todosElementos = (char**)malloc(qntElementos * sizeof(char*)); // matriz com todos os elementos
    for (int  i = 0; i <qntCaracter ; i++){
        todosElementos[i] = (char*) malloc(sizeof(char));
    }

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


        if( contParecido < qntCaracter ){ // adiciona o elemento caso n exista e chama a funcao
            for(int i = 0; i < qntCaracter; i++){
                todosElementos[contElementos][i] = elemento[i];
                
            }
            printf("\nPadrao = %s\n", elemento);

            leitura( "cachorro.txt", elemento, matrizOcorrencias, contElementos, 0);
            leitura( "chimp.txt", elemento, matrizOcorrencias, contElementos, 1);
            leitura( "humano.txt", elemento, matrizOcorrencias, contElementos, 2);
            contElementos ++;
        }
        
    }
    printf("\n");
    for(int i = 0; i < contElementos; i ++){
        for(int j = 0; j < 3; j ++){
            printf("%ld ", matrizOcorrencias[i][j]);
        }
        printf("\n");
    }

}
 