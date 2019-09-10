#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila_dinamica.h"


int main() {
    Objeto Y;
    FilaDinamica X;


    iniciaFila(&X);
    Y.chave=10;
    enfileira(Y,&X);
    imprimeFila(&X);

    Y.chave=22;
    enfileira(Y,&X);
    imprimeFila(&X);


    Y.chave=56;
    enfileira(Y,&X);
    imprimeFila(&X);


    Y.chave=4;
    enfileira(Y,&X);
    imprimeFila(&X);


    desenfileira(&X, &Y);
    imprimeFila(&X);
    tamanhoFila(&X);
    inicioFila(&X);
    fimFila(&X);

    return 0;
}
