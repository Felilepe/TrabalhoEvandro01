#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct texto
{
    int id;
    double x, y;
    char *corb, *corp, *txto, *fFamily, *fWeight, *fSize;
    char a;
}texto;


static double calcComp (char *txto) //Calcula o comprimento da linha
{
    return 10 * strlen(txto);
}
    


Texto texto_create(int id, double x, double y, char *corb, char *corp, char a, char* txto)
{
    texto *t = malloc(sizeof(texto));
    if(t == NULL){
        printf("Erro de alocacao de memoria ao criar texto");
        exit(1);
    }

 
    t  -> id = id;
    t -> x = x;
    t -> y = y;
    t -> a = a;

    
    t -> fFamily = (char*)malloc(strlen("Arial") + 1);
    if(t -> fFamily == NULL){
    printf("Erro de alocacao de memoria ao atribuir fonte inicial do texto.");
    exit(1);
    }
    strcpy(t -> fFamily, "Arial");
    
    t->fWeight = (char*)malloc(strlen("n") + 1);
    if(t -> fFamily == NULL){
    printf("Erro de alocacao de memoria ao atribuir peso inicial do texto.");
    exit(1);
    }
    strcpy(t->fWeight, "n");

    t -> fSize = (char*)malloc(strlen("12") + 1);
    if(t -> fFamily == NULL){
    printf("Erro de alocacao de memoria ao atribuir tamanho inicial do texto.");
    exit(1);
    }
    strcpy(t -> fSize, "12");
    
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


void texto_setStyle(Texto t, char *fFamily, char *fWeight, char* fSize)
{
    if(fFamily != NULL){
        free(((texto*)t) -> fFamily);
        ((texto*)t) -> fFamily = malloc(strlen(fFamily) + 1);
        strcpy(((texto*)t) -> fFamily, fFamily);
    } 
    

    if(fWeight != NULL){
        free(((texto*)t) -> fWeight);
        ((texto*)t) -> fWeight = malloc(strlen(fWeight) + 1);
        strcpy(((texto*)t) -> fWeight, fWeight); 
    } 
    

    if(fSize != NULL){
        free(((texto*)t) -> fSize);
        ((texto*)t) -> fSize = malloc(strlen(fSize) +1);
        strcpy(((texto*)t) -> fSize, fSize);
    }
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