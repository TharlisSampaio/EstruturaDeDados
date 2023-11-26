/*
1) Faça a descrição textual do método de ordenação da bolha e discuta qual a complexidade da função bolha, apresentada em sala de aula
É uma algoritmo para organizar de maneira correta uma sequencia de elementes de um vetor, ele compara cada elemento com seu adjacente,
e se estiverem em fora de ordem ele ira trocar os elementos, o algoritmo BubbleSort tem complexidade n^2.
2) Faça um programa em C , usando funções, que implemente uma variação do método da bolha e duscuta a complexidade dessa nova implementação:
a)a cada passo, da interação mais externa, leve o menor elemento para o início do vetor.
b) a cada passo da interação leve o menor elemento para o início do vetor e o maior para o final.
*/

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
    for (int i = n; i >= 0; i--){
        for (int j = n; j >= 0+i+1; j--){
            if (vetor[j]<vetor[j-1]){
                troca(vetor, j-1, j);
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