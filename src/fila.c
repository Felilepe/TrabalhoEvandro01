#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

typedef struct node
{
    item forma;
    struct node *next;
}node;

struct fila
{
    node *first;
    int size;
};

Fila *fila_create()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f == NULL){
        printf("Erro na alocacao de memoria ao criar fila");
        exit(1);
    }
    
    f ->first = NULL;
    f -> size = 0;

    return f;
}

bool fila_isEmpty(Fila *f)
{
    if(f -> size = 0){
        return true;
    }else{
        return false;
    }
}

