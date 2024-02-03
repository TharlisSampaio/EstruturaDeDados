#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
  ÁRVORES BINÁRIAS DE BUSCA
 
*/

typedef struct no{
  int valor;
  struct no *esq; // filho da esquerda
  struct no *dir; // filho da direita  
}ABB;
// prototipação
ABB *cria_no(int valor);

ABB *insere(ABB *raiz, int valor);

ABB *excluir(ABB *raiz, int valor);

void imprimir(ABB *raiz);

int altura(ABB *raiz); // exerc

int contaFolha(ABB *raiz); // exerc
// caminhamentos em árvores binárias
void ordemCentral(ABB *raiz);
void posOrdem(ABB *raiz);
void preOrdem(ABB *raiz);
int contaFilhoUnico(ABB *raiz); // exerc
void percorrerNivel(ABB *raiz); // exerc
int contaNo(ABB *raiz); // exerc
int contaNoInterno(ABB *raiz); // exerc
int contaNoExterno(ABB *raiz); // exerc
int contaNoNivel(ABB *raiz, int nivel); // exerc
int contaNoFolha(ABB *raiz); // exerc
int contaNoFolhaNivel(ABB *raiz, int nivel); // exerc
int contaNoNivel(ABB *raiz, int nivel); // exerc
int contaNoNivel(ABB *raiz, int nivel); // exerc
int contaNoNivel(ABB *raiz, int nivel); // exerc
int contaNoNivel(ABB *raiz, int nivel); // exerc

void preOrdem(ABB *raiz){
   if (raiz != NULL){
      printf("\n%d", raiz->valor);
      preOrdem(raiz->esq);
      preOrdem(raiz->dir);
   }
}

void ordemCentral(ABB *raiz){
   if (raiz != NULL){
      ordemCentral(raiz->esq);
      printf("\n%d", raiz->valor);
      ordemCentral(raiz->dir);
   }
}
void posOrdem(ABB *raiz){
   if (raiz != NULL){
      posOrdem(raiz->esq); // visita a árvore da esquerda
      posOrdem(raiz->dir);
      printf("\n%d", raiz->valor);      
   }
}

ABB *cria_no(int valor){
   ABB *novo;
   novo = (ABB*)malloc(sizeof(ABB));
   if( novo == NULL ){
        printf("\nFALHA DE MEMÓRIA");
        exit(1);
   }
   novo->valor = valor;
   novo->esq = NULL;
   novo->dir = NULL;
   return novo;
}

ABB *insere(ABB *raiz, int valor){
   
   // se a árvore estiver
   if (raiz == NULL){
      raiz = cria_no(valor);
   }else{
      if ( valor <= raiz->valor){  
         raiz->esq = insere(raiz->esq, valor);
      }else
         raiz->dir = insere(raiz->dir, valor);
   }
   return raiz;
}

int contaFolha(ABB *raiz){
   if (raiz == NULL)
      return 0;
   else
      if (raiz->esq == NULL && raiz->dir == NULL)
         return 1;
      else  
         return contaFolha(raiz->esq)+contaFolha(raiz->dir);

}
// retorna o menor valor em uma abb
ABB *menorValorNaABB(ABB *raiz) {
   ABB *atual = raiz;
   while (atual && atual->esq != NULL) {
      atual = atual->esq;
   }
   return atual;
}

ABB *maiorValorNaABB(ABB *raiz){
   ABB *atual = raiz;
   
   while(atual && atual->dir != NULL){
      atual = atual->dir;
   }
   return atual;
}

int maximo(int a, int b){
   return a>b?a:b;
}

int altura(ABB *raiz){
   if(!raiz){
      return 0;
   }else{
      return maximo(altura(raiz->esq), altura(raiz->dir)) + 1;
   }
}


ABB *excluir(ABB *raiz, int valor) {
   if (raiz == NULL) {
      return raiz;
   }
   if (valor < raiz->valor) {
      raiz->esq = excluir(raiz->esq, valor);
   } else
      if (valor > raiz->valor) {
         raiz->dir = excluir(raiz->dir, valor);
      }
      else { // valor == raiz->valor
         // não tem o filho da esquerda
         if (raiz->esq == NULL) {
               ABB *temp = raiz->dir;
               free(raiz);
               return temp;
         } else
            // não tem o filho da direita
            if (raiz->dir == NULL) {
               ABB *temp = raiz->esq;
               free(raiz);
               return temp;
         }
         // o nó excluído tem dois filhos
         ABB *temp = menorValorNaABB(raiz->dir);
         raiz->valor = temp->valor;
         raiz->dir = excluir(raiz->dir, temp->valor);
      }
   return raiz;
}

int contaFilhoUnico(ABB *raiz){
   int cont = 0;
   if ((raiz->esq != NULL) || (raiz->dir != NULL)){
      if ((raiz->esq == NULL) && (raiz->dir == NULL)){
         cont += 1;
         contaFilhoUnico(raiz->esq);
      }
      contaFilhoUnico(raiz->esq);
   }

   return cont;
}

// Retorna 1 se for balanceada ou 0 caso contrario
bool balanceada(ABB *raiz){
   if (raiz == NULL)
      return true;
   if (abs(contaFolha(raiz->esq) - contaFolha(raiz->dir)) <= 1){
      return true;
   }else
      return false;
}

int main(void){
   // ABB *raiz = NULL;
   // insere(raiz, 4);
   ABB *raiz = cria_no(8);
   insere(raiz, 2);
   insere(raiz, 3);
   // insere(raiz, 5);
   // insere(raiz, 6);
   // insere(raiz, 9);
   // insere(raiz, 13);

   // printf("Altura %d", altura(raiz));

   // printf("É balanceada? %d",balanceada(raiz));

   // printf("\npreOrdem\n");
   // preOrdem(raiz);

   // printf("\nposOrdem\n");
   // posOrdem(raiz);

   // printf("\nordemCentral\n");
   // ordemCentral(raiz);

   printf("\nFilhos unicos %d", contaFilhoUnico(raiz));

   return 0;
}