#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct texto
{
    int id;
    double x, y;
    char *corb, *corp, *txto;
    char a;
}texto;


double calcComp (char *txto)
{
    return
}

double calcAnc(double x, double y)
{

}


Texto texto_create(int id, double x, double y, char *corb, char *corp, char a, char* txto)
{
    texto *t = malloc(sizeof(texto));
    if(t == NULL){
        printf("Erro de alocacao de memoria ao criar texto");
        exit(1);
    }

    double tempX = x;

    switch(a){
        case 'i': break;
        case 'm': tempX =
    }

    t  -> id = id;
    t -> x = x;
    t -> y = y;
    t -> a = a;
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
