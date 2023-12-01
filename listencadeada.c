#include<stdio.h>
#include<stdlib.h> // rand()

#define N 10
/*
void leVetor(int A[], int n){
    int i;
    for (i=0;i<n;i++){
       // A[i] =  rand()%n;
       scanf("%d", &A[i]);
    }
}
void imprime(int vetor[], int n){
    int i;
    printf("\n");
    for (i=0;i<n;i++)
        printf(" %d ",vetor[i]);
}
void troca(int A[], int i, int j){
    int temp;
    temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

void bolha(int vetor[], int n){
    int i, j, trocou = 1;
    for ( i = 0;i<n && trocou;i++){   // O(n)
        trocou = 0;                   // O(1)
        for (j = 0; j<n-1-i;j++)      // O(n)
            if (vetor[j]>vetor[j+1]){
                troca(vetor, j, j+1);
                trocou =1;
            }
    }
    // O(n)xO(n) = O(n^2)
    
    printf("\n i = %d", i);
}
void selecao(int vetor[], int n){
    int i, j, menor;
    for ( i=0;i<n;i++){
        menor = i;
        for (j = i+1;j<n;j++){
            if (vetor[j] < vetor[menor])
                menor = j;
        }
        troca(vetor, i, menor);
    }
}
void insercao(int vetor[], int n){
int novo, j;
	for (novo=1;novo<n;novo++){
    		if (vetor[j] < vetor[j-1]){
        			troca(vetor, j, j-1);
    		}
	imprime(vetor, n);
	}
}
void mergeSort(int vetor[], int inicio, int fim){
	int meio = (inicio + fim)/2;
	if (inicio < fim){//mais de um elemento
    		mergeSort(vetor, inicio, meio);
    		mergeSort(vetor, meio+1, fim);
    		intercala(vetor, inicio, meio, fim);
	}
}
void intercala(int vetor[], int inicio, int meio, int fim){
	// quantos elementos tem o vetor?
    	int n = f - i + 1;
	int *w;
	w = (int *)malloc(sizeof(int)*n);
}

int main(){
    int vetor[N];
    leVetor(vetor, N);
    imprime(vetor, N);
    // bolha(vetor, N);
    selecao(vetor, N);
    imprime(vetor, N);
    return 0;-+
}
'''
*/

// “*a” e “a[]” é o mesmo na declaração de parâmetros em uma função.


// listaencadeada.c 24/11/2023
#include <stdio.h>
#include <stdlib.h> // malloc, free

// typedef define tipos
typedef struct no{  // criando a estrutura do nó
	int valor;  	// valor do nó
	struct no *prox;// ponteiro para o próximo nó
}lista;

lista *criar_lista(){ // função para criar lista
	return NULL;  	// retorna NULL
}

lista *criar_no(int valor){ // função para criar nó
	lista *novo = (lista*)malloc(sizeof(lista)); // aloca memória para o novo nó
	novo->valor = valor;                     	// atribui o valor para o novo nó
	novo->prox = NULL;                       	// atribui NULL ao ponteiro do prox
	return novo;                             	// retorna o novo nó
}

lista *inserir(lista *l, int valor){// insere um nó no inicio da lista
	lista *novo = criar_no(valor);  // cria um novo nó
	novo->prox = l;             	// o ponteiro do proximo nó aponta para ao primeiro
	return novo;                	// retorna o nó
}

lista *insere_inicio(lista *l, int valor){
	lista *novo = criar_no(valor);
	novo-> prox = l;
	l = novo;
	return l;
}
int tamanho_i(lista *l){
    int tam = 0;
    lista *aux = l;
    while(aux !=NULL){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

float mediaList(lista *l){
    int soma = 0, tam = 0;
    lista *aux = l;
    if(aux == NULL){
        printf("A lista e NULL");
    }else{
        while (aux != NULL){
            soma += aux->valor;
            tam++;
            aux = aux->prox;
        }
        
    }
    return (float)soma / tam;
}

int valorPosin(lista *l, int posicao){
    int index = 1;
    lista *aux = l;
    if(aux == NULL){
        printf("Lista nula");
    }else{
        while (aux != NULL){
            if(index == posicao)
                return aux->valor;
            index++;
        }
        
    }
}

void imprimir(lista *l){
	lista *aux = l;             	// cria um nó auxiliar para percorrer a lista
	while(aux!=NULL){
    	printf("%d", aux->valor);   // imprime o valor do nó
    	aux = aux->prox;         	// o nó auxiliar aponta para o próximo nó
	}
}
