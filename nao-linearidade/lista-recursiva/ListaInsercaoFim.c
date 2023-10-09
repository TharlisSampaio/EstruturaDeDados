#include<stdio.h>
#include<stdlib.h>


struct ponto{
    float x;
    float y;
    struct ponto *prox; // alem te ter os pontos (x,y) terá um pronteiro aprondando para o proximo Struct
};

typedef struct ponto Ponto;

Ponto *listaPontos; // este ponteiro ira apontar para o primeiro elemento da lista
// a partir do primeiro irei acessar os demais

// adciona novo elemeno no inicio da lista
void addFirt(float x, float y){ // adciona no inicio da lista
    Ponto *p = (Ponto*) malloc((sizeof(Ponto))); // alocando as estruturas
    p->x = x;
    p->y = y;
    p->prox = listaPontos; // lincagem dos pontos para não se perder
    listaPontos = p;
}


// adciona novo elemeno no inicio da lista
void addLast(float x, float y){ // adciona no final da lista
    Ponto *p = (Ponto*) malloc((sizeof(Ponto))); // alocando as estruturas
    p->x = x;
    p->y = y;
    p->prox = NULL; // certaza que o prox sera NULL porque ele é o ultimo da lista
    if(listaPontos==NULL){ // verifica se o primeiro elemento é NULL
        listaPontos = p;
    }else{ // caso não seja NULL, tenho que pecorrer todo a lista até encontrar o proximo elemento que seja NULL
        Ponto *listaAux  = listaPontos; // listaAux aponta para o primeiro elemento
        while (listaAux->prox!=NULL)
        {
            listaAux = listaAux->prox;
        }
        listaAux->prox = p;
    }
}

void imprime(Ponto *p){
    if (p!=NULL)
    {
        printf("\nPont(%.2f,%.2f)",p->x, p->y);
        imprime(p->prox); // aplicando recursão
    }
}

int main(){
    addFirt(2.5, 3.2);
    addFirt(2,7);
    addFirt(4.33,8.92);
    addLast(9.23, 8.43);
    addLast(3.23, 0.43);

    Ponto *auxLista = listaPontos;
    imprime(auxLista);

    return 0;
}