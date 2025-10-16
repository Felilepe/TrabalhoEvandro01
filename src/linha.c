#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "linha.h"

typedef struct linha
{
    int id;
    double x1, x2, y1, y2;
    char* cor;
}linha;

Linha linha_create(int id, double x1, double x2, double y1, double y2, char* cor)
{
    linha *l = malloc(sizeof(linha));
    if(l = NULL){
        printf("Erro na alocacao de memoria ao criar linha");
        exit(1);
    }
    
    l ->id = id;
    l -> x1 = x1;
    l -> x2 = x2;
    l -> y1 = y1;
    l -> y2 = y2;
    l -> cor = (char*)malloc(strlen(cor) + 1);

}

