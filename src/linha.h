#ifndef LINHA_H
#define LINHA_H

typedef void* Linha;

Linha linha_create(int id, double x1, double y1, double x2, double y2, char* cor, bool isDotted);



int linha_getID(Linha l);

double linha_getCoordX1(Linha l);

double linha_getCoordX2(Linha l);

double linha_getCoordY1(Linha l);

double linha_getCoordY2(Linha l);

char* linha_getCor(Linha l);

bool linha_getIsDotted(Linha l);



double linha_calcArea(Linha l);



void linha_setCoordX1(Linha l, double x1);

void linha_setCoordX2(Linha l, double x2);

void linha_setCoordY1(Linha l, double y1);

void linha_setCoordY2(Linha l, double y2);

void linha_setCor(Linha l, char *cor);



void linha_destroy(Linha l);

#endif