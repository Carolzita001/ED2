#include <stdio.h>

int main(){
    int A [12] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};// 'n' é igual a 6!
    int n = 12;

    for (int i = 0; i < n-1; i++){

        int menor_indice = i;

        for (int j = i+1; j < n; j++)
        {
            if (A[j]<A[menor_indice])
            {
                menor_indice = j;
            }
        }

        int temp = A[i];
        A[i] = A[menor_indice];
        A[menor_indice] = temp;
    }
    
   for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    return 0;
}