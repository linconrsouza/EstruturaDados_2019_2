//
// Created by a1242938 on 10/09/19.
//

#ifndef UNTITLED_FILA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoFila *PtrNoFila;

typedef struct NoFila{
    Objeto obj;
    PtrNoFila proximo;
} NoFila;

typedef struct {
    PtrNoFila inicio;
    PtrNoFila fim;
    int tamanho;
} FilaDinamica;

void iniciaFila(FilaDinamica *fila){
    fila->inicio = NULL;
    fila->fim=NULL;
    fila->tamanho=0;
}



int estaVazia(FilaDinamica *fila){
    return (fila->tamanho ==0);
}


void enfileira(Objeto x, FilaDinamica *fila){
    PtrNoFila aux;
    aux= (PtrNoFila) malloc(sizeof(NoFila));
    aux->obj=x;
    if(fila->tamanho==0){
        fila->inicio = fila->fim = aux;
        aux->proximo=NULL;
    } else{
        aux->proximo = NULL;
        fila->fim->proximo=aux;
        fila->fim = fila->fim->proximo;
    }
    fila->tamanho++;

}

void desenfileira(FilaDinamica *fila, Objeto *x){
    NoFila *aux;

    if(!estaVazia(fila)){
        aux=fila->inicio;
        *x = aux->obj;
        fila->inicio = fila->inicio->proximo;
        free(aux);
        fila->tamanho--;

    } else{
        printf("A fila está vazia");
    }


}

void imprimeFila(FilaDinamica *fila){
    NoFila *ponteiro;
    for(ponteiro = fila->inicio; ponteiro!=NULL; ponteiro= ponteiro->proximo){
        printf("%d\n",ponteiro->obj.chave);
    }
    printf("\n");

}
int tamanhoFila(FilaDinamica *fila){
    return (fila->tamanho);
}

Objeto inicioFila(FilaDinamica *fila){
    return (fila->inicio->obj);
}

Objeto fimFila(FilaDinamica *fila){
    return (fila->fim->obj);
}


#define UNTITLED_FILA_DINAMICA_H

#endif //UNTITLED_FILA_DINAMICA_H
