#ifndef FORMAS_H
#define FORMAS_H

typedef void* forma;

void forma_destroy(forma f);
double forma_calcArea(forma f);
int forma_getID(forma f);



double forma_getCoordX(forma f);
double forma_getCoordY(forma f);
char* forma_getCorBorda(forma f);
char* forma_getCorPreench(forma f);

void forma_setCoordX(forma f, double x);
void forma_setCoordY(forma f, double y);
void forma_setCorBorda(forma f, char* corb);
void forma_setCorPreench(forma f, char* corp);


#endif