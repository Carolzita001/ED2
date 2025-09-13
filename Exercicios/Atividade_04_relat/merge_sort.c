#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para intercalar duas metades ordenadas
void intercalar(int *vetor, int tamanho) {
    int meio = tamanho / 2;
    int i = 0, j = meio, k = 0;
    int *auxiliar = (int*)malloc(tamanho * sizeof(int));
    if (!auxiliar) {
        printf("Erro de alocação!\n");
        exit(1);
    }

    while (i < meio && j < tamanho) {
        if (vetor[i] <= vetor[j])
            auxiliar[k++] = vetor[i++];
        else
            auxiliar[k++] = vetor[j++];
    }
    while (i < meio)
        auxiliar[k++] = vetor[i++];
    while (j < tamanho)
        auxiliar[k++] = vetor[j++];

    for (i = 0; i < tamanho; i++)
        vetor[i] = auxiliar[i];

    free(auxiliar);
}

// Função principal do Merge Sort
void mergeSort(int *vetor, int tamanho) {
    int meio = tamanho / 2;
    if (tamanho > 1) {
        mergeSort(vetor, meio);
        mergeSort(vetor + meio, tamanho - meio);
        intercalar(vetor, tamanho);
    }
}

int main() {
    int tamanho = 100000;
    int limit = 1000000;
    int *vet = (int*)malloc(tamanho * sizeof(int));
    if (!vet) {
        printf("Erro de alocação!\n");
        return 1;
    }

    srand(time(NULL));

    printf("Preenchendo o vetor...\n");
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % limit;
        // printf("Vetor[%d] = %d\n", i, vet[i]); // Descomente se quiser ver os valores
    }

    printf("Ordenando...\n");
    clock_t tempo_inicio = clock();

    mergeSort(vet, tamanho);

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