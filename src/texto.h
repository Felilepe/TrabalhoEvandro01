#ifndef TEXTO_H
#define TEXTO_H

typedef void* Texto;

Texto texto_create(int id, double x, double y, char *corb, char *corp, char *a, char* txto);


int texto_getID(Texto t);

double texto_getCoordX(Texto t);

double texto_getCoordy(Texto t);

char *texto_getTexto(Texto t);

char *texto_getAnchor(Texto t);

double texto_getArea(Texto t);

char *texto_getCorB(Texto t);

char *texto_getCorP(Texto t);

char *texto_getFamily(Texto t);

char *texto_getWeight(Texto t);

char *texto_getSize(Texto t);


void texto_setNewDefault(char* fFamily, char* fWeight, char* fSize);

void texto_setCoordX(Texto t, double x);

void texto_seCoordY(Texto t, double y); 

void texto_setcorP(Texto t, char* corp);

void texto_setcorB(Texto t, char* corb);

void texto_setTexto(Texto t, char* txto);

void texto_setFamily(Texto t, char* fFamily);

void texto_setWeight(Texto t, char* fWeight);

void texto_setSize(Texto t, char* fSize);

void texto_setAnchor(Texto t, char *a);


#endif