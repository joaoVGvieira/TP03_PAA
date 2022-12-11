 #include <stdio.h>
#include <string.h>
#include <limits.h>
 int SearchString(char* text, char* pat)
{
	int m = strlen(pat); // tamanho do padrao
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

int main(){
    char* texto = "chocolate chocolate chocolate";
    char* pat = "chocolate" ;
    int i = SearchString(texto, pat);
    printf("%d\n",i);
}