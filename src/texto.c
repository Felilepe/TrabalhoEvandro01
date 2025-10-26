#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct texto
{
    int id;
    double x, y;
    char *corborda, *corpreench, *txto, *fFamily, *fWeight, *fSize; 
    char a;
}texto;



static char *default_fFamily = NULL;
static char *default_fWeight = NULL;
static char *default_fSize = NULL;  

static void inicializarDefault()
{
    free(default_fFamily);
    default_fFamily = (char*)malloc(strlen("Arial") + 1);
    strcpy(default_fFamily, "Arial");

    free(default_fWeight);
    default_fWeight = (char*)malloc(strlen("n") + 1);
    strcpy(default_fWeight,"n");

    free(default_fSize);
    default_fSize = (char*)malloc(strlen("12") + 1);
    strcpy(default_fSize, "12");
}


static double calcComp (char *txto) //Calcula o comprimento da linha
{
    return 10 * strlen(txto);
}
    


Texto texto_create(int id, double x, double y, char *corborda, char *corpreench, char a, char* txto)
{
    if(default_fFamily == NULL){
        inicializarDefault();
    }
    

    texto *t = malloc(sizeof(texto));
    if(t == NULL){
        printf("Erro de alocacao de memoria ao criar texto");
        exit(1);
    }

 
    t -> id = id;
    t -> x = x;
    t -> y = y;
    t -> a = a;

    
    t -> fFamily = (char*)malloc(strlen(default_fFamily) + 1);
    if(t -> fFamily == NULL){
    printf("Erro de alocacao de memoria ao atribuir fonte inicial do texto.");
    exit(1);
    }
    strcpy(t -> fFamily, default_fFamily);
    
    t->fWeight = (char*)malloc(strlen(default_fWeight) + 1);
    if(t -> fWeight == NULL){
    printf("Erro de alocacao de memoria ao atribuir peso inicial do texto.");
    exit(1);
    }
    strcpy(t->fWeight, default_fWeight);

    t -> fSize = (char*)malloc(strlen(default_fSize) + 1);
    if(t -> fSize == NULL){
    printf("Erro de alocacao de memoria ao atribuir tamanho inicial do texto.");
    exit(1);
    }
    strcpy(t -> fSize, default_fSize);
    
    t -> corborda = (char*)malloc((strlen(corborda) + 1));
    if(t -> corborda == NULL){
        printf("Erro na alocacao de memoria ao atribuir cor de borda");
        exit(1);
    }
    strcpy(t -> corborda, corborda);

    t -> corpreench = (char*)malloc((strlen(corpreench) + 1));
    if(t -> corpreench == NULL){
        printf("Erro na alocacao de memoria ao atribuir cor de preenchimento");
        exit(1);
    }
    strcpy(t -> corpreench, corpreench);

    t -> txto = (char*)malloc((strlen(txto) + 1));
    if(t -> txto == NULL){
        printf("Erro na alocacao de memoria ao atribuir texto");
        exit(1);
    }
    strcpy(t -> txto, txto);


    return t;
}



int texto_getID(Texto t) {return ((texto*)t) -> id;}

double texto_getCoordX(Texto t) {return ((texto*)t) -> x;}

double texto_getCoordY(Texto t) {return ((texto*)t) -> y;}

char *texto_getTexto(Texto t) {return ((texto*)t) -> txto;}

char *texto_getCorBorda(Texto t) {return ((texto*)t) -> corborda;}

char *texto_getCorPreench(Texto t) {return ((texto*)t) -> corpreench;}

char *texto_getFamily(Texto t) {return ((texto*)t) -> fFamily;}

char *texto_getWeight(Texto t) {return ((texto*)t) -> fWeight;}

char *texto_getSize(Texto t) {return ((texto*)t) -> fSize;}

char texto_getAnchor(Texto t) {return ((texto*)t)  -> a;}

double texto_getArea(Texto t) {return 2 * calcComp(((texto*)t) -> txto);}



void texto_setNewDefault(char *fFamily, char *fWeight, char* fSize)
{
    if(default_fFamily == NULL){
        inicializarDefault();
    }


    free(default_fFamily);
    default_fFamily = (char*)malloc(strlen(fFamily) + 1);
    strcpy(default_fFamily, fFamily);

    free(default_fWeight);
    default_fWeight = (char*)malloc(strlen(fWeight) + 1);
    strcpy(default_fWeight, fWeight);

    free(default_fSize);
    default_fSize = (char*)malloc(strlen(fSize) + 1);
    strcpy(default_fSize, fSize);
}

void texto_setCoordX(Texto t, double x) {((texto*)t) -> x = x;}

void texto_setCoordY(Texto t, double y) {((texto*)t) -> y = y;}

void texto_setCorPreench(Texto t, char* corpreench)
{
    free(((texto*)t) -> corpreench);
    ((texto*)t) -> corpreench = (char*)malloc(strlen(corpreench) + 1);
    strcpy(((texto*)t) -> corpreench, corpreench);
}

void texto_setCorBorda(Texto t, char* corborda)
{
    free(((texto*)t) -> corborda);
    ((texto*)t) -> corborda = (char*)malloc(strlen(corborda) + 1);
    strcpy(((texto*)t) -> corborda, corborda);
}

void texto_setTexto(Texto t, char* txto)
{
    free(((texto*)t) -> txto);
    ((texto*)t) -> txto = (char*)malloc(strlen(txto) + 1);
    strcpy(((texto*)t) -> txto, txto);
}

void texto_setFamily(Texto t, char* fFamily)
{
    free(((texto*)t) -> fFamily);
    ((texto*)t) -> fFamily = (char*)malloc(strlen(fFamily) + 1);
    strcpy(((texto*)t) -> fFamily, fFamily);
}

void texto_setWeight(Texto t, char* fWeight)
{
    free(((texto*)t) -> fWeight);
    ((texto*)t) -> fWeight = (char*)malloc(strlen(fWeight) + 1);
    strcpy(((texto*)t) -> fWeight, fWeight);
}

void texto_setSize(Texto t, char* fSize)
{
    free(((texto*)t) -> fSize);
    ((texto*)t) -> fSize = (char*)malloc(strlen(fSize) + 1);
    strcpy(((texto*)t) -> fSize, fSize);
}

void texto_setAnchor(Texto t, char a) {((texto*)t) -> a = a;}


void texto_destroy(Texto*t){
    texto* ttemp = (texto*)t;

    free(ttemp -> corborda);
    free(ttemp ->corpreench);
    free(ttemp ->fFamily);
    free(ttemp -> fSize);
    free(ttemp -> fWeight);
    free(ttemp -> txto);
    free(ttemp); 

}