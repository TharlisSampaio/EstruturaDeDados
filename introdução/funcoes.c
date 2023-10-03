#include<stdio.h>


int soma(int a, int b){
    int s = a + b;
    return s;
}

int sub(int a, int b){
    int s = a - b;
    return s;
}

int main(){

    int n1, n2, op, res;
    int fim = 0;

    while (fim==0)
    {
        printf("\nDigite um valor: ");
        scanf("%d", &n1);
        printf("Digite um valor: ");
        scanf("%d", &n2);

        printf("\nEscolha a operacao\n1 - Adicao\n2 - Subtracao\n");
        scanf("%d", &op);

        if(op==1){
            res = soma(n1, n2);
        }
        if(op==2){
            res = sub(n1, n2);
        }


        printf("O resultado: %d", res);

        printf("\nPara encerra digite 1\n");
        scanf("%d", &fim);
    }
    


    return 0;
    
}