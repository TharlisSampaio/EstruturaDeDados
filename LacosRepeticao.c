#include<stdio.h>


int main(){

    int a=0;

    printf("\nLaço While\n"); // pode ser definido ou não
    while (a<5) // condição a ser testada
    {
        printf("\nA variavel a=%d", a);
        a++; // a = a + 1;
    }

    printf("\nLaço For\n");
    for (int i=0; i<5; i++) // for(inicializa; teste; incrementa)
    {
        printf("\nO valor de i=%d", i);
    }
    
    return 0;
}