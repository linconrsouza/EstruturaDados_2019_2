#include <stdio.h>
#include "arvore_binaria.h"

int main() {

    Ponteiro raiz;


    bool aux;

    iniciaArvore(&raiz);

    Item x;

    x.chave = 37;

    Item y;

    y.chave = 25;

    Item z;

    z.chave = 24;

    Item w;

    w.chave = 30;

    Item recebe;

    insereItem(&raiz, x);
    insereItem(&raiz, y);
    insereItem(&raiz, z);
    insereItem(&raiz, w);

    aux = estaVazia(&raiz);

    if(aux){
        printf("Arvore vazia\n");

    }else{
        printf("Arvore não vazia\n");
    }
    printf("Pre ordem: \n");
    percursoEmOrdem(&raiz);
    printf("\n");
    printf("Pos ordem: \n");
    percursoPosOrdem(&raiz);



    printf("\n");
    printf("Procura elemento: \n");

    printf("Se for 1 = true\nSe for 0 = false\nResultado: %d \n", procuraItem(&raiz, x.chave));

    maiorElemento(&raiz);
    menorElement(&raiz);

    removeItem(&raiz, x.chave, &recebe);

    percursoEmOrdem(&raiz);

    aux = estaVazia(&raiz);

    if(aux){
        printf("Arvore vazia!\n");

    }else{
        printf("Arvore não vazia\n");
    }



    return 0;
}
