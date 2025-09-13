#include <stdio.h>

typedef struct VETOR
{
    int vet[6];
}vetor;


int main(){
    int array[6] = {50,60,7,80,25,40,20}, indice;
    vetor vet1, vet2, vet3, vet4, vet5; 

    for (int i = 0; i < 7; i++)
    {
        if (array[i]>=0&&array[i]<=25){
            vet1.vet[indice] = array[i];
            indice++;  
        }else if (array[i]>=26&&array[i]<=40){
            vet2.vet[indice] = array[i];
            indice++;
        }else if (array[i]>=41&&array<=60){
            vet3.vet[indice] = array[i];
            indice++;
        }else if (array[i]>=61&&array<=80){
            vet4.vet[indice] = array[i];
            indice++;
        }else
        {
            vet5.vet[indice] = array[i];
            indice++;
        }
    }
    

}