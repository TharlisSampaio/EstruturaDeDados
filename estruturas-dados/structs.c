#include<stdio.h>


struct pessoa
{
    int idade;
    float altura;
};

// typedef: permite definir (ou redefinir) um tipo de dado
typedef struct pessoa Pessoa;


int main(){

    // Criei uma variavel do tipo struct pessoa
    Pessoa p;

    p.idade = 24;
    p.altura = 1.63;

    printf("\nA idade da pessoa e: %d", p.idade);
    printf("\nA altura da pessoa e: %.2f", p.altura);

}
