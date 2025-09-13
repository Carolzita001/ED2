#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int vet[5], ordenado = 1, limite = 100;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        vet[i] = rand()%limite;
        printf("Posicao [%d]: [%d]\n", i, vet[i]);
        if (vet[i]<vet[i+1]) ordenado = 0;
    }
    
    if (ordenado)
    {
        printf("Ordenado!\n");
    }else printf("Desordenado!\n");
    
    return 0;
}