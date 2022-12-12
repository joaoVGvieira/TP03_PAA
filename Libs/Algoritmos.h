#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define NO_OF_CHARS 256


int max( int a, int b ) ;

void badCharHeuristic( char *str, int size, int badchar[NO_OF_CHARS] );

int pesquisaCoincidencia( char *txt,  char *pat);

void computeLPSArray(char* pat, int M, int* lps);

int SearchString(char* text, char* pat);