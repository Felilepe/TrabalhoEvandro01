#ifndef TEXTO_H
#define TEXTO_H

typedef void* Texto;

Texto texto_create(int id, double x, double y, char *corb, char *corp, char a, char* txto);

int texto_getID(Texto t);

double texto_getCoordX(Texto t);

double texto_getCoordy(Texto t);

char *texto_getTexto(Texto t);

#endif