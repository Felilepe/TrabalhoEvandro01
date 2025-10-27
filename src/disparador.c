#include <stdio.h>
#include <stdlib.h>
#include "disparador.h"

struct disparador
{
    Pilha *cesq, *cdir;
    item pos_lanc;
    double x, y;
    int l;
};

Disparador *disparador_create(int l, double x, double y) //pd
{
    Disparador *d = (Disparador*)malloc(sizeof(Disparador));
    if(d == NULL){
        printf("Erro na alocacao de memoria ao criar disparador.");
        exit(1);
    }

    d -> l = l;
    d -> x = x;
    d -> y = y;

    d -> cdir = NULL;
    d -> cesq = NULL;
    d ->pos_lanc = NULL;

    return d;
}

void disparador_attachCarregador(Disparador *d, Pilha *cesq, Pilha *cdir)
{
    d -> cesq = cesq;
    d -> cdir = cdir;

}

item disparador_shift(Disparador *d, char b, int n)
{
    switch (b){
    case 'e': 
        for(int i = 0; i < n; i++){
            if(d -> pos_lanc != NULL){
                pilha_push(d -> cdir, d -> pos_lanc);
            }
            d -> pos_lanc = pilha_pop(d -> cesq);
        } break;
    case 'd':
        for(int i = 0; i < n; i++){
            if(d -> pos_lanc != NULL){
                pilha_push(d -> cesq, d ->pos_lanc);
            }
            d -> pos_lanc = pilha_pop(d -> cdir);
        } break;
    
    default: printf("Erro: Botao %c nao e uma opcao aceita.", b);
    exit(1);


    return d -> pos_lanc;
    }
}