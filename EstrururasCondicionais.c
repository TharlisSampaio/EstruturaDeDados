#include<stdio.h>


int main(){

    int a;
    printf("Digite um valor:\n");
    scanf("%d", &a);

    if (a==0) //condição
    {
        printf("A variavel 'a' é igua a %d", a);
    }else // se não
    {
        printf("A variavel 'a' é diferente de 0");
    }
    

    return 0;
}