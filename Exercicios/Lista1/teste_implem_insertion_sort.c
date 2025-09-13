#include <stdio.h>

int main(){
    int vet[6] = {4,5,6,3,1,2};
    int n = 6;

    for (int i = 1; i < n; i++)//divide o sub-A do sub-B
    {
        int chave = vet[i];// vadiável que carrega a primeira posição do sub-B
        int j = i-1;// 'j' armazena o ultimo elemento do sub-A
        while (j>=0 && vet[j] > chave)/*anda pra trás até achar um elemento menor*/
        {
            vet[j+1] = vet[j];
            j--;//anda pra trás para comparar com os demais 
        }
        vet[j+1] = chave; // insere a chave na posição da frente de onde o while parou
    }

    for (int i = 0; i < 6; i++)
    {
        printf("%d, ", vet[i]);
    }
    
}