#include<stdio.h>


// criação de ponteiro, deve informar o tipo (o tipo deve ser o mesmo da variavel)
int *ponteiro; // com * quer dizer que é um ponteiro
int val = 5;

int main(){

    ponteiro = &val; // estou apontando o ponteiro para val, ou seja, posso acessar o valor de val atraves do ponteiro
    printf("O valor apontado por 'ponteiro' é %d", *ponteiro);

    return 0;
}