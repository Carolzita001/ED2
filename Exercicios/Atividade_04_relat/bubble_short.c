#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int tamanho = 10000;

    int vet[tamanho];

    srand(time(NULL));

    int limit = 100000;//Limite de números gerados se 100 => [0 á 99]

    printf("Preenchendo o vetor...\n");
    for (int i = 0; i < tamanho; i++)
    {
        vet[i] = rand()%limit;
        printf("Vetor[%d] = %d\n", i, vet[i]);
    }

    printf("Ordenando...\n");

    clock_t tempo_inicio = clock(); // Tempo inicial

    int temp;

    for (int i = 0; i < tamanho-1; i++)
    {
        for (int j = 0; j < tamanho-1-i; j++)
        {
            if (vet[j]>vet[j+1])
            {
                temp = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = temp;
            }   
        }
    }
    
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