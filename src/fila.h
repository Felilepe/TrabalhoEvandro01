#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef void *item;
typedef struct fila Fila;



Fila *fila_create();

void fila_queue(Fila *f, item i);

item fila_dequeue(Fila *f);

item fila_peek(Fila *f);

bool fila_isEmpty(Fila *f);

void fila_destroy(Fila* f);


#endif