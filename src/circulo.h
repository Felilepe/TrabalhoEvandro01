#ifndef CIRCULO_H;
#define CIRCULO_H;

typedef void* Circulo;

Circulo createCirculo(int id, double x, double  y, double r, char *corborda, char *corpreench);

Circulo moverCirculo(int id, int x, int y);

#endif
