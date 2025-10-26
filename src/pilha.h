#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef void *item;
typedef struct pilha Pilha;

Pilha *pilha_create(); 
/****************************************************
*@brief cria uma pilha com tamanho = 0 e item = NULL*
*@return um pointeiro para a pilha inicializada     *
****************************************************/

bool pilha_isEmpty(Pilha *p); 
/******************************************************************** 
 *@brief Verifica se a pilha está vazia                              *
 *@param Pilha Ponteiro para pilha que será checada                  *
 *@return True se a pilha estiver vazia, caso contrário retorna False*
 ********************************************************************/

void pilha_push(Pilha *p, item i); 
/*****************************************************************
 *@brief Adiciona item ao topo da pilha                           *
 *@param Pilha Pointeiro para a pilha aonde será adicionado o item*
 *@param item Pointeiro para o item que será adicionado à pilha   *
 *****************************************************************/

 item pilha_pop(Pilha *p); 
/**********************************************************************************
*@brief Remove o item no topo da pilha, retorna um erro caso a pilha esteja vazia.*
*@param p Pointeiro para a pilha                                                  *
*@return Retorna o endereço para o item                                           *              
**********************************************************************************/

item pilha_peek(Pilha *p); 
/******************************************************************
*@brief Mostra o item no topo da pilha                            *
*@param p Pointeiro para a pilha que será checada                 *
*@return Retorna o ponteiro para o item que está no topo da pilha.*
*Retorna um erro caso a pilha esteja vaiza*                       *
******************************************************************/

int pilha_getSize(Pilha *p);
/******************************************************************
*@brief Pega o número de itens atualmente na pilha.               *
*@param p Ponteiro para a pilha.                                  *
*@return O número de itens (int) na pilha.                        *
******************************************************************/

void pilha_destroy(Pilha *p); 
/******************************************************************
*@brief Libera toda a memória alocada pela pilha (nós e estrutura)*
*@param p Ponteiro para a pilha a ser destruída                   *
*@return Não há retorno                                           *
******************************************************************/


#endif