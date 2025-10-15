#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "retangulo.h"


typedef struct retangulo 
{
    int id;
    double x, y, w, h;
    char *corborda, *corpreench;

}retangulo;


Retangulo createRetangulo(int id, double x, double y, double w, double h, char *corborda, char*corpreench)
{
    retangulo *ret= malloc(sizeof(retangulo));
    if(ret == NULL){
        printf("Erro na alocação de memória ao criar retangulo");
        exit(1);
    }
    
    ret -> id = id;
    ret -> x = x;
    ret -> y = y;
    ret -> w = w;
    ret -> h = h;
    
    ret -> corborda = (char*)malloc(strlen(corborda) + 1);
    if(ret -> corborda == NULL){
        printf("Erro na alocação da memorio ao trocar cor da borda");
        exit(1);
    }
    strcpy(ret -> corborda, corborda);

    ret -> corpreench = (char*)malloc(strlen(corpreench) + 1);
    if(ret -> corpreench == NULL){
        printf("Erro na alocacao de memoria ao trocar cor de preenchimento");
        exit(1);
    }
    strcpy(ret -> corpreench, corpreench);

    return ret;
}


double calcArea(Retangulo r)
{
    double altura = ((retangulo*)r) -> h;
    double largura = ((retangulo*)r) -> w;
    
    return altura * largura;
}


double getCoordX(Retangulo r) {return ((retangulo*)r) -> x;}

double getCoordY(Retangulo r) {return ((retangulo*)r) -> y;}

int getID(Retangulo r) {return((retangulo*)r) -> id;}

double getHeight(Retangulo r) {return ((retangulo*)r) -> h;}

double getWidth(Retangulo r) {return ((retangulo*)r) -> w;}



