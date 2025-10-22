#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct texto
{
    int id;
    double x, y;
    char *corb, *corp, *txto, *fFamily, *fWeight, *fSize, *a;
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
    


Texto texto_create(int id, double x, double y, char *corb, char *corp, char *a, char* txto)
{
    if(default_fFamily == NULL){
        inicializarDefault;
    }
    

    texto *t = malloc(sizeof(texto));
    if(t == NULL){
        printf("Erro de alocacao de memoria ao criar texto");
        exit(1);
    }

 
    t  -> id = id;
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
    if(t -> fFamily == NULL){
    printf("Erro de alocacao de memoria ao atribuir peso inicial do texto.");
    exit(1);
    }
    strcpy(t->fWeight, default_fWeight);

    t -> fSize = (char*)malloc(strlen(default_fSize) + 1);
    if(t -> fFamily == NULL){
    printf("Erro de alocacao de memoria ao atribuir tamanho inicial do texto.");
    exit(1);
    }
    strcpy(t -> fSize, default_fSize);
    
    t -> corb = (char*)malloc((strlen(corb) + 1));
    if(t -> corb == NULL){
        printf("Erro na alocacao de memoria ao atribuir cor de borda");
        exit(1);
    }
    strcpy(t -> corb, corb);

    t -> corp = (char*)malloc((strlen(corp) + 1));
    if(t -> corp == NULL){
        printf("Erro na alocacao de memoria ao atribuir cor de preenchimento");
        exit(1);
    }
    strcpy(t -> corp, corp);

    t -> txto = (char*)malloc((strlen(txto) + 1));
    if(t -> txto == NULL){
        printf("Erro na alocacao de memoria ao atribuir texto");
        exit(1);
    }
    strcpy(t -> txto, txto);


    return t;
}



int texto_getID(Texto t){return ((texto*)t) -> id;}

double texto_getCoordX(Texto t){return ((texto*)t) -> x;}

double texto_getCoordY(Texto t){return ((texto*)t) -> y;}

char *texto_getTexto(Texto t){return ((texto*)t) -> txto;}

char *texto_getCorB(Texto t){return ((texto*)t) -> corb;}

char *texto_getCorP(Texto t){return ((texto*)t) -> corp;}

char *texto_getFamily(Texto t){return ((texto*)t) -> fFamily;}

char *texto_getWeight(Texto t){return ((texto*)t) -> fWeight;}

char *texto_getSize(Texto t){return ((texto*)t) -> fSize;}

char *texto_getAnchor(Texto t){return ((texto*)t)  -> a;}

double texto_getArea(Texto t){return 2 * calcComp(((texto*)t) -> txto);}



void texto_setNewDefault(char *fFamily, char *fWeight, char* fSize)
{
    if(default_fFamily == NULL){
        inicializarDefault;
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

void texto_seCoordY(Texto t, double y) {((texto*)t) -> y = y;}

void texto_setcorP(Texto t, char* corp)
{
    free(((texto*)t) -> corp);
    ((texto*)t) -> corp = (char*)malloc(strlen(corp) + 1);
    strcpy(((texto*)t) -> corp, corp);
}

void texto_setcorB(Texto t, char* corb)
{
    free(((texto*)t) -> corb);
    ((texto*)t) -> corb = (char*)malloc(strlen(corb) + 1);
    strcpy(((texto*)t) -> corb, corb);
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

void texto_setAnchor(Texto t, char *a)
{
    free(((texto*)t) -> a);
    ((texto*)t) -> a = (char*)malloc(strlen(a) + 1);
    strcpy(((texto*)t) -> a, a);
}