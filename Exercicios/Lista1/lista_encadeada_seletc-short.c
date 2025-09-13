#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct ITEM
{
    int item;
    struct ITEM *proximo;
} *tipoLista;

tipoLista criarItem(int valor)
{
    tipoLista novoItem = (tipoLista)malloc(sizeof(struct ITEM)); // CORRIGIDO: sizeof(struct ITEM), não sizeof(tipoLista)
    if (novoItem == NULL)
    {
        printf("\nErro!");
        return NULL;
    }
    else
    {
        novoItem->item = valor;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

tipoLista inserirEsquerda(int valor, tipoLista lista)
{
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        novoItem->proximo = lista;
        return novoItem;
    }
}

tipoLista inserirDireita(int valor, tipoLista lista)
{
    tipoLista novoItem = criarItem(valor);
    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        tipoLista listaAuxiliar = lista;
        while (listaAuxiliar->proximo != NULL)
        {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoItem;
        novoItem->proximo = NULL;
        return lista;
    }
}

tipoLista inserirMeio(int valor, tipoLista lista, int valorReferencia)
{
    tipoLista novoItem = criarItem(valor);

    tipoLista noReferencia = lista;

    while (noReferencia != NULL && noReferencia->item != valorReferencia)
    {
        noReferencia = noReferencia->proximo;
    }
    if(noReferencia != NULL) {
        novoItem->proximo = noReferencia->proximo;
        noReferencia->proximo = novoItem;
    }

    return lista;
}

tipoLista removerEsquerda(tipoLista lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }
    else
    {
        tipoLista listaAuxiliar;
        listaAuxiliar = lista;
        lista = lista->proximo;
        free(listaAuxiliar);
        listaAuxiliar = NULL;
    }
    return lista;
}

tipoLista removerDireita(tipoLista lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
    }
    else
    {
        tipoLista listaAuxiliar;
        listaAuxiliar = lista;

        if (lista->proximo == NULL)
        {
            free(lista);
            lista = NULL;
        }
        else
        {
            while (listaAuxiliar->proximo->proximo != NULL)
            {
                listaAuxiliar = listaAuxiliar->proximo;
            }
            tipoLista itemDescartar;
            itemDescartar = listaAuxiliar->proximo;
            free(itemDescartar);
            itemDescartar = NULL;
            listaAuxiliar->proximo = NULL;
        }
    }
    return lista;
}

tipoLista removerMeio(tipoLista lista, int valorReferencia)
{
    if (lista == NULL)
    {
        printf("Lista vazia!\n");
        return NULL;
    }
    else
    {
        tipoLista noReferencia = lista;

        if (lista->proximo == NULL)
        {
            free(lista);
            lista = NULL;
            return lista;
        }
        else
        {
            while (noReferencia->proximo != NULL && noReferencia->proximo->item != valorReferencia)
            {
                noReferencia = noReferencia->proximo;
            }
            if(noReferencia->proximo != NULL) {
                tipoLista itemDescartar = noReferencia->proximo;
                noReferencia->proximo = itemDescartar->proximo;
                free(itemDescartar);
                itemDescartar = NULL;
            }

            return lista;
        }
    }
}

void exibir(tipoLista lista)
{
    printf("\n---Lista atual---\n");
    if (lista == NULL)
    {
        printf("\nVazia!\n");
    }
    else
    {
        tipoLista listaAuxiliar = lista;
        while (listaAuxiliar != NULL)
        {
            printf("[%d] ", listaAuxiliar->item);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

// Função para ordenar a lista com Selection Sort
void selectionSort(tipoLista lista)
{
    if (lista == NULL) return;

    tipoLista i, j, min;
    int temp;

    for (i = lista; i->proximo != NULL; i = i->proximo)
    {
        min = i;
        for (j = i->proximo; j != NULL; j = j->proximo)
        {
            if (j->item < min->item)
            {
                min = j;
            }
        }

        // Troca os valores (não os ponteiros)
        if (min != i)
        {
            temp = i->item;
            i->item = min->item;
            min->item = temp;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao = -1;
    int valor = 0, valorReferencia = 0;
    tipoLista lista = NULL;

    while (opcao != 0)
    {
        exibir(lista);
        valor = 0;

        printf("\n\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir no inicio\n");
        printf("2: Inserir no final\n");
        printf("3: Inserir no meio\n");
        printf("4: Remover no inicio\n");
        printf("5: Remover no final\n");
        printf("6: Remover no meio\n");
        printf("7: Ordenar lista (Selection Sort)\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            lista = inserirEsquerda(valor, lista);
            break;

        case 2:
            printf("Digite um valor\n");
            scanf("%d", &valor);
            lista = inserirDireita(valor, lista);
            break;
        case 3:
            printf("Insira o valor de referência:\n");
            scanf("%d", &valorReferencia);

            printf("Digite um valor\n");
            scanf("%d", &valor);

            lista = inserirMeio(valor, lista, valorReferencia);
            break;
        case 4:
            lista = removerEsquerda(lista);
            break;

        case 5:
            lista = removerDireita(lista);
            break;

        case 6:
            printf("Insira o valor de referência para remover o nó:\n");
            scanf("%d", &valorReferencia);
            lista = removerMeio(lista, valorReferencia);
            break;

        case 7:
            selectionSort(lista);
            printf("\nLista ordenada com Selection Sort!\n");
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    return 0;
}
