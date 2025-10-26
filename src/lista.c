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
    node *inicio, *fim;
    int size;
};