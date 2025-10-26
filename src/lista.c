#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

typedef struct node
{
    item elemento;
    struct node *last, *next;
}node;

struct lista
{
    node *start, *end;
    int size;
};

Lista *lista_create()
{
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if(l == NULL){
        printf("Erro na alocacao de memoria ao criar lista");
        exit(1);
    }
    l -> start = l -> end = NULL;
    l -> size = 0;

    return l;
}

bool lista_isEmpty(Lista *l){return l -> size == 0;}



void lista_insert(Lista *l, item i)
{
    node *novoNode = (node*)malloc(sizeof(node));
    if(novoNode == NULL){
        printf("Erro na alocacao de memoria ao adicionar item a lista.");
        exit(1);
    }

    novoNode -> elemento = i;
    novoNode -> next = NULL;

    if(l ->start == NULL){
        novoNode -> last = NULL;
        l -> start = novoNode;
        l -> end = novoNode;
    } else{
        novoNode -> last = l -> end;
        l -> end -> next = novoNode;
        l -> end = novoNode;
    }

    l -> size++;
}

item lista_remove(Lista *l)
{
    if(lista_isEmpty(l)){
        printf("Erro: Lista esta vazia.");
        exit(1);
    }

}