#ifndef DISPARADOR_H
#define DISPARADOR_H

#include "pilha.h"

typedef struct disparador Disparador;

typedef Pilha Carregador;

typedef void* item;

Disparador *disparador_create();

void disparador_attachCarregador(Disparador *d, Carregador *cesq, Carregador *cdir);

item disparador_shift(Disparador *d, char b, int n);

void disparador_destroy(Disparador *d);



#endif