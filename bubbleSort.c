#include<stdio.h>
#include<stdlib.h>

#define N 10

void lerVetor(int A[], int n){
    for (int i=0; i<n; i++)
        A[i] = rand()%n;
}

void imprimeVetor(int vetor[], int n){
    for (int i = 0; i < n; i++){
        printf( "%d ", vetor[i]);
    }
    printf("\n");
    
}

void troca(int A[], int i, int j){
    int temp;
    temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

void bubbleSort(int vetor[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (vetor[j]>vetor[j+1]){
                troca(vetor, j, j+i);
            }
        }
        
    }
    
}

int main(){
    int vetor[N];
    lerVetor(vetor, N);
    imprimeVetor(vetor, N);
    bubbleSort(vetor, N);
    imprimeVetor(vetor, N);

    return 0;
}
