#include<stdio.h>


int matriz[2][2];

int main(){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("\nDigite um numero para posicao matriz[%d][%d] = ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("\nmatriz[%d][%d] = %d", i, j, matriz[i][j]);
        }
    }

    return 0;
}