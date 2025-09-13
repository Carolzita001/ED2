#include <stdio.h>

int main(){
    int vet [6] = {6,3,4,1,2,5};
    int temp;

   for (int i = 0; i < 5; i++)
   {
    for (int j = 0; j < 5-i; j++)
    {
        if (vet[j]>vet[j+1])
        {
           //printf("Variavel 'i': %d\n", vet[j]);
           //printf("Variavel 'i+1': %d\n", vet[j+1]); 
           temp = vet[j+1];
           //printf("Variavel 'temp': %d\n", temp);
           vet[j+1] = vet[j];
           //printf("Variavel 'i+1': %d\n", vet[j+1]);
           vet[j] = temp;
           //printf("Variavel 'i': %d\n", vet[j]);
        }
        
    }
   }
   

    for (int i = 0; i <= 5; i++)
    {
        printf("%d, ", vet[i]);
    }
    
    return 0;
}