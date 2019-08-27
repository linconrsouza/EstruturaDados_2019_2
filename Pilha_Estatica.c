
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define N 100

typedef struct {
  int chave;

} Objeto;


typedef struct {
  Objeto array[N];
  int topo;
} pilhaEstatica;



void iniciaPilha(pilhaEstatica *pilha){
    pilha->topo = 0;
}


bool estaVazia(pilhaEstatica *pilha){
    if(pilha->topo == 0){
            return true;
        } else {
            return false;
        }

}

bool estaCheia(pilhaEstatica *pilha){
    if(pilha -> topo == N){
            return true;
        } else {
            return false;
        }
}


void empilha(Objeto item, pilhaEstatica *pilha){
    if(estaCheia(pilha)==0){
        pilha->array[pilha->topo] = item;
        pilha->topo = pilha->topo+1;
    } else{
        printf("Pilha Cheia, Elemento nao inserido!!!! \n");
    }
}


void desempilha(Objeto *item, pilhaEstatica *pilha){
    if(estaVazia(pilha)==0){
        *item = pilha->array[pilha->topo-1];
        pilha->topo = pilha->topo-1;
    } else{
        printf("Pilha Vazia!!!!! \n");
    }
}


int tamanhoPilha(pilhaEstatica *pilha){
    return pilha->topo;
}

Objeto topo(pilhaEstatica *pilha){
    return pilha->array[pilha->topo-1];
}

void imprimePilha(pilhaEstatica *pilha){
    for(int i=0; i<pilha->topo;i++){
        printf("%d \n", pilha->array[i].chave);
    }
    printf("\n");
}


int main()
{

    pilhaEstatica X;
    Objeto Y;

    Y.chave = 10;
    iniciaPilha(&X);
    estaCheia(&X);
    estaVazia(&X);
    empilha(Y, &X);
    imprimePilha(&X);

    Y.chave = 20;
    empilha(Y, &X);
    imprimePilha(&X);

    Y.chave = 40;
    empilha(Y, &X);
    imprimePilha(&X);

    Y.chave = 60;
    empilha(Y, &X);
    imprimePilha(&X);


    desempilha(&Y, &X);
    imprimePilha(&X);


    Y.chave = 70;
    empilha(Y, &X);
    imprimePilha(&X);
    

    return 0;
}
