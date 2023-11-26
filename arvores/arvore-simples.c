#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int valor;
    struct nodo *esquerdo;
    struct nodo *direito;
};

typedef struct nodo Nodo;

Nodo* create(int valor){
    Nodo *n = (Nodo*) malloc(sizeof(Nodo));
    n->valor = valor;
    n->esquerdo = NULL;
    n->direito = NULL;
    return n;
}

void addNodo(Nodo *n, int valor){
    if(valor < n->valor){
        if(n->esquerdo == NULL)
            n->esquerdo = create(valor);
        else
            addNodo(n->esquerdo, valor); 
    }else{
        if(n->direito == NULL)
            n->direito = create(valor);
        else
            addNodo(n->direito, valor);
    }
}

void removeNodo(Nodo *n, int valor){
    Nodo *filho = n;
    Nodo *pai;

    do{
        pai = filho;
        if(valor < filho->valor)
            filho = filho->esquerdo;
        else if(valor > filho->valor)
            filho = filho->direito;
    } while (filho != NULL && filho -> valor != valor);
    
    if(filho != NULL){
        if(filho->esquerdo == NULL && filho->direito == NULL){
            if(pai->esquerdo == filho) pai->esquerdo = NULL;
            if(pai->direito == filho) pai->direito = NULL;
        }

        if(filho->esquerdo != NULL && filho->direito == NULL){
            if(pai->esquerdo == filho) pai->esquerdo = filho->esquerdo;
            if(pai->direito == filho) pai->direito = filho->esquerdo;
        }
        if(filho->direito != NULL && filho->esquerdo == NULL){
            if(pai->esquerdo == filho) pai->esquerdo = filho->direito;
            if(pai->direito == filho) pai->direito = filho->direito;
        }

        if(filho->esquerdo != NULL && filho->direito != NULL){
            if(filho->esquerdo->direito == NULL){
                filho->valor = filho->esquerdo->valor;
            }else{
                Nodo *p = filho->esquerdo;
                Nodo *aux = p;
                while(p->direito != NULL){
                    aux = p;
                    p = p->direito;
                }
                aux->direito = NULL;
                filho->valor = p->valor;
            }
        }

    }
}

void imprimirArvore(Nodo *n){
    if(n==NULL)
        return;
    
    imprimirArvore(n->esquerdo);
    printf("\n%d", n->valor);
    imprimirArvore(n->direito);
}
int main(){
    Nodo *root = create(5);
    addNodo(root, 3);
    addNodo(root, 1);
    addNodo(root, 4);
    addNodo(root, 2);
    addNodo(root, 8);
    removeNodo(root, 3);

    imprimirArvore(root);

    return 0;
}
