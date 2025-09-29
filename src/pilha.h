#ifndef PILHA_H
#define PILHA_H


typedef void* Stack, *item;

stack createPilha(); 
/**************************************************
*@brief cria uma pilha com tamanho = 0 item = NULL*
*@return um pointeiro para a pilha inicializada   *
**************************************************/

void *popPilha(stack *Stack); 
/*******************************************************************************
*@brief Remove o item no topo da pilha, retorna NULL caso a pilha esteja vazia.*
*@param Stack Pointeiro para a pilha                                           *
*@return Retorna o endereço para o item                                        *              
*******************************************************************************/

void pushPilha(stack *Stack, void *item); 
/*****************************************************************
*@brief Adiciona item ao topo da pilha                           *
*@param Stack Pointeiro para a pilha aonde será adicionado o item*
*@param item Pointeiro para o item que será adicionado à pilha   *
*****************************************************************/

void *peekPilha(stack *Stack); 
/******************************************************************
*@brief Mostra o item no topo da pilha                            *
*@param Stack Pointeiro para a pilha que será checada             *
*@return Retorna o ponteiro para o item que está no topo da pilha.*
*Retorna NULL caso a pilha esteja vaiza*                          *
******************************************************************/

bool isEmpty(stack *Stack); 
/******************************************************************** 
*@brief Verifica se a pilha está vazia                              *
*@param Stack Ponteiro para pilha que será checada                  *
*@return True se a pilha estiver vazia, caso contrário retorna False*
********************************************************************/


#endif