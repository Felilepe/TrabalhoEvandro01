#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

// Definimos 'item' da mesma forma que em fila.h e pilha.h
// para consistência.
typedef void *item;
typedef struct lista Lista;

/****************************************************
*@brief Cria uma lista vazia.
*@return Um ponteiro para a lista inicializada.
****************************************************/
Lista *lista_create();

/******************************************************************** 
 * *@brief Verifica se a lista está vazia.
 *@param l Ponteiro para a lista que será checada.
 *@return True se a lista estiver vazia, caso contrário False.
 ********************************************************************/
bool lista_isEmpty(Lista *l);

/*****************************************************************
 *@brief Adiciona um item à lista, associado a um ID.
 *@param l Ponteiro para a lista.
 *@param id O ID (int) a ser associado ao item.
 *@param i O item (void*) a ser adicionado.
 *****************************************************************/
void lista_insere(Lista *l, int id, item i);

/**********************************************************************************
*@brief Busca e retorna um item na lista pelo seu ID.
*@param l Ponteiro para a lista.
*@param id O ID (int) do item a ser buscado.
*@return Retorna o ponteiro para o item (void*) se encontrado, ou NULL se não.
**********************************************************************************/
item lista_get(Lista *l, int id);

/**********************************************************************************
*@brief Remove e retorna um item na lista pelo seu ID.
*@param l Ponteiro para a lista.
*@param id O ID (int) do item a ser removido.
*@return Retorna o ponteiro para o item (void*) se removido, ou NULL se não.
*@note O item (forma, etc.) não é destruído, apenas o nó da lista.
**********************************************************************************/
item lista_remove(Lista *l, int id);

/******************************************************************
*@brief Pega o número de itens atualmente na lista.
*@param l Ponteiro para a lista.
*@return O número de itens (int) na lista.
******************************************************************/
int lista_getSize(Lista *l);

/******************************************************************
*@brief Libera toda a memória alocada pelos nós da lista.
*@note NÃO libera a memória dos 'itens' (dados) armazenados.
*@param l Ponteiro para a lista a ser destruída.
******************************************************************/
void lista_destroy(Lista *l);

/*****************************************************************************
*@brief Percorre a lista e executa uma função 'acao' para cada item.
* Modelado a partir de fila_passthrough.
*@param l Ponteiro para a lista.
*@param acao A função de callback a ser executada em cada item.
*@param aux_data Um ponteiro auxiliar para ser passado para a função 'acao'.
*****************************************************************************/
void lista_passthrough(Lista *l, void (*acao)(int id, item i, item aux_data), item aux_data);

#endif