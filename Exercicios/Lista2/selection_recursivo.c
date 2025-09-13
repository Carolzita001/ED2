#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionRecursivo(int vet[], int local_prox_elemento, int tamanho){
    if (local_prox_elemento >= tamanho-1) return;
    
    int indi_menor = local_prox_elemento;
    for (int i = local_prox_elemento + 1; i < tamanho; i++)
    {
        if (vet[i]<vet[indi_menor])
        {
            indi_menor = i;
        }
    }
    
    int temp = vet[local_prox_elemento];
    vet[local_prox_elemento] = vet[indi_menor];
    vet[indi_menor] = temp;

    selectionRecursivo(vet, local_prox_elemento + 1, tamanho);

}

int main(){
    int tamanho = 10;

    int vet[tamanho];

    srand(time(NULL));

    int limit = 100;//Limite de números gerados se 100 => [0 á 99]

    printf("Preenchendo o vetor...\n");
    for (int i = 0; i < tamanho; i++)
    {
        vet[i] = rand()%limit;
        printf("Vetor[%d] = %d\n", i, vet[i]);
    }

    printf("Ordenando...\n");

    clock_t tempo_inicio = clock(); // Tempo inicial

    /*for (int i = 0; i < tamanho-1; i++){

        int menor_indice = i;

        for (int j = i+1; j < tamanho; j++)
        {
            if (vet[j]<vet[menor_indice])
            {
                menor_indice = j;
            }
        }

        int temp = vet[i];
        vet[i] = vet[menor_indice];
        vet[menor_indice] = temp;
    }*/

    selectionRecursivo(vet, 0, tamanho);
    
    clock_t tempo_fim = clock();   // Tempo final

    printf("Vetor Ordenado:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("[%d] ", vet[i]);
    }

    double tempo_execucao_s = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    double tempo_execucao_ms = tempo_execucao_s * 1000;

    printf("Tempo de execucao: %.2f segundos (%.2f ms)\n", tempo_execucao_s, tempo_execucao_ms);

    return 0;
}