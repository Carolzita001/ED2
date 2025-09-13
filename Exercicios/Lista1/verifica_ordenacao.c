#include <stdio.h>

int main(){
    int vet[6], desordenado = 0;

    for (int i = 0; i < 6; i++) {
        printf("Insira o numero de indice %d:\n", i+1);
        scanf("%d", &vet[i]);
    }

    // Verifica se está ordenado em ordem crescente
    for (int i = 1; i < 6; i++) {
        if (vet[i] < vet[i-1]) {
            desordenado = 1;
            break;
        }
    }

    if (desordenado == 0) {
        printf("ORDENADO!\n");
    } else {
        printf("DESORDENADO!\n");
    }

    for (int i = 0; i < 6; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}