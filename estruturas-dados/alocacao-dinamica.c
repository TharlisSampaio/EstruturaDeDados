#include<stdio.h>
#include<stdlib.h>


struct ponto{
    float x;
    float y;
};

typedef struct ponto Ponto;

int main(){

    // malloc() faz alocação dinamicament na memoria livre (heap), em tempo de execução
    // sizeof() determina o tamanho de um tipo
    Ponto *p = (Ponto*) malloc(sizeof(Ponto)); // conversão do Ponto em ponteiro
    p->x = 5.5;
    p->y = 3.53;
    printf("Ponto = (%.2f, %.2f)", p->x, p->y);
    return 0;
}