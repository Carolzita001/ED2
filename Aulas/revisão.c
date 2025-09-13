#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void intercalar(int*vet, int tamanho){
    int meio = tamanho/2;
    int i = 0, j = meio, k = 0;
    int *auxiliar = (int*)malloc(tamanho*sizeof(int));
    if (!auxiliar)
    {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    // intercala os valores
    while (i<meio && j <tamanho)
    {
        if (vet[i]<=vet[j])
        {
            auxiliar[k++] = vet[i++];
        }else auxiliar[k++] = vet[j++];
    }
    //caso o lado direito tenha acabado
    while (i<meio)
    {
        auxiliar[k++] = vet[i++];
    }
    //caso o lado esquedo tenha acabado
    while (j<tamanho)
    {
        auxiliar[k++]=vet[j++];
    }
    //passa as posições ordenadas pro vetor
    for (i = 0; i < tamanho; i++)
    {
        vet[i]=auxiliar[i];
    }
    
    free(auxiliar);
}

void mergeSort(int *vet, int tamanho){
    int meio = tamanho / 2;
    if (tamanho > 1)//até tamanho ser menor que 1
    {
        mergeSort(vet, meio);//chama um merge pro lado direito
        mergeSort(vet+meio, tamanho-meio);//chama o merge pro lado esquerdo
        intercalar(vet, tamanho);//chama a função que ordena
    } 
}

int main(){
    int tamanho = 10, limite = 100, opcao, x;
    int vet[tamanho];

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++)
    {
        vet[i] = rand()%limite;
        printf("Vetor[%d]: [%d]\n", i, vet[i]);
    }

    do
    {
        printf("\n---ALGORITMOS DE ORDENACAO e metodos de busca---\n\n");
        printf("1 - bubble sort\n");
        printf("2 - selection sort\n");
        printf("3 - insertion sort\n");
        printf("4 - merge sort\n");
        printf("5 - quick sort\n");
        printf("6 - busca sequencial\n");
        printf("7 - busca binaria\n");
        printf("0 - para sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            //prestar atenção nos tamanhos
            for (int i = 0; i < tamanho-1; i++)
            {
                for (int j = 0; j < tamanho-1-i; j++)
                {
                    if (vet[j]>vet[j+1])
                    {
                        int temp = vet[j+1];
                        vet[j+1] = vet[j];
                        vet[j] = temp;
                    }
                }
            }
            
            printf("Vetor Ordenado:\n");
            for (int i = 0; i < tamanho; i++)
            {
                printf("[%d] ", vet[i]);
            }

            break;
        case 2:
            //tamanho - 1 e int j=i+1
            for (int i = 0; i < tamanho-1; i++)
            {
                int menor_indice = i;//guarda a posição
                //verifica do elemento da frente qual o menor
                for (int j = i+1; j < tamanho ; j++)
                {
                    if (vet[j]<vet[menor_indice])
                    {
                        menor_indice = j;
                    }
                }
                //insere na posição quardada
                int temp = vet[i];
                vet[i] = vet[menor_indice];
                vet[menor_indice] = temp;
            }
            
            printf("Vetor Ordenado:\n");
            for (int i = 0; i < tamanho; i++)
            {
                printf("[%d] ", vet[i]);
            }

            break;

        case 3:
            //começa em 1
            for (int i = 1; i < tamanho; i++)
            {
                //declara a chave como segundo elemento
                int chave = vet[i];
                //considera o primeiro elemento como ordenado
                int j = i - 1;
                //muda a chave escolhida
                while (j>=0 && vet[j]>chave)
                {
                    vet[j+1] = vet[j];
                    j--;
                }
                //move a chave
                vet[j+1]=chave;
            }
            
            printf("Vetor Ordenado:\n");
            for (int i = 0; i < tamanho; i++)
            {
                printf("[%d] ", vet[i]);
            }

            break;
        case 4:
            mergeSort(vet, tamanho);

            printf("Vetor Ordenado:\n");
            for (int i = 0; i < tamanho; i++)
            {
                printf("[%d] ", vet[i]);
            }
            break;
        case 5:

            /*vamos entregar pra deus*/

            break;
        case 6:
            printf("----- PESQUISA SEQUENCIAL -----\n\n");
            printf("Infome o numero a ser buscado: ");
            scanf("%d", &x);

            int cont = 0;
            bool existe = false;

            for (int i = 0; i < tamanho; i++)
            {
                if (vet[i]== x)
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
        case 7:
            printf("----- PESQUISA BINARIA -----\n\n");
            printf("Infome o codigo do produto: ");
            scanf("%d", &x);

            int esq = 0;
            int dir = tamanho - 1; // vetor tem 3 elementos: índices 0, 1, 2
            bool encontrado = false;
            while (esq<=dir)
            {
                int i =(esq + dir)/2;
                if (x == vet[i]) {
                    printf("A chave %d existe no vetor e esta na posicao %d.\n", x, i);
                    encontrado = true;
                    break;
                }else if (x<vet[i])
                {
                    dir = i-1;
                }else esq = i+1;
            }
            
            if (!encontrado) {
                printf("O produto %d nao existe no vetor.\n", x);
                }
                printf("----- FIM PESQUISA BINARIA -----\n");

            break;
        default:
            break;
        }

    } while (opcao!=0);
    
    
    return 0;
}