#ifndef LERQRY_H
#define LERQRY_H

#include "fila.h"
#include "lista.h"      // O seu TAD Lista (sem ID)
#include "formas.h"
#include "lerGeo.h"     // Para o tipo Chao
#include "arena.h"      // Para o tipo Arena

// --- Definições de Tipos ---
typedef struct repositorio Repositorio; 

// --- Funções de Gestão do Repositório ---
Repositorio* criarRepositorio();
void destrutorRepositorio(Repositorio *repo);

// --- Funções de Gestão de Formas (usadas por processaArena) ---
void limpaFormaDeTodosDisparadores(Repositorio *repo, forma f);
void devolveFormasDisparadoresParaChao(Repositorio *repo, Chao *c);
void devolveFormasCarregadoresParaChao(Repositorio *repo, Chao *c);

// --- Função Principal do Módulo ---
void processaQry(Repositorio *repo, char *nome_path_qry, const char *nome_txt, 
                 Arena *arena, Chao *chao, double *pontuacao_total,
                 Fila *filaSVG, int *formas_clonadas, int *formas_esmagadas);
#endif