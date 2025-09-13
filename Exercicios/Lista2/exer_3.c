#include <stdio.h>

typedef struct
{
    char nome[50];
    int codigo;
}ITEM;


int main(){
    ITEM item[5];

    item[0].codigo = 004;
    snprintf(item[0].nome, sizeof(item[0].nome), "%s", "Balinha");

    item[1].codigo = 002;
    snprintf(item[1].nome, sizeof(item[1].nome), "%s", "Chocolate");

    item[2].codigo = 001;
    snprintf(item[2].nome, sizeof(item[2].nome), "%s", "Pirulito");

    item[3].codigo = 005;
    snprintf(item[3].nome, sizeof(item[3].nome), "%s", "Cookie");

    item[4].codigo = 003;
    snprintf(item[4].nome, sizeof(item[4].nome), "%s", "Chiclete");

    for (int i = 0; i < 5-1; i++)
    {
        int menor_indice = i;

        for (int j = i+1 ; j < 5; j++)
        {
            if (item[j].codigo < item[menor_indice].codigo)
            {
                menor_indice = j;
            }
        }
        
        ITEM temp = item[i];
        item[i] = item[menor_indice];
        item[menor_indice] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Item [%d]: codigo: %d; nome: %s\n", i+1, item[i].codigo, item[i].nome);
    }
    
    
    return 0;
}