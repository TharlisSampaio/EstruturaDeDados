#include<stdio.h>
#include<stdlib.h>

/*
    Um algoritmo de ordenação com complexidade nlogn é aquele que pode
    ordenar uma lista de tamanho n em tempo proporcional a nlogn.
    Algoritmo de ordenação com complexidade n^2 são aqueles que realizam
    cerca de n^2 comparações para ordenar um arranjo com N elementos.
*/

void merge(int *V, int inicio, int meio, int fim);

#define Num 13
// int V[13] = {10, 1, 20, 3, 7, 40, 30, 4, 17, 45, 18, 30, 17};

// algoritmo de ordenação Bubble Sort
void bubbleSort(int V[], int N){ // revebe um vetor, e o tamanho dele
    int i, continua, aux, fim = N;

    do {
        continua = 0;

        for(i = 0; i < fim-1; i++){
            if(V[i] > V[i+1]){ // compara elemento atual com o proximo se (atual > proximo) então troca
                aux = V[i];
                V[i] = V[i+1]; // posisão do atual recebe o proximo
                V[i+1] = aux; // e a posição do proximo elemento recebe o atual
                continua = i; // continua recebe i, somente se a condição se satisfazer!, para que o do while não pare ate pecorrer todo array
            }
        }
        fim--;

    } while (continua != 0);
    

}

// algoritmo de ondernação Insertion Sort
void insertionSort(int V[], int N){ // recebe um vetor, e seu tamanho
    int i, j, aux;

    for(i = 1; i < N; i++){ // pecorre o vetor começando do segundo elemento do array
        aux = V[i]; // minha variavel aux ira reveber um elemento do vetor 
        for(j = i; (j > 0) && (aux < V[j - 1]); j--){ // j > 0 para que V[j - 1] não acesse um elemento que não exista,
                                                    // aux recebe o valor a ser inserido no vetor, e aux < V[j -1] se satisfazer
                                                    // desloca todos elementos que for maior que a posição que esta analisando e
                                                    // insere aux na frente posição que ele pe menor
            V[j] = V[j - 1];
        }
        V[j] = aux;
    }

}


/*
    A cada passo, procura o menor valor do vetor e coloca na primeira posição do vetor
    Descarta-se a primeira posição do vetor e repete-se o processo para segunda posição
    Isso é feita para todas as posições do vetor
*/
void selectionSort(int V[], int N){ // recebe um vetor, e seu tamanho
    int i, j, menor, troca;
    for(i = 0; i < N - 1; i++){ // pecorrer todo o vetor V, N - 1 para o segundo for não utrapassar o tamanho de V
        menor = i;
        for(j = i + 1; j < N; j++){ // ira procura o menor elemento em relação 'i'
            if(V[j] < V[menor]){
                menor = j;
            }
        }

        if(i != menor){ // troca os valores da posição atual com a 'menor'
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }

    }
}

/*
    Dividir e conquistar: divide, recursivamente, o conjunto de dados até que cada subconjunto possua 1 elemento
    Combina 2 subconjunto de do forma a obter 1 conjunto maior e ordenado
    Esse processo se repete até que exista apenas 1 conjunto.
*/
void mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio+fim)/2;
        mergeSort(V, inicio, fim);
        mergeSort(V, inicio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}

void imprimeVetor(int V[], int N){
    for(int i = 0; i < N; i++){
        printf("%d ", V[i]);
    }
}

int main(){
    int vetor[13] = {10, 1, 20, 3, 7, 40, 30, 4, 17, 45, 18, 30, 17};
    bubbleSort(vetor, 13);
    imprimeVetor(vetor, Num);

    return 0;
}


void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    temp = (int*) malloc(tamanho*sizeof(int));

    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2])
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];

                if(p1 > meio) fim1 = 1;
                if(p2 > meio) fim2 = 1;

            }else{
                if(!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];
            }
        }

        for(j = 0, k = inicio; j < tamanho; j++, k++){
            V[k] = temp[j];
        }

    }

    free(temp);
}
