#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NO_OF_CHARS 256

void leitura( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna);

int max ( int a, int b );

int pesquisaCoincidencia( char *txt,  char *pat);

void badCharHeuristic( char *str, int size,int badchar[NO_OF_CHARS] );

void iniciar();
void iniciar1();
void iniciar2();

int KMPSearch(char* pat, char* txt);

void computeLPSArray(char* pat, int M, int* lps);

int SearchString(char* text, char* pat);

void CalculaSimilaridade(long int **matrizOcorrencias, int linha1, int linha2, int qntPadroes);

void leituraKMP( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna);

void leituraShiftAnd( char* caminhoArquivo, char*  padrao , long int** matrizOcorrencias, int quaLinha, int coluna);
