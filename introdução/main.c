#include<stdio.h>

// tipagem do C é forte, tenho informar o tipo da variável
int a = 5; // variaveis fora do escopo da main, são vairiveis do escopo global
float b = 2.6;
double c = 3.8; // para maior precisão
char ch = 'c'; //

int main(){
    printf("hello meu chapa\n");
    printf("valor da variavel a: %d\n", a); // %d o porcente precende uma saída
    printf("valor da variavel b:%.2f\n", b); //%.2f apos o . devo informar quantas casas tera apos a virgula
    printf("valor da variavel ch:%c", ch);

    return 0;
}