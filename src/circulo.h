#ifndef CIRCULO_H;
#define CIRCULO_H;

typedef void* Circulo;

Circulo createCirculo(int id, double x, double  y, double r, char *corborda, char *corpreench);

Circulo getCoordX(Circulo c);

Circulo getCoordY(Circulo c);

Circulo calcArea(Circulo c);

Circulo getRaio(Circulo c);

Circulo getID(Circulo c);

#endif
