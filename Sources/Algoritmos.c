#include "../Libs/Algoritmos.h"
#include <string.h>
#include <limits.h>
#include <math.h>
#include <time.h>
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

int SearchString(char* text, char* pat)
{
	int m = strlen(pat);
    int n = strlen(text); // tamanho do texto que vamo procurar o padrao
	unsigned long R;
	unsigned long patMask[CHAR_MAX + 1];           
	int i;
    int cont=0;
	if (pat[0] == '\0') return 0;
	if (m > n) return -1; 

	R = ~1;

	for (i = 0; i <= CHAR_MAX; ++i)
		patMask[i] = ~0;

	for (i = 0; i < m; ++i)
		patMask[pat[i]] &= ~(1UL << i);

	for (i = 0; text[i] != '\0'; ++i)
	{
		R |= patMask[text[i]];
		R <<= 1;

		if (0 == (R & (1UL << m))){
            cont+=1;
        }
			
	}

	return cont;

}

int KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    
    int cont=0;
   
    int lps[M];

    computeLPSArray(pat, M, lps);
 
    int i = 0; 
    int j = 0; 
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            cont+=1;
            j = lps[j - 1];
        }
 
    
        else if (i < N && pat[j] != txt[i]) {
   
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    } 
    return cont;
}
 

void computeLPSArray(char* pat, int M, int* lps)
{
    
    int len = 0;
 
    lps[0] = 0; 
 
    
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
          
            if (len != 0) {
                len = lps[len - 1];
 
             
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void CalculaSimilaridade(long int **matrizOcorrencias, int linha1, int linha2, int qntPadroes){

    double nominador = 0;
    double denominador1 = 0;
    double denominador2 = 0;

    for(int i = 0; i < qntPadroes; i ++){
        nominador += matrizOcorrencias[linha1][i] * matrizOcorrencias[linha2][i];
        denominador1 += matrizOcorrencias[linha1][i] * matrizOcorrencias[linha1][i];
        denominador2 += matrizOcorrencias[linha2][i] * matrizOcorrencias[linha2][i];
    }

    denominador1 = sqrt(denominador1);
    denominador2 = sqrt(denominador2);


    double similaridade = nominador / ( denominador1 * denominador2);


    printf(" %lf\n", similaridade);
}

