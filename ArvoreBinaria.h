
#ifndef ARVORES_BILBI_H
#define ARVORES_BILBI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} Item;

typedef struct NoArvore *Ponteiro;

typedef struct NoArvore {
    Item elemento;
    Ponteiro esquerda; //VALOR MENOR
    Ponteiro direita; //VALOR MAIOR
} NoArvore;


//---------------------------------------------------------


void iniciaArvore(Ponteiro *tree){

    *tree = NULL;
}


bool estaVazia(Ponteiro *tree){

    return (*tree == NULL);
}


bool insereItem(Ponteiro *tree, Item x){

    if(*tree== NULL){
        Ponteiro aux = malloc(sizeof(NoArvore));
        (aux)->elemento = x;
        (aux)->direita = (aux)->esquerda = NULL;
        (*tree) = (aux);

        return true;
    }

    if((*tree)->elemento.chave == x.chave){

        return false;
    }

    if((*tree)->elemento.chave > x.chave){

        return (insereItem(&(*tree)->esquerda, x));
    }

    if((*tree)->elemento.chave < x.chave){

        return (insereItem(&(*tree)->direita, x));
    }
}

void percursoEmOrdem(Ponteiro *tree){


    if((*tree) == NULL){
        return;
    }

    percursoEmOrdem(&(*tree)->esquerda);

    printf("%d \n", (*tree)->elemento.chave);

    percursoEmOrdem(&(*tree)->direita);
}


void percursoPreOrdem(Ponteiro *tree){


    if((*tree) == NULL){
        return;
    }

    printf("%d \n", (*tree)->elemento.chave);
    percursoPreOrdem(&(*tree)->esquerda);
    percursoPreOrdem(&(*tree)->direita);

}


void percursoPosOrdem(Ponteiro *tree){


    if((*tree) == NULL){
        return;
    }

    percursoPosOrdem(&(*tree)->esquerda);
    percursoPosOrdem(&(*tree)->direita);
    printf("%d \n", (*tree)->elemento.chave);

}


void destroiArvore(Ponteiro *tree){

    Ponteiro aux;

    if((*tree) == NULL){
        return;
    }

    destroiArvore(&(*tree)->esquerda);
    destroiArvore(&(*tree)->direita);
    aux = (*tree);
    (*tree) = NULL;
    free(aux);
}

bool procuraItem(Ponteiro *tree, int key){

    if((*tree) == NULL){
        return false;
    }

    if(key == (*tree)->elemento.chave){
        return true;
    }

    if(key < (*tree)->elemento.chave){
        procuraItem(&(*tree)->esquerda, key);
    }


    if(key > (*tree)->elemento.chave){
        procuraItem(&(*tree)->direita, key);
    }

}

Ponteiro maiorElemento(Ponteiro *tree){


    Ponteiro aux;

    aux = (*tree);


    while(aux->direita != NULL){
        aux = aux->direita;

    }

    printf("\nMaior Elemento: %d \n", aux->elemento.chave);
    return aux;

}

Ponteiro menorElement(Ponteiro *tree){

    Ponteiro aux;

    aux = (*tree);


    while(aux->esquerda != NULL){
        aux = aux->esquerda;

    }

    printf("\nMenor Elemento: %d \n", aux->elemento.chave);
    return aux;

}


bool removeItem(Ponteiro *tree, int key, Item *ret){



    if((*tree) == NULL){
        return false;
    }

    if(key == (*tree)->elemento.chave) {

        Ponteiro aux;

        if ((*tree)->direita == NULL && (*tree)->esquerda != NULL) {

            (*ret) = (*tree)->elemento;
            aux = (*tree);
            (*tree) = (*tree)->esquerda;
            free(aux);
            return true;
        }


        if ((*tree)->esquerda == NULL && (*tree)->direita != NULL) {

            (*ret) = (*tree)->elemento;
            aux = (*tree);
            (*tree) = (*tree)->direita;
            free(aux);
            return true;
        }


        if ((*tree)->direita == NULL && (*tree)->esquerda == NULL) {

            aux = (*tree);
            (*tree) = NULL;
            free(aux);

            return true;
        }

        if ((*tree)->direita != NULL && (*tree)->esquerda != NULL) {
            Ponteiro aux;
            Ponteiro aux2;


            aux = menorElement(&(*tree)->direita);
            aux2 = (*tree);
            (*tree) = aux;
            free(aux2);

        }

        if (key < (*tree)->elemento.chave) {
            removeItem(&(*tree)->esquerda, key, ret);
        }


        if (key > (*tree)->elemento.chave) {
            removeItem(&(*tree)->direita, key, ret);
        }

    }

}


int sizeTree(Ponteiro *tree){
    if((*tree) == NULL){
        return 0;
    }else{
        return (sizeTree(&(*tree)->esquerda) + 1 + (sizeTree(&(*tree)->direita)));
    }
}


#endif //ARVORES_BILBI_H
