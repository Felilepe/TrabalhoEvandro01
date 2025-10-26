#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef void* item;
typedef struct lista Lista;

Lista *lista_create();

item lista_remove(Lista *l, item i);

void lista_add(Lista *l, item i);

bool lista_isEmpty(Lista *l);

void lista_destroy(Lista *l);

item lista_listapeek(Lista *l);

void lista_showLista(Lista *l);


#endif