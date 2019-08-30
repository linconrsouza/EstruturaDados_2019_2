#ifndef UNTITLED_FILA_ESTATICA_H
#define UNTITLED_FILA_ESTATICA_H

#define MAXTAM 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Item;


typedef struct {
    Item array[MAXTAM];
    int inicio;
    int fim;
    int tamanho;
} FilaEstatica;

void iniciaFila(FilaEstatica *fila){
    fila->inicio=0;
    fila->fim=-1;
}

int incrementaIndice(int i){
    if(i == MAXTAM){
        i=0;
    }else{
        i++;
    }
    return i;
}

bool estaVazia(FilaEstatica *fila){
    if(fila->tamanho ==0){
        return true;
    } else {
        return false;
    }
}

bool estaCheia(FilaEstatica *fila){
    if(fila->tamanho == MAXTAM){
        return true;
    } else {
        return false;
    }
}


void enfileira(Item x, FilaEstatica *fila){
    if(estaCheia(fila)==0){
        fila->fim = incrementaIndice(fila->fim);
        fila->array[fila->fim]=x;
        fila->tamanho++;
    }else{
        printf("Fila Cheia \n");
    }
}

void desenfileira(FilaEstatica *fila, Item *x){
    if(estaVazia(fila)==0){
        *x=fila->array[fila->inicio];
        fila->inicio = incrementaIndice(fila->inicio);
        fila->tamanho--;
    } else{
        printf("Fila Vazia \n");
    }
}

void imprimeFila(FilaEstatica *fila){
    int iterador = fila->inicio;
    if(fila->tamanho ==0){
        printf("Fila Vazia \n");
    } else {
        printf("Fila { ");
        while (iterador != fila->fim){
            printf(" %d ",fila->array[iterador].chave);
            if(iterador == (MAXTAM-1)){
                iterador=0;
            } else {
                iterador++;
            }
        }
        printf(" %d }\n",fila->array[fila->fim].chave);
    }

}


int tamanhoFila(FilaEstatica *fila){
    return fila->tamanho;
}

Item inicioFila(FilaEstatica *fila){
    Item inicio;
    inicio = fila->array[fila->inicio];
    return inicio;
}

Item fimFila(FilaEstatica *fila){
    Item fim;
    fim = fila->array[fila->fim];
    return fim;
}



#endif //UNTITLED_FILA_ESTATICA_H
