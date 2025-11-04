#ifndef ARENA_H
#define ARENA_H

#include <stdio.h>
#include <stdbool.h>

#include "fila.h"
#include "formas.h"
#include "lerGeo.h" // onde fica o definição de chão (typedef Fila Chao)
#include "lista.h"

typedef struct arena Arena;

/* Cria e inicializa uma nova Arena (fila de combate). */
Arena *arena_create();

/* Adiciona uma forma (opaca) à fila da Arena. Retorna a forma adicionada. */
forma arena_add(Arena *a, forma f);

/* Remove e retorna a próxima forma da fila da Arena. */
forma arena_remove(Arena *a);

/* Verifica se a Arena está vazia. */
bool arena_isEmpty(Arena *a);

/* Libera toda a memória associada à Arena (recebe ponteiro para ponteiro). */
void arena_destroy(Arena **a);

/* Obtém o número de formas atualmente na Arena. */
int arena_getSize(Arena *a);

/* Processa um "round" de combate na Arena. */
void processaArena(Arena *a, Chao *c, double *pontuacao_total, Fila *anotacoes_svg, FILE *arquivo_txt, int *formas_clonadas, int *formas_destruidas);

#endif