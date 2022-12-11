#include <stdlib.h>
#include <stdio.h>
#define NO_OF_CHARS 256

void leitura( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna);

int max ( int a, int b );

int pesquisaCoincidencia( char *txt,  char *pat);

void badCharHeuristic( char *str, int size,int badchar[NO_OF_CHARS] );

void func();


