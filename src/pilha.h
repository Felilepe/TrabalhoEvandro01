#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef void *item;

typedef struct pilha Pilha;

Pilha *createPilha(); 
/**************************************************
*@brief cria uma pilha com tamanho = 0 item = NULL*
*@return um pointeiro para a pilha inicializada   *
**************************************************/

item popPilha(Pilha *pilha); 
/*******************************************************************************
*@brief Remove o item no topo da pilha, retorna NULL caso a pilha esteja vazia.*
*@param Pilha Pointeiro para a pilha                                           *
*@return Retorna o endereço para o item                                        *              
*******************************************************************************/

void pushPilha(Pilha *pilha, item Item); 
/*****************************************************************
*@brief Adiciona item ao topo da pilha                           *
*@param Pilha Pointeiro para a pilha aonde será adicionado o item*
*@param item Pointeiro para o item que será adicionado à pilha   *
*****************************************************************/

item peekPilha(Pilha *pilha); 
/******************************************************************
*@brief Mostra o item no topo da pilha                            *
*@param Pilha Pointeiro para a pilha que será checada             *
*@return Retorna o ponteiro para o item que está no topo da pilha.*
*Retorna NULL caso a pilha esteja vaiza*                          *
******************************************************************/

bool isEmpty(Pilha *pilha); 
/******************************************************************** 
*@brief Verifica se a pilha está vazia                              *
*@param Pilha Ponteiro para pilha que será checada                  *
*@return True se a pilha estiver vazia, caso contrário retorna False*
********************************************************************/

void destroyPilha(Pilha *pilha); 
/******************************************************************
*@brief Libera toda a memória alocada pela pilha (nós e estrutura)*
*@param pilha Ponteiro para a pilha a ser destruída               *
******************************************************************/

#endif