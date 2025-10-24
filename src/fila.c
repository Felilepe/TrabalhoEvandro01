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
    node *last;
    int size;
};

Fila *fila_create()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f == NULL){
        printf("Erro na alocacao de memoria ao criar fila");
        exit(1);
    }
    
    f -> first = NULL;
    f -> last = NULL;
    f -> size = 0;

    return f;
}



bool fila_isEmpty(Fila *f){return f -> size == 0;}



void fila_queue(Fila *f, item i)
{
    node *novoNode = (node*)malloc(sizeof(node));
    if(novoNode == NULL){
        printf("Erro na alocacao de memoria ao criar novo elemento para fila.");
        exit(1);
    }
    
    
    novoNode -> forma = i;
    novoNode -> next = NULL;
    
    
    if(f -> first == NULL){
        f -> first = novoNode;
        f -> last = novoNode;
    } else{
        f -> last -> next = novoNode;
        f -> last = novoNode;
    }

    f ->size++;
}

item fila_dequeue(Fila *f)
{
    if(fila_isEmpty(f)){
        printf("Erro: Fila esta vazia");
        exit(1);
    }

    node *auxNode = f -> first;

    item formaReturn = auxNode -> forma;
    
    f -> first = auxNode -> next;

    if(f -> first == NULL){
        f -> last = NULL;
    }
    
    free(auxNode);


    f -> size--;

    return formaReturn;
}


item fila_peek(Fila *f)
{
    if(fila_isEmpty(f)){
        printf("Erro: Fila esta vazia.");
        exit(1);
    }

    return f -> first -> forma;
}


void fila_destroy(Fila* f)
{
    while(!fila_isEmpty(f)){
        fila_dequeue(f);
    }
    free(f);
}