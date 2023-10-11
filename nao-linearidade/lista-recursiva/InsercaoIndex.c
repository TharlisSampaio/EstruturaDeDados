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

int length = 0;

void addIndex(float x, float y, int index){
    Ponto *p = (Ponto*) malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;

    if(index>length){
        printf("Posição invalida");
    }else{
        if(index==0){ // aponta o ponteiro inicia para o novo primeiro elemento
            p->prox = listaPontos; // o antigo primeiro elemento passa a ser o segundo
            listaPontos = p; // e o novo elemento passa a ser o primeiro
        }else{
            // vou pecorrer para adicionar em determinada posição
            Ponto *listaAux = listaPontos;
            int i=0;
            while(i!=index-1){
                listaAux = listaAux->prox;
                i++;
            }
            p->prox = listaAux->prox;
            listaAux->prox = p;
        }
        length++;
    }
}

void removeIndex(int index){
    if (index>length || length==0){
        printf("Posisao invalida ou lista vazia");
    }else{
        if (index==0){
            listaPontos = listaPontos->prox;
        }else{
            Ponto *listaAux = listaPontos;
            int i=0;
            while (i!=index-1){
                listaAux = listaAux->prox;
                i++;
            }
            listaAux->prox = listaAux->prox->prox;
        }
        length--;
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
    addIndex(0,0,0);
    addIndex(2,9,1);
    addIndex(4,3,2);
    addIndex(6,7,2);

    removeIndex(0);
    removeIndex(0);

    Ponto *auxLista = listaPontos;
    imprime(auxLista);

    return 0;
}