#include <stdio.h>
#include <stdlib.h>


int main(){

    int qntCaracter = 3;
    int qntElementos = 5;
    char nucleos[4] = "ATCG";

    printf("Digite a qnt de caracteres: ");
    scanf("%d", &qntCaracter);
    printf("Digie a qnt de elemntos: ");
    scanf("%d", &qntElementos);

    char* elemento = (char*)malloc(qntCaracter*sizeof(char));

    while(qntElementos != 5){

        for(int j = 0; j < qntCaracter; j ++){
            elemento = nucleos[rand()%4];
            
        }

    }

}
