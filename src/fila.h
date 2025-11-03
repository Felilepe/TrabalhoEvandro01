#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef void *item;
typedef struct fila Fila;
typedef struct node NodeF;



Fila *fila_create();

bool fila_isEmpty(Fila *f);

void fila_queue(Fila *f, item i);

item fila_dequeue(Fila *f);

NodeF *fila_getHead(Fila *f);

NodeF *fila_getTail(Fila *f);

item fila_getItem(Fila *f);

NodeF *fila_getNext(Fila *f);

void fila_destroy(Fila* f);

int fila_getSize(Fila *f);



void fila_passthrough(Fila *f, void (*acao)(item i, item aux_data), item aux_data)

#endif