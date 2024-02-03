#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
    struct no *ant;
}lista;

// inicializa uma lista dupla encadeada vazia
lista *criar_lista(){
    return NULL;
}

void imprimir(lista *l){
  lista *aux = l; // cria um nó auxiliar para percorrer a lista
  if (aux == NULL){
    printf("Lista VAZIA");
  }else{
    do{
      printf("%d ", aux->valor);
      aux = aux->prox;
    } while (aux != l);

    // while(aux != l){
    //   printf("%d ", aux->valor);
    //   aux = aux->prox;
    // }
    
  }
  
}

lista *cria_no(int valor){
    lista *novo = (lista*)malloc(sizeof(lista));
    if(novo == NULL){
        printf("\nFalha na alocação de mémoria");
        exit(1);
    }
    novo->valor = valor;
    novo->ant = novo;
    novo->prox = novo;
    return novo;
}

lista *inserir_inicio(lista *l, int valor){
  lista *novo = cria_no(valor);

  if(novo == NULL){
    printf("Falha de alocação de mémoria");
    exit(1);
  }

  if (l != NULL){
    novo->ant = l->ant;
    l->ant->prox = novo;
    novo->prox = l;
    l->ant = novo;
  }

  return novo;
}

lista *inserir_fim(lista *l, int valor){
  lista *novo = cria_no(valor);

  if (l != NULL){
    novo->prox = l->prox;
    l->prox->ant = novo;
    novo->ant = l;
    l->prox = novo;
  }
  
  return novo;
}

int main(void){
  lista *l = criar_lista();

  l = inserir_inicio(l, 10);
  l = inserir_inicio(l, 20);
  l = inserir_fim(l, 30);
  // l = inserir_inicio(l, 40);
  // l = inserir_inicio(l, 50);
  // l = inserir_inicio(l, 60);
  // l = inserir_inicio(l, 70);
  // l = inserir_inicio(l, 80);
  // l = inserir_fim(l, 90);
  imprimir(l);

  free(l);

  return 0;
}