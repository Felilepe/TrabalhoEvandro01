#ifndef ARENA_H
#define ARENA_H

#include <stdio.h>

#include "fila.h"
#include "formas.h"
#include "lerQry.h"
#include "lista.h"


typedef Fila Chao;
typedef struct stArena Arena;
typedef struct stRepositorio repositorio;


Arena *criaArena();


forma *adicionaFormaArena(Arena *a, forma *f);


forma *removeFormaArena(Arena *a);


void destrutorArena(Arena **a);

int getArenaNumFormas(Arena *a);


void processaArena(Arena *a, Chao *c, double *pontuacao_total, Fila *anotacoes_svg, FILE *arquivo_txt, int *formas_clonadas, int *formas_destruidas, Lista *repo);

#endif 