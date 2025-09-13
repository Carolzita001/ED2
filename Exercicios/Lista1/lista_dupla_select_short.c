#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM {
    int item;
    struct ITEM *proximo;
    struct ITEM *anterior;
} tipoLista;

typedef tipoLista* Lista;

tipoLista* criarNo(int valor) {
    tipoLista* novo = (tipoLista*)malloc(sizeof(tipoLista));
    novo->item = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}

Lista inserirFim(Lista lista, int valor) {
    tipoLista* novo = criarNo(valor);
    if (lista == NULL) return novo;

    tipoLista* aux = lista;
    while (aux->proximo != NULL) aux = aux->proximo;

    aux->proximo = novo;
    novo->anterior = aux;
    return lista;
}

void exibir(Lista lista) {
    printf("Lista: ");
    tipoLista* aux = lista;
    while (aux != NULL) {
        printf("[%d] ", aux->item);
        aux = aux->proximo;
    }
    printf("\n");
}

// Função auxiliar: remove um nó da lista
void removerNo(tipoLista** Lista, tipoLista* no) {
    if (no->anterior) no->anterior->proximo = no->proximo;
    else *Lista = no->proximo; // se era a cabeça

    if (no->proximo) no->proximo->anterior = no->anterior;

    no->proximo = no->anterior = NULL;
}

// Função auxiliar: insere nó antes de outro
void inserirAntes(tipoLista** Lista, tipoLista* ref, tipoLista* no) {
    no->proximo = ref;
    no->anterior = ref->anterior;

    if (ref->anterior) ref->anterior->proximo = no;
    else *Lista = no; // virou a nova cabeça

    ref->anterior = no;
}

// Selection sort trocando ponteiros
void selectionSort(tipoLista** Lista) {
    if (*Lista == NULL) return;

    tipoLista* i = *Lista;
    while (i != NULL) {
        tipoLista* min = i;
        tipoLista* j = i->proximo;

        // acha o menor do resto
        while (j != NULL) {
            if (j->item < min->item) min = j;
            j = j->proximo;
        }

        if (min != i) {
            removerNo(Lista, min);
            inserirAntes(Lista, i, min);
            i = min; // reposiciona i
        }

        i = i->proximo;
    }
}

int main() {
    Lista lista = NULL;

    lista = inserirFim(lista, 5);
    lista = inserirFim(lista, 3);
    lista = inserirFim(lista, 8);
    lista = inserirFim(lista, 1);
    lista = inserirFim(lista, 7);

    printf("Antes da ordenação:\n");
    exibir(lista);

    selectionSort(&lista);

    printf("Depois da ordenação:\n");
    exibir(lista);

    return 0;
}
