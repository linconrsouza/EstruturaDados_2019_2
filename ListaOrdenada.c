#include <stdio.h>
#include "listaordenada.h"


int main() {

    Item Y;
    List X;
    initList(&X);


    Y.key=10;
    insert(Y,&X);
    imprimirLista(&X);

    Y.key=30;
    insert(Y,&X);
    imprimirLista(&X);

    Y.key=5;
    insert(Y,&X);
    imprimirLista(&X);

    Y.key=1;
    insert(Y,&X);
    imprimirLista(&X);

    Y.key=70;
    insert(Y,&X);
    imprimirLista(&X);
    return 0;
}
