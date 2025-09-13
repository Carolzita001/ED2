#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int codigo;
    char nome[50];
    float preco;
}ITEM;


int main(){
    ITEM produto [3];
    int opcao, x;

    produto[0].codigo = 001;
    snprintf(produto[0].nome, sizeof(produto[0].nome), "%s", "Arroz Vasconcelos 5kg");
    produto[0].preco = 32.99;

    produto[1].codigo = 003;
    snprintf(produto[1].nome, sizeof(produto[1].nome), "%s","Patinho");
    produto[1].preco = 36.99;

    produto[2].codigo = 002;
    snprintf(produto[2].nome, sizeof(produto[2].nome), "%s", "Oleo Liza 900ml");
    produto[2].preco = 6.99;

    do
    {
        printf("\n---MERCADIN---\n\n");
        printf("1 - busca sequencial\n");
        printf("2 - busca binaria\n");
        printf("3 - listar produtos\n");
        printf("0 - para sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            
            printf("----- PESQUISA SEQUENCIAL -----\n\n");
            printf("Infome o codigo do produto: ");
            scanf("%d", &x);

            int cont = 0;
            bool existe = false;
            for (int i = 0; i < 3; i++)
            {
                if (produto[i].codigo == x)
                {
                    existe = true;
                    cont++;
                }
            }
            if (existe)
            {
                printf("\nO produto %d existe no vetor, e apareceu %d vez(es)\n\n", x, cont);
            }else printf("\nO produto %d nao existe no vetor\n\n", x);

            printf("----- FIM PESQUISA SEQUENCIAL -----\n");

            break;
        case 2:
            printf("Ordenando o vetor...\n\n");

            // Ordena o vetor por código
            for (int i = 1; i < 3; i++) {
                ITEM chave = produto[i];
                int j = i - 1;
                while (j >= 0 && produto[j].codigo > chave.codigo) {
                    produto[j + 1] = produto[j];
                    j--;
                }
                produto[j + 1] = chave;
            }

            printf("Vetor ordenado por codigo:\n");
            for (int i = 0; i < 3; i++) {
                printf("Codigo: %d | Nome: %s | Preco: %.2f\n", produto[i].codigo, produto[i].nome, produto[i].preco);
            }

            printf("----- PESQUISA BINARIA -----\n\n");
            printf("Infome o codigo do produto: ");
            scanf("%d", &x);

            int esq = 0;
            int dir = 2; // vetor tem 3 elementos: índices 0, 1, 2
            bool encontrado = false;

            while (esq <= dir) {
                int i = (esq + dir) / 2;
                if (x == produto[i].codigo) {
                    printf("A chave %d existe no vetor e esta na posicao %d.\n", x, i);
                    encontrado = true;
                    break;
                }
                else if (x < produto[i].codigo) {
                    dir = i - 1;
                } else {
                    esq = i + 1;
                }
            }
            if (!encontrado) {
                printf("O produto %d nao existe no vetor.\n", x);
            }
            printf("----- FIM PESQUISA BINARIA -----\n");
            break;
        case 3:
            //listar produtos
            break;
        default:
            break;
        }

    } while (opcao != 0);
    
}