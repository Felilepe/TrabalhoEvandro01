#ifndef LINHA_H
#define LINHA_H

typedef void* Linha;

Linha linha_create(int id, double x1, double y1, double x2, double y2, char* cor);

Linha linha_getCoordX1(Linha l);

Linha linha_getCoordX2(Linha l);

Linha linha_getCoordY1(Linha l);

Linha linha_getCoordY2(Linha l);

Linha linha_getID(Linha l);

#endif