#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

typedef struct node
{
    item item;
    struct node *next;

} node;

 struct pilha
{
    node *topo;
    int size;
};

Pilha* createPilha()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p == NULL) return NULL;
    p -> topo = NULL;
    p -> size = 0;
    return p;
}

bool isEmpty(Pilha *p)
{
    if(p -> size == 0) return true;
    else return false;
}

void pushPilha(Pilha *p, item item)
{
    node *novaNode = (node*)malloc(sizeof(node));
    novaNode -> item = item;
    novaNode -> next = p -> topo;
    p -> topo = novaNode;
    p -> size++;
}

void *popPilha(Pilha *p)
{
    if(isEmpty(p)) return NULL;
    node *temp = p -> topo;
    void *item = temp -> item;
    p -> topo = temp -> next;
    free(temp);
    p -> size--;
    return item;
}

void *peekPilha(Pilha *p)
{
    if(isEmpty(p)) return NULL;
    return p -> topo -> item;
}

void destroyPilha(Pilha *p)
{
    while(!isEmpty(p)){
        popPilha(p);    
    }
    free(p);
}