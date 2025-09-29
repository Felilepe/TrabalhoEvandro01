#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

typedef struct node
{
    void *item;
    node *next;

} node;

typedef struct stack
{
    node *topo;
    int size;
} stack;

stack* createPilha()
{
    stack *Stack = (stack*)malloc(sizeof(stack));
    Stack -> topo = NULL;
    Stack -> size = 0;
    return Stack;
}

bool isEmpty(stack *Stack)
{
    if(Stack -> size == 0) return true;
    else return false;
}

void pushPilha(stack *Stack, void *item)
{
    node *novaNode = (node*)malloc(sizeof(node));
    novaNode -> item = item;
    novaNode -> next = Stack -> topo;
    Stack -> topo = novaNode;
    Stack -> size++;
}

void *popPilha(stack *Stack)
{
    if(isEmpty(Stack)) return NULL;
    node *temp = Stack -> topo;
    void *item = temp -> item;
    Stack -> topo = temp -> next;
    free(temp);
    Stack -> size--;
    return item;
}

void *peekPilha(stack *Stack)
{
    if(isEmpty(Stack)) return NULL;
    return Stack -> topo -> item;
}

void destroyPilha(stack *Stack)
{
    while(!isEmpty(Stack)){
        popPilha(Stack);    
    }
    free(Stack);
}