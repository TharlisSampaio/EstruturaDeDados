#include<stdio.h>
#include<stdlib.h>


struct ponto{
    float x;
    float y;
    struct ponto *prox; // alem te ter os pontos (x,y) terá um pronteiro aprondando para o proximo Struct
};

typedef struct ponto Ponto;

Ponto *listaPonteiro; // este ponteiro ira apontar para o primeiro elemento da lista
// a partir do primeiro irei acessar os demais

// adciona novo elemeno no inicio da lista
void add(float x, float y){
    Ponto *p = (Ponto*) malloc((sizeof(Ponto))); // alocando as estruturas
    p->x = x;
    p->y = y;
    p->prox = listaPonteiro; // lincagem dos pontos para não se perder
    listaPonteiro = p;
}

void imprime(Ponto *p){
    if (p!=NULL)
    {
        printf("\nPont(%.2f,%.2f)",p->x, p->y);
        imprime(p->prox); // aplicando recursão
    }
}

int main(){
    add(2.5, 3.2);
    add(2,7);
    add(4.33,8.92);

    Ponto *auxLista = listaPonteiro;
    imprime(auxLista);

    return 0;
}