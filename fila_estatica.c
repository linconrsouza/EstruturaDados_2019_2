#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila_estatica.h"

int main() {

    FilaEstatica X;
    Item Y;

    Y.chave = 5;
    iniciaFila(&X);
    estaVazia(&X);
    estaCheia(&X);
    enfileira(Y, &X);
    imprimeFila(&X);


    Y.chave = 100000;
    enfileira(Y, &X);
    imprimeFila(&X);

    Y.chave = 20;
    enfileira(Y, &X);
    imprimeFila(&X);

    Y.chave = 30;
    enfileira(Y, &X);
    imprimeFila(&X);




    return 0;
}
