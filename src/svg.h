#ifndef SVG_H
#define SVG_H

#include <stdio.h>
#include "retangulo.h"
#include "circulo.h"
#include "fila.h"
#include "linha.h"
#include "texto.h"
#include "formas.h"

typedef void* item;

FILE *startSVG(const char *path);

void stopSVG(FILE *file_name);

void createSVG(char *file_name, fila *formas);

void draw(item i, item aux);

void insertForma(FILE *file_name, forma f);

void insertCirculo(FILE *file_name, Circulo c);

void insertRetangulo(FILE *file_name, Retangulo r);

void insertLinha(FILE *file_name, Linha l);

void insertTexto(FILE *file_name, Texto t);




#endif