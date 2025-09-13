#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de partição para o Quick Sort
int particionar(int *vetor, int inicio, int fim){
    int pivoIndice = inicio + rand() % (fim - inicio + 1);

    int temp = vetor[pivoIndice];
    vetor[pivoIndice] = vetor[fim];
    vetor[fim] = temp;

    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            int aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }

    int aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;
    return i + 1;
}

// Função principal do Quick Sort
void quickSort(int *vetor, int inicio, int fim){
    if (inicio < fim) {
        int pivoIndice = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, pivoIndice - 1);
        quickSort(vetor, pivoIndice + 1, fim);
    }
}

int main(){
    int tamanho = 100000;
    int *vet = (int*)malloc(tamanho * sizeof(int));
    if (!vet) {
        printf("Erro de alocação!\n");
        return 1;
    }

    int limit = 1000000;
    srand(time(NULL));

    printf("Preenchendo o vetor...\n");
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % limit;
        // printf("Vetor[%d] = %d\n", i, vet[i]); // Descomente para ver os valores
    }

    printf("Ordenando...\n");
    clock_t tempo_inicio = clock();

    quickSort(vet, 0, tamanho - 1);

    clock_t tempo_fim = clock();

    printf("Vetor Ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] ", vet[i]);
    }
    printf("\n");

    double tempo_execucao_s = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
    double tempo_execucao_ms = tempo_execucao_s * 1000;
    double tempo_execucao_us = tempo_execucao_s * 1000000;
    double tempo_execucao_ns = tempo_execucao_s * 1000000000;

    printf("Tempo de execucao:\n[%.2f] segundos\n[%.2f] milissegundos\n[%.2f] microsegundos\n[%.2f] nanosegundos\n", tempo_execucao_s, tempo_execucao_ms, tempo_execucao_us, tempo_execucao_ns);

    free(vet);
    return 0;
}