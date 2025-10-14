#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "circulo.h"

typedef struct circulo 
{
    int id;
    double x, y, r;
    char *corborda, *corpreench;

}circulo;


Circulo createCirculo(int id, double x, double y, double r, char *corborda, char*corpreench)
{
    circulo *circ= malloc(sizeof(circulo));
    if(circ == NULL){
        printf("Erro na alocação de memória");
        exit(1);
    }
    
    circ -> x = x;
    circ -> y = y;
    circ -> r = r;
    
    circ -> corborda = malloc(strlen(sizeof(corborda) + 1));
    if(circ -> corborda == NULL){
        printf("Erro na alocação da memório ao trocar cor da borda");
        exit(1);
    }
    strcpy(circ -> corborda, corborda);

    circ -> corpreench = malloc(strlen(sizeof(corpreench) + 1));
    if(circ -> corpreench == NULL){
        printf("Erro na alocação de memória ao trocar cor de preenchimento");
        exit(1);
    }
    strcpy(circ -> corpreench, corpreench);

    return circ;
}

Circulo moverCirculo(circulo *c, double x, double y)
{
    c -> x = x;
    c -> y = y;
}

