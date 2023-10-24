#include<stdio.h>


int fatorial(int num){
    if(num <= 0){
        return 1;
    }else{
        return num*fatorial(num-1);
    }
}

int fib(int num){
    if(num <= 1){
        return 1;
    }else{
        return fib(num-1)+fib(num-2);
    }
}

int main(){
    int a = 0;
    int num;

    while (a==0){
        printf("\nDigite um valor x>=0: ");
        scanf("%d", &num);
        printf("\nfatorial de %d!=%d", num, fatorial(num));

        printf("\nPara encerrar o programa digite 1 ou 0 para continuar: ");
        scanf("%d", &a);
    }

    return 0;
}