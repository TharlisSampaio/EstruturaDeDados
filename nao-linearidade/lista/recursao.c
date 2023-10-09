#include<stdio.h>


// Em uma função recursiva, vou ter a chamada da função dentro dela mesma
int potencia(int base, int ep){

    if (ep==1)
    {
        return base;
    }
    return base*potencia(base, ep-1);
}

int main(){
    int v = potencia(2,4); //16
    printf("%d", v);
    return 0;
}