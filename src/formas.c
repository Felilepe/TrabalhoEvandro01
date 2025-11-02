#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "linha.h"
#include "retangulo.h"
#include "texto.h"
#include "formas.h"

typedef struct forma_g
{
    int type;
} FormaG;

#define TIPO_C 1
#define TIPO_R 2
#define TIPO_L 3
#define TIPO_T 4



void forma_destroy(forma f)
{
    FormaG* forma_generica = (FormaG*)f;
    if(forma_generica == NULL) return;

    switch(forma_generica -> type){
        case(TIPO_C): circulo_destroy((Circulo)f); break;
        case(TIPO_R): retangulo_destroy((Retangulo)f); break;
        case(TIPO_L): linha_destroy((Linha)f); break;
        case(TIPO_T): texto_destroy((Texto)f); break;
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
}



int forma_getID(forma f)
{
    FormaG* forma_generica = (FormaG*)f;
    int ID;
    
    switch(forma_generica -> type){
        case(TIPO_C): ID = circulo_getID((Circulo)f);
        case(TIPO_R): ID = retangulo_getID((Retangulo)f);
        case(TIPO_L): ID = linha_getID((Linha)f);
        case(TIPO_T): ID = texto_getID((Texto)f);
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
    return  ID;
}



double forma_calcArea(forma f)
{
    FormaG* forma_generica = (FormaG*)f;
    double area;

    switch(forma_generica -> type){
        case(TIPO_C): area = circulo_calcArea((Circulo)f); break;
        case(TIPO_R): area = retangulo_calcArea((Retangulo)f); break;
        case(TIPO_L): area = linha_calcArea((Linha)f); break; 
        case(TIPO_T): area = texto_calcArea((Texto)f); break;
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
    return area;
}



double forma_getCoordX(forma f) 
{
    FormaG* forma_generica = (FormaG*)f;
    double coordx;
    
    switch(forma_generica -> type){
        case(TIPO_C): coordx = circulo_getCoordX((Circulo)f); break;
        case(TIPO_R): coordx = retangulo_getCoordX((Retangulo)f); break;
        case(TIPO_L): coordx = linha_getCoordX1((Linha)f); break; //Por convenção, x1 será considerado o X da âncora
        case(TIPO_T): coordx = texto_getCoordX((Texto)f); break;
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
    return coordx;
}

double forma_getCoordY(forma f)
{
    FormaG* forma_generica = (FormaG*)f;
    double coordy;

    switch(forma_generica -> type){
        case(TIPO_C): coordy = circulo_getCoordY((Circulo)f); break;
        case(TIPO_R): coordy = retangulo_getCoordY((Retangulo)f); break;
        case(TIPO_L): coordy = linha_getCoordY1((Linha)f); break; //Por convenção, y1 será considerado o Y da âncora
        case(TIPO_T): coordy = texto_getCoordY((Texto)f); break;
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
    return coordy;
}

char* forma_getCorBorda(forma f)
{
    FormaG* forma_generica = (FormaG*)f;
    char* corb;

    switch(forma_generica -> type){
        case(TIPO_C): corb =  circulo_getCorBorda((Circulo)f); break;
        case(TIPO_R): corb =  retangulo_getCorBorda((Retangulo)f); break;
        case(TIPO_L): corb =  linha_getCor((Linha)f); break; //Por convenção, como linha só possui o parâmetro "cor", iremos considerá-la a cor de "borda"
        case(TIPO_T): corb = texto_getCorBorda((Texto)f); break;
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
    return corb;
}

char* forma_getCorPreench(forma f)
{
    FormaG* forma_generica = (FormaG*)f;
    char* corp;

    switch(forma_generica -> type){
        case(TIPO_C): corp = circulo_getCorPreench((Circulo)f); break;
        case(TIPO_R): corp = retangulo_getCorPreench((Retangulo)f); break;
        case(TIPO_L): printf("Erro: tipo de forma invalido. Para linhas, utilize 'forma_getCorBorda'"); break; 
        case(TIPO_T): corp = texto_getCorBorda((Texto)f); break;
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
    return corp;
}



void forma_setCoordX(forma f, double x)
{
    FormaG* forma_generica = (FormaG*)f;

    switch(forma_generica -> type){
        case(TIPO_C): circulo_setCoordX((Circulo)f, x); break;
        case(TIPO_R): retangulo_setCoordX((Retangulo)f, x); break;
        case(TIPO_T): texto_setCoordX((Texto)f, x); break;
        case(TIPO_L): {
            Linha l = (Linha)f;

            double x1temp = linha_getCoordX1(l);
            double x2temp = linha_getCoordX2(l);

            double delta = x2temp - x1temp;

            linha_setCoordX1(l, x);
            linha_setCoordX2(l, (x + delta));
            break;
        }
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
}

void forma_setCoordY(forma f, double y)
{
    FormaG* forma_generica = (FormaG*)f;

    switch(forma_generica -> type){
        case(TIPO_C): circulo_setCoordY((Circulo)f, y); break;
        case(TIPO_R): retangulo_setCoordY((Retangulo)f, y); break;
        case(TIPO_T): texto_setCoordY((Texto)f, y); break;
        case(TIPO_L): {
            Linha l = (Linha)f;

            double y1temp = linha_getCoordY1(l);
            double y2temp = linha_getCoordY2(l);

            double delta = y2temp - y1temp;

            linha_setCoordY1(l, y);
            linha_setCoordY2(l, (y + delta));
            break;
        }
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
}

void forma_setCorBorda(forma f, char* corb)
{
    FormaG* forma_generica = (FormaG*)f;

    switch(forma_generica -> type){
        case(TIPO_C): circulo_setCorBorda((Circulo)f, corb); break;
        case(TIPO_R): retangulo_setCorBorda((Retangulo)f, corb); break;
        case(TIPO_L): linha_setCor((Linha)f, corb); break; //Mesma convenção do forma_getCorBorda
        case(TIPO_T): texto_setCorBorda((Texto)f, corb); break;
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
}

void forma_setCorPreench(forma f, char* corp)
{
    FormaG* forma_generica = (FormaG*)f;

    switch(forma_generica -> type){
        case(TIPO_C): circulo_setCorPreench((Circulo)f, corp); break;
        case(TIPO_R): retangulo_setCorPreench((Retangulo)f, corp); break;
        case(TIPO_L): printf("Erro: tipo de forma invalido. Para linhas, utilize 'forma_setCorBorda'"); break;         
        case(TIPO_T): texto_setCorPreench((Texto)f, corp); break;
        default: printf("Erro: tipo de forma invalido."); exit(1); break;
    }
}