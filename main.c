#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Libs/ler.h"
int main()
{
    srand(time(NULL));
    printf("\n------------------  Similaridade Boyer-Moore  -----------------------\n\n");
    clock_t boyerMoore = clock();
    iniciar(); 
    clock_t finalBoyerMoore = clock();
    printf("\n\n------------------ Similaridade KMP -----------------------\n\n");
    clock_t KMP = clock();
    iniciar1();
    clock_t finalKMP = clock();
    printf("\n\n------------------ Similaridade Shift-And -----------------------\n\n");
    clock_t shiftAnd = clock();
    iniciar2();
    clock_t finalshiftAnd = clock();
    printf("\n\n------------------ Tempo de Execucao Total -----------------------\n\n");
    printf("Boyer-Moore: %.2lfs\n", ((float)(finalBoyerMoore-boyerMoore)) / (CLOCKS_PER_SEC));
    printf("KMP: %.2lfs\n", ((float)(finalKMP-KMP)) / (CLOCKS_PER_SEC));
    printf("Shift-And: %.2lfs\n", ((float)(finalshiftAnd-shiftAnd)) / (CLOCKS_PER_SEC));
    printf("\n------------------------------------------------------------------\n");
           
}

