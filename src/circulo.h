#ifndef CIRCULO_H
#define CIRCULO_H

typedef void* Circulo;

Circulo createCirculo(int id, double x, double  y, double r, char *corborda, char *corpreench);

double getCoordX(Circulo c);

double getCoordY(Circulo c);

double calcArea(Circulo c);

double getRaio(Circulo c);

int getID(Circulo c);

#endif
