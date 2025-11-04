#ifndef ARENA_H
#define ARENA_H

#include <stdio.h>

#include "fila.h"
#include "formas.h"
#include "lerGeo.h" // onde fica o definição de chão
#include "lista.h"


typedef struct arena Arena;

Arena *arena_create();


forma arena_add(Arena *a, forma *f);


forma arena_remove(Arena *a);

bool arena_isEmpty(Arena *a);

void arena_destroy(Arena **a);

int arena_getSize(Arena *a);


void processaArena(Arena *a, Chao *c, double *pontuacao_total, Fila *anotacoes_svg, FILE *arquivo_txt, int *formas_clonadas, int *formas_destruidas);

#endif 