#include<stdlib.h>
#include <stdio.h>

void Intercala (int inicio, int meio, int fim, int v[]) {
	int prim, // índice do início do primeiro vetor
     seg, // índice do início do segundo vetor 
     res, // posição livre no vetor temporário w     
     *w;  // vetor temporário w
	// alocação de memória para o vetor temporário w
    w = (int*)malloc ((fim-inicio+1) * sizeof (int));
    if (w == NULL) {
       printf ("Erro: Memória Insuficiente\n");
       exit (1);
    }

	prim = inicio; // índice do início do primeiro vetor
     seg = meio+1; // índice do início do segundo vetor
      res = 0; // posição livre no vetor temporário w

	while (prim <= meio && seg <= fim ) {
	   if (v[prim] <= v[seg]) 
          w[res++] = v[prim++];
       else w[res++] = v[seg++];
	}
	while (prim <= meio) // copia o que resta do primeiro vetor 
	    w[res++] = v[prim++];
	while (seg <= fim) // copia o que resta do segundo vetor
	    w[res++] = v[seg++]; 

    // descarregue os elementos do vetor temporário W no vetor V
	for (prim = inicio, res = 0; prim <= fim; prim++,res++) 
        v[prim] = w[res];
    /*
        prim = inicio;
        res = 0;
        while (prim <= fim){
            v[prim++] = w[res++];
        }
    */
	free (w);
}

/*
Nome: Mergesort
*/
void Mergesort (int inicio, int fim, int v[]) {
	if (inicio < fim) {
	   int meio = (inicio + fim)/2;
	   Mergesort (inicio, meio, v);
	   Mergesort (meio+1, fim, v);
	   Intercala (inicio, meio, fim, v);

   }
}

/*
Ordenação por Inserção

O algoritmo funciona da seguinte maneira:

1 - Começando da posição 1, percorre-se cada elemento da lista.
2 - Para cada elemento, o algoritmo compara o elemento atual com 
os elementos anteriores na lista, de forma a encontrar a posição 
correta do elemento atual na lista ordenada.
3 - Para inserir o elemento atual na posição correta, o algoritmo 
desloca todos os elementos maiores do que o elemento atual para a 
direita, abrindo espaço para o elemento atual na posição correta.
4 - O algoritmo repete o passo 2 e 3 para cada elemento da lista, 
até que a lista esteja completamente ordenada.

for i = 1 to n-1
    j = i
    while j > 0 and A[j-1] > A[j]
        swap A[j] and A[j-1]
        j = j - 1
*/


void troca(int A[], int i, int j){
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void insercao(int A[], int n){
    int i, j;
    for ( i = 1; i<n;i++ )    {
        j = i;
        while (j > 0 && A[j-1] > A[j] ){
            troca(A,j,j-1);
            j =  j -1;
        }
    }
}

void imprime(int A[], int n, char *msg){
    printf("\n%s\nA[", msg);
    for (int i=0;i<n;i++){
        printf("%d",A[i]);
        if (i<n-1)
            printf(",");
    }
    printf("]");
}

int particiona(int inicio, int fim, int A[]){
    int pivo, i, j;
    pivo = A[fim];
    printf("\nInicio = %d", inicio);
    printf("\nFim = %d", fim);
    //código em C para mudar a cor do pivo
    printf("\033[1;33m");
    printf("\n\nPivo = %d", pivo);
    printf("\033[0m");
    
    j = inicio; //j é a posição do pivo
    for (i = inicio; i<fim;i++){
        if ( A[i] < pivo){
                troca(A,i,j);
                printf("\n\tTroca A[%d] = %d com A[%d] = %d", i, A[i], j, A[j]);
                j = j + 1;
        }
    }
    A[fim] = A[j];
    A[j] = pivo;
    return j;
}

void quickSort(int inicio, int fim, int A[]){
    int pos_pivo;
    if (inicio < fim){
        pos_pivo = particiona(inicio, fim, A);
        quickSort(inicio, pos_pivo-1, A);
        quickSort(pos_pivo+1,fim, A);
    }
}

void carregaVetor(int A[], int n){
    for ( int i = 0; i<n;i++){
        A[i] = rand()%n;
    }
}

int main(){   int *A,
         n;
    printf("\nQuantos valores?");
    scanf("%d",&n);
    A = (int*)malloc(sizeof(int)*n);
    
    carregaVetor(A, n);    
    imprime(A,n,"\nAntes de Ordenar");
    //insercao(A,n);
    //Mergesort (0, n-1, A);
    quickSort( 0, n-1,A);
    imprime(A,n,"\nDepois de ordenar");

    return 0;
}