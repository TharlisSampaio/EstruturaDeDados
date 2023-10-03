#include<stdio.h>


int main(){
    float num, soma;

    printf("\nDigite um numero:\n");
    scanf("%f", &num); // devo informar qual o tipo de dado, & informar em qual variavel sera armazenado o dado

    printf("\nO valor da variavel num: %.2f", num);

    return 0;
}