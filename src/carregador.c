#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "formas.h"
#include <stdbool.h>
#include "carregador.h"
#include "pilha.h"

typedef struct carregador
{
    int id;
    Pilha *p;
} carregador;

Carregador *carregador_create(int id)
{
    carregador *c = (carregador*)malloc(sizeof(carregador));
    if(c == NULL){
        printf("Erro na alocacao de memoria ao criar carregador.");
        return NULL;
    }
    c -> id = id;
    c -> p = pilha_create();

    return c;
}

int carregador_getID(Carregador *c) {return ((carregador*)c) -> id;}

forma carregador_loadForma(Carregador *c, forma f)
{
    if(c == NULL || f == NULL){
        printf("Erro: carregador e/ou forma identificado(s) como sendo nulo.\n");
        return NULL;
    }
    
    carregador *mag = (carregador*)c;
    if(mag -> p == NULL){
        printf("Erro: pilha do carregador identificada como sendo nula.\n");
        return NULL;
    }

    pilha_push(mag -> p, f);

    return f;
}

forma carregador_loadFromChao(Carregador *c, Chao *h)
{
    if (c == NULL || h == NULL) {
		printf("Erro: chao e/ou carregador identificado(s) como sendo nulo.\n");
	}

    
    carregador *mag = (carregador*)c;

    carregador_loadForma(mag, fila_dequeue(h));
}

Chao *carregador_loadAmount(Chao *h, Carregador *c, int n)
{
    if (c == NULL || h == NULL) {
		if(n < 0) return fila_create();
        printf("Erro: chao e/ou carregador identificado(s) como sendo nulo.\n");
        return NULL;
	}

    Fila *Historico = fila_create();

    for(int i = 0; i < n; i++){
        if(fila_isEmpty(h)){
            printf("Chao foi esvaziado.\n");
            break;
        }
        fila_queue(Historico, fila_getHead(c));
        carregador_loadFromChao(c, h);
    }
}

bool carregador_isEmpty(Carregador *c)
{
    carregador *mag = (carregador*)c;
    if(c == NULL) return true;

    return pilha_isEmpty(mag -> p);
}

void carregador_destroy(Carregador **c_point)
{
    if (c_point == NULL || *c_point == NULL) {
		return;
	}

	carregador *c = *c_point;

	liberaPilha(c -> p, NULL);

	free(c);

	*c_point = NULL;
}


forma carregador_remove(Carregador *c)
{
    if(c == NULL){
        printf("Erro: Carregador Nulo.");
        return NULL;
    }

    carregador* mag = (carregador*)c;
        
        return pilha_pop(mag);
}
