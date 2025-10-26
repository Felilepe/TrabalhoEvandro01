#ifndef TEXTO_H
#define TEXTO_H

typedef void* Texto;

Texto texto_create(int id, double x, double y, char *corborda, char *corpreench, char a, char* txto);


int texto_getID(Texto t);

double texto_getCoordX(Texto t);

double texto_getCoordY(Texto t);

char *texto_getTexto(Texto t);

char *texto_getCorBorda(Texto t);

char *texto_getCorPreench(Texto t);

char *texto_getFamily(Texto t);

char *texto_getWeight(Texto t);

char *texto_getSize(Texto t);

char texto_getAnchor(Texto t);

double texto_getArea(Texto t);



void texto_setNewDefault(char* fFamily, char* fWeight, char* fSize);

void texto_setCoordX(Texto t, double x);

void texto_setCoordY(Texto t, double y); 

void texto_setCorPreench(Texto t, char* corpreench);

void texto_setCorBorda(Texto t, char* corborda);

void texto_setTexto(Texto t, char* txto);

void texto_setFamily(Texto t, char* fFamily);

void texto_setWeight(Texto t, char* fWeight);

void texto_setSize(Texto t, char* fSize);

void texto_setAnchor(Texto t, char a);

void texto_destroy(Texto t);

#endif