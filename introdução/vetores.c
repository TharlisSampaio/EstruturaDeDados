#include<stdio.h>


int v[4];
float vet[3];


int main(){
    v[0]=43;
    v[1]=44;
    v[2]=483;
    v[3]=3;

    for(int i=0;i<4;i++){
        printf("\nDigite um valor par o vet[%d]",i);
        scanf("%f", &vet[i]);
    }
    for(int i=0;i<4;i++){
        printf("\nValor armazenado na posicao vet[%d]=%.2f",i, vet[i]);
    }

}