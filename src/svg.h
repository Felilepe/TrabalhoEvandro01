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



void svg_insertCirculo(FILE *file_name, Circulo c);

void svg_insertRetangulo(FILE *file_name, Retangulo r);

void svg_insertLinha(FILE *file_name, Linha l);

void svg_insertTexto(FILE *file_name, Texto t);

void svg_insertForma(FILE *file_name, forma f);



void draw(item i, item aux);



void createSVG(char *file_name, Fila *formas);



#endif