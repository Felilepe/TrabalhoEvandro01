#include "lerQry.h"
#include "carregador.h"
#include "disparador.h"
#include "arena.h"
#include "formas.h"
#include "texto.h"
#include "fila.h"
#include "lista.h"
#include "pilha.h"
#include "lerGeo.h"
#include "colisoes.h" 
#include "linha.h"
#include "retangulo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512
#define COMANDO_SIZE 16

// --- Structs Internas ---

struct repositorio 
{
    Lista *Disparadores; // Lista sem ID
    Lista *Carregadores; // Lista sem ID
};

// (report_txt não é necessária se pds/lds não existem)

typedef struct stEstatisticas 
{
    int instrucoes_realizadas;
    int total_disparos;
    int formas_esmagadas;
    int formas_clonadas;
    double pontuacao_total;
} estatisticas;


// =================================================================
// FUNÇÕES DE BUSCA (Necessárias por a Lista não ter IDs)
// =================================================================

// Struct auxiliar para a busca
typedef struct {
    int id_alvo;
    void* resultado;
} SearchData;

// Callback para encontrar um Disparador por ID
static void acao_encontrar_disparador(item i, item aux_data)
{
    SearchData* search = (SearchData*)aux_data;
    if (search->resultado != NULL) return; // Já encontrou

    Disparador* d = (Disparador*)i;
    // (Assumindo que o seu TAD Disparador tem esta função)
    if (disparador_getID(d) == search->id_alvo) {
        search->resultado = d;
    }
}

// Callback para encontrar um Carregador por ID
static void acao_encontrar_carregador(item i, item aux_data)
{
    SearchData* search = (SearchData*)aux_data;
    if (search->resultado != NULL) return; // Já encontrou

    Carregador* c = (Carregador*)i;
    // (Assumindo que o seu TAD Carregador tem esta função)
    if (carregador_getID(c) == search->id_alvo) {
        search->resultado = c;
    }
}

/*
 * Função principal de busca (Ineficiente, O(N), mas necessária)
 */
static void* encontrar_item_na_lista(Lista *lista, int id, void (*callback)(item, item))
{
    SearchData data;
    data.id_alvo = id;
    data.resultado = NULL;
    
    lista_passthrough(lista, callback, &data);
    
    return data.resultado; // Retorna o item (Disparador/Carregador) ou NULL
}

/*
 * Funções 'encontrarOuCriar' que agora usam a busca O(N)
 * (Baseado na sua lógica de arrays original)
 */
static Disparador* encontrarOuCriarDisparador(Repositorio *repo, int id)
{
    Disparador *d = (Disparador*) encontrar_item_na_lista(repo->Disparadores, id, acao_encontrar_disparador);
    
    if (d == NULL) {
        // (Assumindo que disparador_create(id, x, y) existe)
        d = disparador_create(id, 0, 0, NULL, NULL); // (Cria em 0,0 por defeito)
        if(d == NULL) return NULL;
        lista_insere_fim(repo->Disparadores, (item)d);
    }
    return d;
}

static Carregador* encontrarOuCriarCarregador(Repositorio *repo, int id)
{
    Carregador *c = (Carregador*) encontrar_item_na_lista(repo->Carregadores, id, acao_encontrar_carregador);

    if (c == NULL) {
        c = carregador_create(id); // (Assumindo que carregador_create(id) existe)
        if(c == NULL) return NULL;
        lista_insere_fim(repo->Carregadores, (item)c);
    }
    return c;
}


// =================================================================
// Funções de Callback (Callbacks para limpeza/relatórios)
// =================================================================

static void esvaziar_carregador_no_chao(item i, item aux_data)
{
    Carregador* car = (Carregador*)i;
    Fila* chao = (Fila*)aux_data; 
    while (!carregador_isEmpty(car)) { // (Assumido)
        // CORREÇÃO: 'forma' (void*) em vez de 'forma*' (void**)
        forma f = carregador_remove(car); // f é void* (Assumido)
        if (f != NULL) {
            fila_queue(chao, f);
        }
    }
}

static void esvaziar_disparador_no_chao(item i, item aux_data)
{
    Disparador* d = (Disparador*)i;
    Fila* chao = (Fila*)aux_data; 
    // CORREÇÃO: 'forma' (void*) em vez de 'forma*' (void**)
    forma f = disparador_getFormaDisparo(d); // f é void* (Assumido)
    if (f != NULL) {
        fila_queue(chao, f);
        disparador_removeForma(d, f); // (Assumido)
    }
}

static void limpar_forma_do_disparador_se_igual(item i, item aux_data)
{
    Disparador* d = (Disparador*)i;
    forma f_alvo = (forma)aux_data; // f_alvo é void*
    forma f_no_disparador = disparador_getFormaDisparo(d);
    if (f_no_disparador != NULL && f_no_disparador == f_alvo) {
        disparador_removeForma(d, f_alvo); 
    }
}

// (Usada por 'lc' e 'rjd' para reportar formas)
static void acao_reportar_forma(item i, item aux_data)
{
    // CORREÇÃO: 'forma' (void*) em vez de 'forma*' (void**)
    forma f = (forma)i; // f é void*
    FILE* arquivo_txt = (FILE*)aux_data;
    if (f != NULL && arquivo_txt != NULL) {
        // CORREÇÃO: Usando a função do TAD Formas
        forma_exportarDados(f, arquivo_txt, "  ->");
    }
}

// =================================================================
// Funções Públicas (Gestão do Repositório)
// =================================================================

Repositorio* criarRepositorio()
{
    Repositorio *repo = (Repositorio*) malloc(sizeof(Repositorio));
    if (repo == NULL) {
        printf("Erro: Falha ao alocar repositorio.\n");
        exit(1);
    }
    repo->Disparadores = lista_create();
    repo->Carregadores = lista_create();
    return repo;
}

void destrutorRepositorio(Repositorio *repo)
{
    if (repo == NULL) return;
    // (NOTA: Faltam callbacks para destruir os 'Disparador' e 'Carregador' internos)
    // (ex: lista_passthrough(repo->Disparadores, disparador_destroy_callback, NULL);)
    lista_destroy(repo->Disparadores);
    lista_destroy(repo->Carregadores);
    free(repo);
}

void limpaFormaDeTodosDisparadores(Repositorio *repo, forma f) 
{
    if (repo == NULL || f == NULL) return;
    // CORREÇÃO: 'forma' (void*) em vez de 'forma*' (void**)
    lista_passthrough(repo->Disparadores, limpar_forma_do_disparador_se_igual, (item)f);
}

void devolveFormasDisparadoresParaChao(Repositorio *repo, Chao *c) 
{
    if (repo == NULL || c == NULL) return;
    lista_passthrough(repo->Disparadores, esvaziar_disparador_no_chao, (item)c);
}

void devolveFormasCarregadoresParaChao(Repositorio *repo, Chao *c) 
{
    if (repo == NULL || c == NULL) return;
    lista_passthrough(repo->Carregadores, esvaziar_carregador_no_chao, (item)c);
}

// =================================================================
// Funções Auxiliares (Simulação e Anotações)
// =================================================================

static void criar_anotacoes_visuais(int id, double x_inicial, double y_inicial,
                                    double x_final, double y_final, Fila* filaSVG) {
    double tam_caixa = 20.0;
    // CORREÇÃO: Usando os TADs corretos (sem 'criaForma')
    Retangulo caixa_id = retangulo_create(-1,
        x_inicial - (tam_caixa / 2.0),
        y_inicial + (tam_caixa / 2.0),
        tam_caixa, tam_caixa, "red", "none");
    fila_queue(filaSVG, (forma)caixa_id);

    char id_str[16];
    sprintf(id_str, "%d", id);
    
    // CORREÇÃO: Usando o TAD Texto (sem 'criaEstilo')
    Texto texto_id = texto_create(-1, x_inicial, y_inicial, "red", "red", 'm', id_str);
    texto_setFamily(texto_id, "sans-serif");
    texto_setWeight(texto_id, "bold");
    texto_setSize(texto_id, "12px");
    fila_queue(filaSVG, (forma)texto_id);

    // CORREÇÃO: Usando o TAD Linha
    Linha proj_y = linha_create(-1, x_final, y_inicial, x_final, y_final, "#FF0000", true);
    fila_queue(filaSVG, (forma)proj_y);

    Linha proj_x = linha_create(-1, x_inicial, y_final, x_final, y_final, "#FF0000", true);
    fila_queue(filaSVG, (forma)proj_x);
}


/*
 * Esta é a função que executa a lógica do 'calc' (a simulação da arena).
 * (Renomeada de 'processaArena' para evitar confusão, como você sugeriu)
 */
static void executar_simulacao_calc(Arena *a, Chao *c, double *pontuacao_total, Fila *anotacoes_svg,
                   FILE *arquivo_txt, int *formas_clonadas, int *formas_esmagadas, Repositorio *repo) {
    if (c == NULL || a == NULL || arquivo_txt == NULL) {
        return;
    }
    double area_esmagada_round = 0.0;

    // (Assumindo que o TAD Arena tem arena_getSize e arena_remove)
    while (arena_getSize(a) >= 2) {
        forma forma_I = arena_remove(a);
        forma forma_J = arena_remove(a);

        if (checarColisao(forma_I, forma_J)) {
            double area_I = forma_calcArea(forma_I);
            double area_J = forma_calcArea(forma_J);

            fprintf(arquivo_txt, "Forma %d (I) vs Forma %d (J). HOUVE SOBREPOSIÇÃO.\n",
                    forma_getID(forma_I), forma_getID(forma_J));

            if (area_I < area_J) {
                fprintf(arquivo_txt,
                        "<<<-- I < J -->>> forma %d (I) (área %.2f) foi esmagada por forma %d (J) (área %.2f).\n",
                         forma_getID(forma_I), area_I, forma_getID(forma_J), area_J);

                if (repo != NULL) {
                    limpaFormaDeTodosDisparadores(repo, forma_I);
                }
                double x_esmagada = forma_getCoordX(forma_I);
                double y_esmagada = forma_getCoordY(forma_I);

                Texto asterisco = texto_create(-1, x_esmagada, y_esmagada, "red", "black", 'm', "*");
                texto_setFamily(asterisco, "sans-serif");
                texto_setWeight(asterisco, "bold");
                texto_setSize(asterisco, "30px");
                
                fila_queue(anotacoes_svg, (forma)asterisco);

                *pontuacao_total += area_I;
                area_esmagada_round += area_I;
                if (formas_esmagadas != NULL) (*formas_esmagadas)++;

                forma_destroy(forma_I);
                fila_queue(c, forma_J);

            } else if (area_I >= area_J) {
                fprintf(arquivo_txt,
                        "<<<-- I >= J -->>>\n forma %d (I) (área %.2f) modificou a forma %d (J) (área %.2f).\n\n",
                         forma_getID(forma_I), area_I, forma_getID(forma_J), area_J);

                forma clone_I = NULL;

                if (forma_getType(forma_I) == TIPO_T) {
                    char* cor_original_I = forma_getCorBorda(forma_I);
                    char* cor_complementar = forma_getCorComp(cor_original_I);

                    forma_setCorBorda(forma_J, cor_complementar);
                    clone_I = forma_clonar(forma_I);
                    forma_setCorBorda(clone_I, cor_complementar);
                    free(cor_complementar);
                } else {
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
    // (Assumindo que arena_isEmpty existe)
    if (!arena_isEmpty(a)) {
        fila_queue(c, arena_remove(a));
    }
    fprintf(arquivo_txt, "Área total esmagada no round: %.2f\n", area_esmagada_round);
}

static void imprimir_relatorio_final(FILE* arquivo_txt, estatisticas* stats) {
    fprintf(arquivo_txt, "\n--- ESTATISTICAS FINAIS ---\n");
    fprintf(arquivo_txt, "Instrucoes realizadas: %d\n", stats->instrucoes_realizadas);
    fprintf(arquivo_txt, "Total de disparos: %d\n", stats->total_disparos);
    fprintf(arquivo_txt, "Formas clonadas: %d\n", stats->formas_clonadas);
    fprintf(arquivo_txt, "Formas esmagadas: %d\n", stats->formas_esmagadas);
    fprintf(arquivo_txt, "Pontuacao Total: %.2f\n", stats->pontuacao_total);
}

// =================================================================
// Funções de Processamento de Comandos (Implementações)
// =================================================================

static void processar_pd(char* linha, Repositorio* repo, estatisticas* stats) {
    int id;
    double x, y;
    sscanf(linha, "pd %i %lf %lf", &id, &x, &y);
    Disparador *d = encontrarOuCriarDisparador(repo, id);
    if (d) {
        disparador_move(d, x, y); // (Função do TAD Disparador)
        stats -> instrucoes_realizadas++;
    }
}

static void processar_lc(char* linha, Repositorio* repo, Chao* chao, FILE* arquivo_txt, estatisticas* stats) {
    int id, n;
    sscanf(linha, "lc %i %i", &id, &n);
    Carregador *c = encontrarOuCriarCarregador(repo, id);
    if (c) {
        stats -> instrucoes_realizadas++;
        Fila *formas_carregadas = carregador_loadAmount(chao, c, n); // (Função do TAD Carregador)
        if (formas_carregadas != NULL) {
            fila_passthrough(formas_carregadas, acao_reportar_forma, arquivo_txt);
            fila_destroy(formas_carregadas);
        }
    }
}

static void processar_atch(char* linha, Repositorio* repo, estatisticas* stats) {
    int id1, id2, id3;
    sscanf(linha, "atch %i %i %i", &id1, &id2, &id3);
    Disparador *d = encontrarOuCriarDisparador(repo, id1); 
    Carregador *c1 = encontrarOuCriarCarregador(repo, id2);
    Carregador *c2 = encontrarOuCriarCarregador(repo, id3);
    if (d && c1 && c2) {
        disparador_attachCarregador(d, c1, c2); // (Função do TAD Disparador)
        stats -> instrucoes_realizadas++;
    }
}

static void processar_shft(char* linha, Repositorio* repo, FILE* arquivo_txt, estatisticas* stats) {
    int id, n;
    char botao;
    sscanf(linha, "shft %i %c %i", &id, &botao, &n);
    // 'shft' não cria, apenas modifica
    Disparador *d = (Disparador*) encontrar_item_na_lista(repo->Disparadores, id, acao_encontrar_disparador);
    if (d) {
        stats->instrucoes_realizadas++;
        disparador_shift(d, botao, n); // (Função do TAD Disparador)
        forma forma_final = disparador_getFormaDisparo(d);
        if (forma_final) {
            forma_exportarDados(forma_final, arquivo_txt, "  -> Forma final:");
        } else {
            fprintf(arquivo_txt, "Nenhuma forma na posição de disparo!\n");
        }
    }
}

static void processar_dsp(char* linha, Repositorio* repo, Arena* arena,
                           FILE* arquivo_txt, Fila* filaSVG, estatisticas* stats) {
    int id;
    double dx, dy;
    char flag_visual[4] = "";
    int campos_lidos = sscanf(linha, "dsp %d %lf %lf %3s", &id, &dx, &dy, flag_visual);

    Disparador* d = (Disparador*) encontrar_item_na_lista(repo->Disparadores, id, acao_encontrar_disparador);
    if (d) {
        stats->instrucoes_realizadas++;
        double x_inicial = disparador_getCoordX(d); // (Assumido)
        double y_inicial = disparador_getCoordY(d); // (Assumido)
        
        forma forma_disparada = disparador_disparar(d, dx, dy); // (Assumido)

        if (forma_disparada) {
            stats->total_disparos++;
            arena_add(arena, forma_disparada); // (Assumido)

            double x_final = forma_getCoordX(forma_disparada);
            double y_final = forma_getCoordY(forma_disparada);
            forma_exportarDados(forma_disparada, arquivo_txt, "  -> Forma disparada:");

            if (campos_lidos == 4 && strcmp(flag_visual, "v") == 0) {
                criar_anotacoes_visuais(id, x_inicial, y_inicial, x_final, y_final, filaSVG);
            }
        } else {
            fprintf(arquivo_txt, "-> Falha no disparo: Nenhuma forma na posição de disparo.\n");
        }
    }
}

static void processar_rjd(char* linha, Repositorio* repo, Arena* arena,
                           FILE* arquivo_txt, estatisticas* stats) {
    int id;
    char botao;
    double dx, dy, ix, iy;
    sscanf(linha, "rjd %i %c %lf %lf %lf %lf", &id, &botao, &dx, &dy, &ix, &iy);

    Disparador *d = (Disparador*) encontrar_item_na_lista(repo->Disparadores, id, acao_encontrar_disparador);
    if (d) {
        stats->instrucoes_realizadas++;
        Fila *formas_disparadas = disparador_rajada(d, botao, dx, dy, ix, iy, arena); // (Assumido)
        if (formas_disparadas != NULL) {
            int tamFilaDisparos = fila_getSize(formas_disparadas);
            stats->total_disparos += tamFilaDisparos;
            fila_passthrough(formas_disparadas, acao_reportar_forma, arquivo_txt);
            fila_destroy(formas_disparadas);
        }
    }
}

static void processar_calc(Repositorio* repo, Arena* arena, Chao* chao,
                           FILE* arquivo_txt, Fila* filaSVG, estatisticas* stats) {
    stats->instrucoes_realizadas++;
    executar_simulacao_calc(arena, chao, &stats->pontuacao_total, filaSVG, arquivo_txt,
                  &stats->formas_clonadas, &stats->formas_esmagadas, repo);
}

// =================================================================
// Função Principal
// =================================================================

void processaQry(Repositorio *repo, char *nome_path_qry, const char *nome_txt, 
                 Arena *arena, Chao *chao, double *pontuacao_total,
                 Fila *filaSVG, int *formas_clonadas, int *formas_esmagadas) 
{
    FILE *arquivo_qry = fopen(nome_path_qry, "r");
    if (arquivo_qry == NULL) {
        perror("Erro ao abrir o arquivo .qry");
        return;
    }

    FILE* arquivo_txt = fopen(nome_txt, "w");
    if (arquivo_txt == NULL) {
        perror("Erro ao criar o arquivo .txt");
        fclose(arquivo_qry);
        return;
    }

    estatisticas stats = {0, 0, *formas_esmagadas, *formas_clonadas, *pontuacao_total};
    char linha_buffer[BUFFER_SIZE];
    char comando[COMANDO_SIZE] = "";

    while (fgets(linha_buffer, sizeof(linha_buffer), arquivo_qry) != NULL) {
        sscanf(linha_buffer, "%s", comando);
        fprintf(arquivo_txt, "[*] %s", linha_buffer);
        
        if (strncmp(comando, "pd", 2) == 0) {
            processar_pd(linha_buffer, repo, &stats);
        }
        else if (strncmp(comando, "lc", 2) == 0) {
            processar_lc(linha_buffer, repo, chao, arquivo_txt, &stats);
        }
        else if (strncmp(comando, "atch", 4) == 0) {
            processar_atch(linha_buffer, repo, &stats);
        }
        else if (strncmp(comando, "shft", 4) == 0) {
            processar_shft(linha_buffer, repo, arquivo_txt, &stats);
        }
        else if (strncmp(comando, "dsp", 3) == 0) {
            processar_dsp(linha_buffer, repo, arena, arquivo_txt, filaSVG, &stats);
        }
        else if (strncmp(comando, "rjd", 3) == 0) {
            processar_rjd(linha_buffer, repo, arena, arquivo_txt, &stats);
        }
        else if (strncmp(comando, "calc", 4) == 0) {
            processar_calc(repo, arena, chao, arquivo_txt, filaSVG, &stats);
        }
        // Os comandos 'pds' e 'lds' (que eu inventei) foram removidos 
        // para corresponder à sua imagem de comandos (image_646c42.png).
    }

    *pontuacao_total = stats.pontuacao_total;
    *formas_clonadas = stats.formas_clonadas;
    *formas_esmagadas = stats.formas_esmagadas;

    imprimir_relatorio_final(arquivo_txt, &stats);

    fclose(arquivo_qry);
    fclose(arquivo_txt);
}