// Em filas todo novo elemento é sempre adciondado no final da fila
// e so podemos remover o primeiro elemnto da fila e 
// não podemos adicionar qualquer outro elemento do meio da fila

#include<stdio.h>
#include<stdlib.h>

struct pessoa
{
    int senha;
    struct pessoa *prox;
    
};

typedef struct pessoa Pessoa;

Pessoa *fila;

void add(int senha){
    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
    p->senha = senha;
    p->prox = NULL;

    if(fila == NULL){
        fila = p;
    }else{
        Pessoa *filaAux = fila;
        while (filaAux->prox != NULL)
        {
            filaAux = filaAux->prox;
        }
        filaAux->prox = p;
    }

}

void remover(){
    if (fila == NULL){
        printf("Fila vazia");
    }else{
        fila = fila->prox;
    }
    
}

void imprime(Pessoa *f){
    if (f != NULL){
        printf("\nA senha da pessoa e: %d", f->senha);
        imprime(f->prox);
    }
    
}

int main(){
    Pessoa *listaAux = fila;

    add(3);
    add(5);
    add(7);
    add(9);
    add(11);
    add(13);

    imprime(fila);
    printf("\n");

    remover();
    remover();

    imprime(fila);
    printf("\n");

    remover();
    remover();

    imprime(fila);
    printf("\n");
    
    return 0;
}
