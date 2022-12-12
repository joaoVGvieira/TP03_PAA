#include "../Libs/ler.h"


#define K 7

void leitura( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna)
{   
  
    FILE *arq;
    char elemento[300000];
    long int numOcorrencias = 0;
    arq = fopen( caminhoArquivo, "r" );
    while (!feof( arq )){
        fscanf( arq, "%s", elemento );
        numOcorrencias += pesquisaCoincidencia( elemento, padrao );
    }
    fclose( arq );
    matrizOcorrencias[quaLinha][coluna] = numOcorrencias;
   
}
    


void iniciar(){
   
    int qntCaracter = K;
    int qntElementos = K;
    int contElementos = 0;
    int contParecido = 0;
    char nucleos[4] = {'A','T','C','G'};
    char* elemento = (char*)malloc(qntCaracter*sizeof(char)); // elemento atual verificado
    
    char** todosElementos = (char**)calloc(qntElementos , sizeof(char*)); // matriz com todos os elementos
    for (int  i = 0; i <qntElementos ; i++){
        todosElementos[i] = (char*) calloc(qntCaracter,sizeof(char));
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


        if( contParecido < qntCaracter ){ //adiciona o elemento caso n exista e chama a funcao
            for(int i = 0; i < qntCaracter; i++){
                todosElementos[contElementos][i] = elemento[i];
                
            }
            leitura( "cachorro.txt", elemento, matrizOcorrencias, 0, contElementos);
            leitura( "chimp.txt", elemento, matrizOcorrencias, 1, contElementos);
            leitura( "humano.txt", elemento, matrizOcorrencias, 2, contElementos);

            contElementos ++;
        }
        
    }



    printf("Similaridade cachorro e chimpanze = ");
    CalculaSimilaridade(matrizOcorrencias,  0,  1,  qntElementos);
    printf("Similaridade cachorro e humano = ");
    CalculaSimilaridade(matrizOcorrencias,  0,  2,  qntElementos);
    printf("Similaridade humano e chimpanze = ");
    CalculaSimilaridade(matrizOcorrencias,  1,  2,  qntElementos);



    free(matrizOcorrencias);

}
 


void leitura1( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna)
{   
  
    FILE *arq;
    char elemento[300000];
    long int numOcorrencias = 0;
    arq = fopen( caminhoArquivo, "r" );
    while (!feof( arq )){
        fscanf( arq, "%s", elemento );
        numOcorrencias += KMPSearch( padrao, elemento );
    }
    fclose( arq );
    matrizOcorrencias[quaLinha][coluna] = numOcorrencias;
   
}


void iniciar1(){
    int qntCaracter = K;
    int qntElementos = K;
    int contElementos = 0;
    int contParecido = 0;
    char nucleos[4] = {'A','T','C','G'};
    char* elemento = (char*)malloc(qntCaracter*sizeof(char)); // elemento atual verificado
    
    char** todosElementos = (char**)calloc(qntElementos , sizeof(char*)); // matriz com todos os elementos
    for (int  i = 0; i <qntElementos ; i++){
        todosElementos[i] = (char*) calloc(qntCaracter,sizeof(char));
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


        if( contParecido < qntCaracter ){ //adiciona o elemento caso n exista e chama a funcao
            for(int i = 0; i < qntCaracter; i++){
                todosElementos[contElementos][i] = elemento[i];
                
            }
           //printf("\nPadrao = %s\n", elemento);

            leitura1( "cachorro.txt", elemento, matrizOcorrencias, 0, contElementos);
            leitura1( "chimp.txt", elemento, matrizOcorrencias, 1, contElementos);
            leitura1( "humano.txt", elemento, matrizOcorrencias, 2, contElementos);

            contElementos ++;
        }
        
    }



    printf("Similaridade cachorro e chimpanze = ");
    CalculaSimilaridade(matrizOcorrencias,  0,  1,  qntElementos);
    printf("Similaridade cachorro e humano = ");
    CalculaSimilaridade(matrizOcorrencias,  0,  2,  qntElementos);
    printf("Similaridade humano e chimpanze = ");
    CalculaSimilaridade(matrizOcorrencias,  1,  2,  qntElementos);



    free(matrizOcorrencias);

}



 // Kmp Algoritmo 






 

 // Shift-And

void leitura2( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna)
{   
  
    FILE *arq;
    char elemento[300000];
    long int numOcorrencias = 0;
    arq = fopen( caminhoArquivo, "r" );
    while (!feof( arq )){
        fscanf( arq, "%s", elemento );
        numOcorrencias += SearchString( elemento, padrao );
    }
    fclose( arq );
    matrizOcorrencias[quaLinha][coluna] = numOcorrencias;
   
}

 

void iniciar2(){
    int qntCaracter = K;
    int qntElementos = K;
    int contElementos = 0;
    int contParecido = 0;
    char nucleos[4] = {'A','T','C','G'};
    char* elemento = (char*)malloc(qntCaracter*sizeof(char)); // elemento atual verificado
    
    char** todosElementos = (char**)calloc(qntElementos , sizeof(char*)); // matriz com todos os elementos
    for (int  i = 0; i <qntElementos ; i++){
        todosElementos[i] = (char*) calloc(qntCaracter,sizeof(char));
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


        if( contParecido < qntCaracter ){ //adiciona o elemento caso n exista e chama a funcao
            for(int i = 0; i < qntCaracter; i++){
                todosElementos[contElementos][i] = elemento[i];
                
            }
           //printf("\nPadrao = %s\n", elemento);

            leitura2( "cachorro.txt", elemento, matrizOcorrencias, 0, contElementos);
            leitura2( "chimp.txt", elemento, matrizOcorrencias, 1, contElementos);
            leitura2( "humano.txt", elemento, matrizOcorrencias, 2, contElementos);

            contElementos ++;
        }
        
    }



    printf("Similaridade cachorro e chimpanze = ");
    CalculaSimilaridade(matrizOcorrencias,  0,  1,  qntElementos);
    printf("Similaridade cachorro e humano = ");
    CalculaSimilaridade(matrizOcorrencias,  0,  2,  qntElementos);
    printf("Similaridade humano e chimpanze = ");
    CalculaSimilaridade(matrizOcorrencias,  1,  2,  qntElementos);



    free(matrizOcorrencias);

}
