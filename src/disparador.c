#include <stdio.h>
#include <stdlib.h>
#include "disparador.h"
#include "formas.h"
#include "carregador.h"

struct disparador
{
    Carregador *cesq, *cdir;
    forma pos_lanc;
    double x, y;
    int id;
};

Disparador *disparador_create(int id, double x, double y, Carregador *cesq, Carregador *cdir) 
{
    Disparador *d = (Disparador*)malloc(sizeof(Disparador));
    if(d == NULL){
        printf("Erro na alocacao de memoria ao criar disparador.");
        exit(1);
    }

    d -> id = id;
    d -> x = x;
    d -> y = y;

    d -> cdir = cdir;
    d -> cesq = cesq;
    d ->pos_lanc = NULL;

    return d;
}



int disparador_getId(Disparador *d)
{
    if(d == NULL){
        printf("Erro: Disparador nulo.");
        return NULL;
    }

    return d -> id;
}

double disparador_getCoordX(Disparador *d)
{
    if(d == NULL){
        printf("Erro: disparador nulo.");
        exit(1);
    }

    return d -> x;
}

double disparador_getCoordY(Disparador *d)
{
    if(d == NULL){
        printf("Erro: disparador nulo.");
        exit(1);
    }

    return d -> y;
}

Carregador *disparador_getCEsq(Disparador *d)
{
    if(d == NULL){
        printf("Erro: disparador nulo.");
        exit(1);
    }

    return d -> cesq;
}

Carregador *disparador_getCDir(Disparador *d)
{
    if(d == NULL){
        printf("Erro: disparador nulo.");
        exit(1);
    }

    return d -> cdir;
}

forma disparador_getFormaDisparo(Disparador *d)
{
    if(d == NULL){
        printf("Erro: disparador nulo.");
        exit(1);
    }

    return d -> pos_lanc;
}



void disparador_posicionarDisp(Disparador *d, double x, double y)
{
    if(d == NULL){
        printf("Erro: Disparador nulo.");
        return;
    }
    d -> x = x;
    d -> y = y;

}

void disparador_attachCarregador(Disparador *d, Carregador *cesq, Carregador *cdir) //atch
{
    d -> cesq = cesq;
    d -> cdir = cdir;

}

item disparador_shift(Disparador *d, char b, int n) //shft
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

forma disparador_disparar(Disparador *d, double dx, double dy)
{

    if (d == NULL) {
		printf("Erro: disparador nulo.\n");
		return NULL;
	}


	if (d -> pos_lanc == NULL) {
		printf("Nenhuma forma na posição de disparo.\n");
		return NULL;
	}

	forma disparada = d -> pos_lanc;
	d -> pos_lanc = NULL;

	double dispx = disparador_getCoordX(d);
	double dispy = disparador_getCoordY(d);

	double xfinal = dx + dispx;
	double yfinal = dy + dispy;

	forma_setCoordX(disparada, xfinal);
    forma_setCoordY(disparada, yfinal);


	return disparada;

}



void destrutorDisparador(Disparador **ptr_disparador) 
{
	if (ptr_disparador == NULL || *ptr_disparador == NULL) return;

	Disparador* d = *ptr_disparador;

	free(d);
	*ptr_disparador = NULL;
}