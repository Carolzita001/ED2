#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particionar(int *vetor, int inicio, int fim){
    int pivoIndice = inicio + rand() % (fim - inicio + 1);

    printf("\nPivo: %d\n", pivoIndice);

    int temp = vetor[pivoIndice];
    vetor[pivoIndice] = vetor[fim];
    vetor[fim] = temp;
    
    
    int pivo = vetor[fim];
    int i = inicio - 1;


    for (int j = inicio; j <= fim-1 ; j++)
    {
        if(vetor[j] <= pivo){
            i++;
            int aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }

    int aux = vetor[i+1];
    vetor[i+1] = vetor[fim];
    vetor[fim] = aux;
    return i+1;
}

void quickSort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int pivoIndice = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, pivoIndice - 1);
        quickSort(vetor, pivoIndice + 1, fim);
    }
}

int main (){
    int vetor[10] = {7,3,1,2,8,10,6,5,9,4};

    srand(time(NULL));

    printf("\nVETOR INICIAL\n");
    for (int i = 0; i < 10; i++)
    {
        printf("[%d] ", vetor[i]);
    }

    quickSort(vetor, 0, 9);

    printf("\n\nVETOR ORDENADO\n");
    for (int i = 0; i < 10; i++)
    {
        printf("[%d] ", vetor[i]);
    }
    getchar();
    
    return 0;
}    
    