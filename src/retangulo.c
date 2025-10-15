#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "retangulo.h"


typedef struct retangulo 
{
    int id;
    double x, y, r;
    char *corborda, *corpreench;

}retangulo;


Retangulo createRetangulo(int id, double x, double y, double r, char *corborda, char*corpreench)
{
    retangulo *circ= malloc(sizeof(retangulo));
    if(circ == NULL){
        printf("Erro na alocação de memória ao criar retangulo");
        exit(1);
    }
    
    circ -> id = id;
    circ -> x = x;
    circ -> y = y;
    circ -> r = r;
    
    circ -> corborda = (char*)malloc(strlen(corborda) + 1);
    if(circ -> corborda == NULL){
        printf("Erro na alocação da memorio ao trocar cor da borda");
        exit(1);
    }
    strcpy(circ -> corborda, corborda);

    circ -> corpreench = (char*)malloc(strlen(corpreench) + 1);
    if(circ -> corpreench == NULL){
        printf("Erro na alocacao de memoria ao trocar cor de preenchimento");
        exit(1);
    }
    strcpy(circ -> corpreench, corpreench);

    return circ;
}


double getCoordX(Retangulo c) {return ((retangulo*)c) -> x;}

double getCoordY(Retangulo c) {return ((retangulo*)c) -> y;}

int getID(Retangulo c) {return((retangulo*)c) -> id;}

double getRaio(Retangulo c) {return ((retangulo*)c) -> r;}

double calcArea(Retangulo c) 
{

}


