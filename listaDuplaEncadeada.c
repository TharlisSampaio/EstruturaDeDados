// listaencadeada.c
#include <stdio.h>
#include <stdlib.h> // malloc, free

typedef struct no{    // criando a estrutura do nó
    int valor;        // valor do nó
    struct no *prox;  // ponteiro para o próximo nó
    struct no *ant;
}lista;
// inicializa uma lista dupla encadeada vazia
lista *criar_lista(){ // função para criar a lista
    return NULL;      // retorna NULL
}
// Aloca memória para um novo nó e atribui o valor a ele
// e NULL ao ponteiro do próximo nó
lista *criar_no(int valor){ // função para criar o nó
    lista *novo = (lista*)malloc(sizeof(lista)); // aloca memória para o novo nó
    novo->valor = valor;                          // atribui o valor ao novo nó
    novo->prox = NULL;                            // atribui NULL ao ponteiro do próximo nó
    novo->ant = NULL;
    return novo;                                  // retorna o novo nó
}

lista *inserir(lista *l, int valor){ // insere um nó no início da lista
    lista *novo = criar_no(valor);    // cria um novo nó
    if(l == NULL){
      printf("\nLisata vaziz!");
      exit(1);
    }
    novo->prox = l;                   // o ponteiro do próximo nó aponta para o primeiro nó da lista
    l->ant = novo;
    return novo;                      // retorna o novo nó
}

lista *insere_inicio(lista *l, int valor){
    lista *novo = criar_no(valor);    // cria um novo nó
    novo->prox = l;                   // o ponteiro do próximo nó aponta para o primeiro nó da lista
    l->ant = novo;                        // o primeiro nó da lista aponta para o novo nó
    l = novo;
    return l;      // retorna a lista atualizada
}

void imprimir(lista *l){
  lista *aux = l; // cria um nó auxiliar para percorrer a lista
  while(aux!=NULL){
    printf("%d ", aux->valor); // imprime o valor do nó
    aux = aux->prox;           // o nó auxiliar aponta para o próximo nó
  }
}

void imprime_recusiva(lista *l){ 
  if(l!=NULL){
    printf("%d ", l->valor); // imprime o valor do nó
    imprime_recusiva(l->prox);   // chama a função recursivamente para o próximo nó
  }
} 

lista *buscar(lista *l, int valor){
  lista *aux = l;
  while(aux!=NULL && aux->valor !=valor)
    aux = aux->prox;
  if (aux!=NULL){
    printf("\nVALOR ENCONTRADO");
  }else
    printf("\nVALOR NÃO ENCONTRADO");
  return aux;
}

lista *excluir(lista *l, int valor){
  lista *aux = l, *ant = NULL;
  while(aux!=NULL && aux->valor!=valor){ 
    ant = aux;
    aux = aux->prox;
  }
  if (aux != NULL){
    if (ant == NULL){ // se queremos excluir o primeiro nó
     l = aux->prox;
     l->ant = NULL;
    }
    else{
      aux->prox->ant = aux->prox;
      aux->ant->prox = aux->prox;     
    }
    free(aux);
  }
  return l;
}
// Exercícios para implementar
// 1. Escreva uma função recursiva que imprima os valores de uma lista encadeada em ordem inversa
// 2. Escreva uma função que remova um elemento de uma lista encadeada
// 3. Escreva uma função que retorne o tamanho de uma lista encadeada
int tamanho(lista *l){
  if (l!=NULL){
    return 1+ tamanho(l->prox);
  }
  return 0;
}
int tamanho_i(lista *l){
  int tam = 0;
  lista *aux = l;
  while(aux != NULL){
    tam++;
    aux = aux->prox;
  }
  return tam;
}

// 4. Escreva uma função que retorne o valor máximo de uma lista encadeada
int maximo(lista *l){
    lista *aux = l;
    int max ;
    if (aux!=NULL){
      max = aux->valor;
    }
    aux = aux->prox;
    while(aux!= NULL){
      if (aux->valor > max)
        max  = aux->valor;
      aux = aux->prox;
    }
    return max;
}

// 5. Escreva uma função que retorne o valor mínimo de uma lista encadeada
int minimo(lista *l){
    lista *aux = l;
    int min ;
    if (aux!=NULL){
      min = aux->valor;
    }
    aux = aux->prox;
    while(aux!= NULL){
      if (aux->valor < min)
        min  = aux->valor;
      aux = aux->prox;
    }
    return min;
}
// 6. Escreva uma função que retorne a média dos valores de uma lista encadeada
float media(lista *l){
  int tam = 0, soma = 0;
  lista *aux = l;
  if (aux == NULL){
    printf("\nLISTA VAZIA");
    return 0;
  }
  while(aux!= NULL){
    tam++;
    soma = soma + aux->valor;
    aux = aux->prox;
  }
  return (float)soma/tam;
}
// 8. Escreva uma função que retorne o valor que está na posição n de uma lista encadeada
// val = valor_pos(l, n);
// int valor_pos(lista *l, int n){

// }
// 9. Escreva uma função que retorne o valor que está na última posição de uma lista encadeada
// 10. Escreva uma função que retorne o valor que está na primeira posição de uma lista encadeada
// 11. Escreva uma função que retorne o valor que está na penúltima posição de uma lista encadeada
// 13. Escreva uma função que retorne o valor que está na posição n a partir do final de uma lista encadeada
// 14. Escreva uma função que retorne o valor que está na posição n a partir do início de uma lista encadeada
// 15. Escreva uma função que retorne o valor que está na posição n a partir de um nó de uma lista encadeada
// 16. Escreva uma função que retorne o valor que está na posição n a partir do último nó de uma lista encadeada
// 17. Escreva uma função que retorne o valor que está na posição n a partir do primeiro nó de uma lista encadeada
// 18. Escreva uma função que retorne o valor que está na posição n a partir do penúltimo nó de uma lista encadeada
// 19. Crie uma função que receba uma lista encadeada e retorne o valor da moda da lista.
// 20. Crie uma função que receba uma lista encadeada e um valor e retorne a quantidade de vezes que o valor aparece na lista.
// 21. Crie uma função que receba uma lista encadeada e um valor e retorne a posição da primeira ocorrência do valor na lista.
// 22. Crie uma função que receba uma lista encadeada e um valor e retorne a posição da última ocorrência do valor na lista.
// 23. Crie uma função que receba duas listas encadeadas e retorne uma lista com a concatenação das duas listas.
// 24. Crie uma função que receba uma lista encadeada e um valor e retorne uma lista com os valores menores que o valor recebido.
// 25. Crie uma função que receba uma lista encadeada e um valor e retorne uma lista com os valores maiores que o valor recebido.
// 26. Crie uma função que receba uma lista encadeada e um valor e retorne uma lista com os valores iguais ao valor recebido.
// 27. Crie um programa em C, que receba um arquivo de texto e produza uma lista com 
//     todas as palavras contidas nele e as posições que
//     cada uma delas ocorre

lista *liberar(lista *l){
  lista *aux = l;
  while(aux!=NULL){
    l = aux->prox;
    free(aux);
    aux = l;
  }
  return NULL;
}
int main(void){
  lista *l = criar_lista();
  l = inserir(l, 10); 
  l = inserir(l, 20);
  l = inserir(l, 30);
  l = inserir(l, 40);
  l = inserir(l, 50);
  l = inserir(l, 60);
  l = inserir(l, 70);
  l = inserir(l, 80);
  imprimir(l);
  printf("\n");
  l = excluir(l, 10);
  imprimir(l);
  imprime_recusiva(l);
  printf("\n");
  l = liberar(l); // libera a memória alocada para a lista

  return 0;
}