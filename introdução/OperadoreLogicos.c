#include<stdio.h>


int main(){

    int a, b, c;
    printf("Digite um numero:\n");
    scanf("%d", &a);
    printf("Digite um numero:\n");
    scanf("%d", &b);
    printf("Digite um numero:\n");
    scanf("%d", &c);
    
    // && operador lógico E
    // || operador lógico OU
    // !  operador lógico NÃO

    if (a==b && b==c)
    {
        printf("Os valores de 'a', 'b' e 'c' são iguais");
    }
    

    return 0;
}