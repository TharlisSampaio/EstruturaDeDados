// Em Pilha todo novo elemento é adicionado no topo da pilha e 
// para remover sempre será removido o elemento que esta no topo da pilha

#include<stdio.h>
#include<stdlib.h>

struct prato{
    char cor;
    struct prato *prox;
};

typedef struct prato Prato;

Prato *pilha;

void imprime(Prato *p){
    if (p != NULL){
        printf("\nCor do prato e: %c", p->cor);
        imprime(p->prox);
    }
    
}

void add(char cor){
    Prato *p = (Prato*) malloc(sizeof(Prato));
    p->cor = cor;
    p->prox = pilha;
    pilha = p;
}

void remove(){
    if (pilha == NULL){
        printf("Pilha esta vazia");
    }else{
        pilha = pilha->prox;
    }
    
}

int main(){
    add('a');
    add('b');
    add('c');
    add('d');
    remove();

    Prato *pilhaAux = pilha;

    imprime(pilhaAux);

    return 0;
}
