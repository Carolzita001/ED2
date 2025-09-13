#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalar(int *vetor, int tamanho) 
{
    //trata o vetor como duas metades. i percorrerá a primeira metade e j a segunda
    int meio = tamanho / 2;
    int i = 0, j = meio, k = 0;
    int auxiliar[tamanho]; //é preciso um vetor auxiliar para armazenar os valores ordenados
    
    //enquanto houver elementos no vetor
    while( i < meio && j < tamanho )
    {
        // pega o menor deles e coloca no aux
         if( vetor[i] >= vetor[j] )
            auxiliar[k] = vetor[i++];
         else
            auxiliar[k] = vetor[j++];
        k++;
      
    }
    //se a primeira metade acabou, então copia o resto da segunda metade. E vice-versa
    if( i == meio )
        while( j < tamanho )
            auxiliar[k++] = vetor[j++];
     else
         while( i < meio )
         auxiliar[k++] = vetor[i++];
    
    //depois de tudo, copia o vetor auxiliar para o vetor original
    for( i = 0; i < tamanho; i++ )
        vetor[i] = auxiliar[i];
}

void mergeSort(int *vet, int tamanho){
    int meio = tamanho/2;
    if (tamanho>1)
    {
        mergeSort(vet, meio);
        mergeSort(vet+meio, tamanho-meio);
        intercalar(vet, tamanho);
    }
}

int main(){
    int tamanho = 5;
    int vet[tamanho], limite = 100;

    srand(time(NULL));

    printf("Vetor antes da ordenacao:\n");

    for (int i = 0; i < tamanho; i++)
    {
        vet[i] = rand()%limite;
        printf("Posicao [%d]: [%d]\n", i, vet[i]);
    }

    mergeSort(vet, tamanho);

    printf("Vetor depois da ordenacao:\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("Posicao [%d]: [%d]\n", i, vet[i]);
    }
    
    getchar();
    return 0;
}