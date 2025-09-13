#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int tamanho = 5;
    char vet[tamanho][50];

    strcpy(vet[0], "Gabriela");
    strcpy(vet[1], "Maria");
    strcpy(vet[2], "Fernanda");
    strcpy(vet[3], "Lucelena");
    strcpy(vet[4], "Ana Carolina");

    for (int i = 0; i < tamanho - 1; i++)
    {

        int menor_indice = i;

        for (int j = i + 1; j < tamanho; j++)
        {
            if (strcmp(vet[j], vet[menor_indice]) < 0)
            {
                menor_indice = j;
            }
        }

        if (menor_indice != i)
        {
            char temp[50];
            strcpy(temp, vet[i]);
            strcpy(vet[i], vet[menor_indice]);
            strcpy(vet[menor_indice], temp);
        }
    }

    printf("Strings ordenadas:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%s\n", vet[i]);
    }

    printf("----- PESQUISA BINARIA -----\n\n");
    char busca[50];
    printf("Infome o nome a ser buscado: ");
    scanf("%[^\n]", busca);

    int esq = 0;
    int dir = tamanho-1; // vetor tem 3 elementos: índices 0, 1, 2
    bool encontrado = false;

    while (esq <= dir)
    {
        int meio = (esq + dir) / 2;
        int cmp = strcmp(busca, vet[meio]);
        if (cmp == 0)
        {
            printf("'%s'encontrado na posicao %d.\n", busca, meio);
            encontrado = true;
            break;
        }
        else if (cmp < 0)
        {
            dir = meio - 1;
        }
        else
        {
            esq = meio + 1;
        }
    }
    if (!encontrado)
    {
        printf("'%s' nao foi encontrado no vetor.\n", busca);
    }
    printf("----- FIM PESQUISA BINARIA -----\n");

    return 0;
}