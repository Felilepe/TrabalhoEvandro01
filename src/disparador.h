#ifndef DISPARADOR_H
#define DISPARADOR_H

#include "carregador.h"
#include "formas.h"

typedef struct disparador Disparador;

typedef void* item;



Disparador *disparador_create(int id, double x, double y, Carregador *cesq, Carregador *cdir); 



int disparador_getID(Disparador *d);

double disparador_getCoordX(Disparador *d);

double disparador_getCoordY(Disparador *d);

Carregador disparador_getCDir(Disparador *d);

Carregador disparador_getCEsq(Disparador *d);

forma disparador_getFormaDisparo(Disparador *d);



void disparador_attachCarregador(Disparador *d, Carregador *cesq, Carregador *cdir);

item disparador_shift(Disparador *d, char b, int n);

void disparador_destroy(Disparador *d);



#endif