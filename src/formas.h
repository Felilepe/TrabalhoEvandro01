#ifndef FORMAS_H
#define FORMAS_H

typedef void* forma;

void forma_destroy(forma f);

double forma_calcArea(forma f);

void forma_trocarCores(forma f);

void forma_trocarCoresEntreFormas(forma f1, forma f2);



int forma_getID(forma f);

int forma_getType(forma f);

double forma_getCoordX(forma f);

double forma_getCoordY(forma f);

char* forma_getCorBorda(forma f);

char* forma_getCorPreench(forma f);

char *forma_getCorComp(forma f);



void forma_setCoordX(forma f, double x);

void forma_setCoordY(forma f, double y);

void forma_setCorBorda(forma f, char* corb);

void forma_setCorPreench(forma f, char* corp);


#endif