#include "arena.h"
#include "fila.h"
#include "formas.h"
#include "colisoes.h"

#include <stdio.h>
#include <stdlib.h>



struct arena 
{
    Fila *filaArena;
};

Arena *arena_create() 
{
    Arena *a = (Arena*) malloc (sizeof(Arena));
    if (a == NULL) {
        printf("Erro ao criar a arena.\n");
        return NULL;
    }

    a -> filaArena = fila_create();



    return a;
}

forma arena_add(Arena *a, forma f) 
{
    if (f == NULL) {
        return NULL;
    }

    if (a == NULL) {
        printf("Arena inexistente passada para a função 'adicionaFormaArena'\n");
        return NULL;
    }

    fila_queue(a->filaArena, f);

    return f;
}

forma arena_remove(Arena *a) 
{
    if (a == NULL ) return NULL;

    forma removido = fila_dequeue(a -> filaArena);

    return removido;
}

bool arena_isEmpty(Arena *a) 
{
    if (a == NULL) return true;

    return fila_isEmpty(a -> filaArena);
}

void arena_destroy(Arena **a_ptr) 
{
    if (a_ptr == NULL || *a_ptr == NULL) {
        return;
    }
    Arena* a = *a_ptr;

    fila_destroy(a -> filaArena);

    free(a);
    *a_ptr = NULL;
}

int arena_getSize(Arena *a) 
{
    if (a == NULL) {
        return -1;
    }

    return fila_getSize(a -> filaArena);
}


void processaArena(Arena *a, Chao *c, double *pontuacao_total, Fila *anotacoes_svg,
                   FILE *arquivo_txt, int *formas_clonadas, int *formas_esmagadas) 
{
    if (c == NULL || a == NULL || arquivo_txt == NULL) {
        printf("Erro: Parâmetros nulos passados para processaArena!\n");
        return;
    }

    double area_esmagada_round = 0.0;

    // printf("\n=== INICIANDO PROCESSAMENTO DA ARENA ===\n");
    while (arena_getSize(a) >= 2) {
        
        // CORREÇÃO: 'forma' já é um ponteiro (void*), não 'forma*' (void**)
        forma forma_I = arena_remove(a);
        forma forma_J = arena_remove(a);

        // CORREÇÃO: Nome da função de colisão
        if (checarColisao(forma_I, forma_J)) {
            // printf("\nSobreposição detectada!\n");

            double area_I = forma_calcArea(forma_I);
            double area_J = forma_calcArea(forma_J);

            fprintf(arquivo_txt, "Forma %d (I) vs Forma %d (J). HOUVE SOBREPOSIÇÃO.\n",
                    forma_getID(forma_I), forma_getID(forma_J));

            if (area_I < area_J) {
                // ... (lógica de esmagar I) ...
                fprintf(arquivo_txt,
                        "<<<-- I < J -->>> forma %d (I) (área %.2f) foi esmagada por forma %d (J) (área %.2f).\n",
                         forma_getID(forma_I), area_I, forma_getID(forma_J), area_J);

                // if (repo != NULL) {
                //     limpaFormaDeTodosDisparadores(repo, forma_I);
                // }

                // CORREÇÃO: Nomes dos getters
                double x_esmagada = forma_getCoordX(forma_I);
                double y_esmagada = forma_getCoordY(forma_I);

                // CORREÇÃO: Lógica de criação de Texto
                // O seu TAD Texto usa estilo global, não local.
                // 1. Criar o texto (ele usará o estilo global atual)
                Texto asterisco = texto_create(-1, x_esmagada, y_esmagada, "red", "black", 'm', "*");

                // 2. Corrigir o estilo do asterisco manualmente
                texto_setFamily(asterisco, "sans-serif");
                texto_setWeight(asterisco, "bold");
                texto_setSize(asterisco, "30px");
                
                // CORREÇÃO: 'asterisco' JÁ É a forma, não use 'criaForma'
                fila_queue(anotacoes_svg, (forma)asterisco);

                *pontuacao_total += area_I;
                area_esmagada_round += area_I;
                if (formas_esmagadas != NULL) (*formas_esmagadas)++;

                forma_destroy(forma_I);
                fila_queue(c, forma_J); // 'c' é o Chao/Fila

            } else if (area_I >= area_J) {
                // ... (lógica de I modificar J) ...
                fprintf(arquivo_txt,
                        "<<<-- I >= J -->>>\n forma %d (I) (área %.2f) modificou a forma %d (J) (área %.2f).\n\n",
                         forma_getID(forma_I), area_I, forma_getID(forma_J), area_J);

                forma clone_I = NULL;

                if (forma_getType(forma_I) == TIPO_T) {
                    
                    // CORREÇÃO: Gestão de memória
                    char* cor_original_I = forma_getCorBorda(forma_I); // 1. Obter (não dar free)
                    char* cor_complementar = forma_getCorComp(cor_original_I); // 2. Alocar (malloc)

                    forma_setCorBorda(forma_J, cor_complementar); // 3. Usar (copiar)
                    
                    clone_I = forma_clonar(forma_I);

                    // 4. Corrigir a cor do clone (que é um Texto)
                    forma_setCorBorda(clone_I, cor_complementar);

                    // 5. Libertar a memória alocada
                    free(cor_complementar);

                } else {
                    // Lógica para Circulo/Retangulo/Linha (estava correta)
                    forma_setCorBorda(forma_J, forma_getCorPreench(forma_I));
                    clone_I = forma_clonar(forma_I);
                    forma_trocarCores(clone_I);
                }

                if (formas_clonadas != NULL) (*formas_clonadas)++;

                fila_queue(c, forma_I);
                fila_queue(c, forma_J);
                if (clone_I != NULL) {
                    fila_queue(c, clone_I);
                }
            }
        } else {
            fprintf(arquivo_txt, "Forma %d (I) vs Forma %d (J). NÃO HOUVE SOBREPOSIÇÃO.\n",
                    forma_getID(forma_I), forma_getID(forma_J));
            fila_queue(c, forma_I);
            fila_queue(c, forma_J);
        }
    }

    // Devolver a última forma que sobrou (se houver) para o chão
    if (!arena_isEmpty(a)) {
        fila_queue(c, arena_remove(a));
    }

    fprintf(arquivo_txt, "Área total esmagada no round: %.2f\n", area_esmagada_round);
}