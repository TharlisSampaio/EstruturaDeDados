#include<stdio.h>


int multiplica(int a, int b);

int main(){
    // int a, b;
    // int parar = 0;

    // while(parar == 0){
    //     printf("\nMultiplicacao de inteiros nao negativos");
    //     printf("\nDigite A e B serparados por espaco: ");
    //     scanf("\n%d %d", &a, &b);
    //     printf("\n%d x %d = %d", a, b, multiplica(a,b));
    //     printf("\nDigite 1 para encerrar ou 0 para continuar o programa: ");
    //     scanf("\n%d", &parar);
    // }

    int a[10], i, soma;

    for (i=0; i<10;i++){
        scanf("%d", &a[i]);
    }

    return 0;
}

/*Funções recursivas
 exercicio
 1) faça uma funçao recursiva para
 a) Multiplicar dois numeros inteiros A e B
 b) Calcular a soma dos elementos de um vetor de inteiros
*/

//Multiplicar dois numeros inteiros A e B
int multiplica(int a, int b){
    if (b>0){
        return a+multiplica(a, b-1);
    }else{
        return 0;
    }
    
}

int mdc(int a, int b){
    if( a > b){
        return mdc(a-b, b);
    }else{
        if( a < b ){
            return mdc(a, b-a);
        }else
            return a;
    }
}

// Somatorio dos elementos de um vetor, passando o vetor e o tamanho
int soma(int a[], int n){
    if (n>0){
        return a[n-1]+soma(a, n-1);
    }else
        return 0;
}
