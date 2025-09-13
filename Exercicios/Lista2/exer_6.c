#include <stdio.h>

int main(){
    int vet[12] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};

    for (int i = 0; i < 4; i++)
    {
        int chave = vet[i];
        int j = i-1;
        while (j>=0 && vet[j]>chave)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = chave;
    }

    for (int i = 0; i < 12; i++)
    {
        printf("Vet[%d]: [%d]\n", i, vet[i]);
    }
    

    return 0;
}