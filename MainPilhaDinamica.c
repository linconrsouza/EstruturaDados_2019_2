
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PilhaDinamica.h"


int main()
{

    PilhaDinamica p;
    Objeto x;


    x.chave = 10;
    iniciaPilha(&p);
    estaVazia(&p);
    empilha(x, &p);
    imprimePilha(&p);


    x.chave = 5;
    empilha(x, &p);
    imprimePilha(&p);

    x.chave = 20;
    empilha(x, &p);
    imprimePilha(&p);

    x.chave = 30;
    empilha(x, &p);
    imprimePilha(&p);


    x.chave = 5;
    empilha(x, &p);
    imprimePilha(&p);


    desempilha(&p, &x);
    imprimePilha(&p);

    desempilha(&p, &x);
    imprimePilha(&p);

    return 0;
}
