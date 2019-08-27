

#ifndef UNTITLED1_PILHADINAMICA_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoPilha *Ponteiro;

typedef struct NoPilha{
    Objeto obj;
    Ponteiro proximo;
} NoPilha;

typedef struct {
    Ponteiro topo;
    int tamanho;
} PilhaDinamica;


void iniciaPilha(PilhaDinamica *p){
    p->topo=NULL;
    p->topo=0;
}


bool estaVazia(PilhaDinamica *p){
    if(p->topo == 0){
        return true;
    } else {
        return false;
    }
}




void empilha(Objeto obj, PilhaDinamica *p){
    Ponteiro aux;
    aux = (Ponteiro) malloc (sizeof(NoPilha));
    aux->obj = obj;
    aux->proximo = p->topo;
    p->topo = aux;
    p->tamanho++;
    printf("Empilhou: %d \n", aux->obj.chave);

}

void desempilha(PilhaDinamica *p, Objeto *obj){
    if(estaVazia(p)){
        printf("Pilha Vazia \n");
    } else {
        *obj = p->topo->obj;
        Ponteiro aux;
        aux = p->topo;
        printf("Desempilhou: %d \n", aux->obj.chave);
        p->topo = p->topo->proximo;
        free(aux);
        p->tamanho--;
    }
}



int tamanhoPilha(PilhaDinamica *p){
    return (p->tamanho--)    ;

}

Objeto topo(PilhaDinamica *p, Objeto *obj){

    *obj = p->topo->obj;
    return *obj;
}

void imprimePilha(PilhaDinamica *p){
    Ponteiro aux;
    printf("Estado Atual da Pilha \n");
    for(aux = p->topo; aux != NULL; aux = aux->proximo){
        printf("%d \t", aux->obj.chave);
    }
    printf("\n");
}


#define UNTITLED1_PILHADINAMICA_H

#endif //UNTITLED1_PILHADINAMICA_H
