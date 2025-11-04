#ifndef CARREGADOR_H
#define CARREGADOR_H

#include "fila.h"
#include "formas.h"
#include <stdbool.h>
#include "lerGeo.h"

typedef void* Carregador;

Carregador carregador_create(int id);

int carregador_getID(Carregador *c);

forma carregador_loadForma(Carregador *c, forma f);

forma carregador_loadFromChao(Carregador *c, Chao *h);

Chao *carregador_loadAmount(Chao *h, Carregador *c, int n);

bool carregador_isEmpty(Carregador *c);

void carregador_destroy(Carregador **c_point);

forma carregador_remove(Carregador *c);

#endif