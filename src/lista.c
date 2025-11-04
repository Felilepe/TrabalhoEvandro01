#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

// --- Estruturas de Dados Internas (Privadas) ---

// Usamos uma lista duplamente encadeada para remoção
// e inserção eficiente em ambas as pontas (O(1)).
typedef struct nodeL {
    item data;          // O ponteiro void* (para a forma, etc.)
    struct nodeL *next;
    struct nodeL *prev; // Ponteiro para o nó anterior
} NodeL;

struct lista {
    NodeL *head;  // Ponteiro para o primeiro nó
    NodeL *tail;  // Ponteiro para o último nó
    int size;
};

// --- Implementação das Funções Públicas ---

Lista *lista_create()
{
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if(l == NULL){
        printf("Erro na alocacao de memoria ao criar lista.");
        exit(1);
    }
    
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

bool lista_isEmpty(Lista *l)
{
    return l->size == 0;
}

int lista_getSize(Lista *l)
{
    if(l == NULL) return 0;
    return l->size;
}

void lista_insere_inicio(Lista *l, item i)
{
    NodeL *novoNode = (NodeL*)malloc(sizeof(NodeL));
    if(novoNode == NULL){
        printf("Erro na alocacao de memoria ao criar novo no para lista.");
        exit(1);
    }
    
    novoNode->data = i;
    novoNode->prev = NULL;
    novoNode->next = l->head;

    if(lista_isEmpty(l)){
        // Se a lista está vazia, head e tail são o mesmo nó
        l->head = novoNode;
        l->tail = novoNode;
    } else {
        // Se não, o head antigo aponta 'prev' para o novo nó
        l->head->prev = novoNode;
        l->head = novoNode;
    }
    l->size++;
}

void lista_insere_fim(Lista *l, item i)
{
    NodeL *novoNode = (NodeL*)malloc(sizeof(NodeL));
    if(novoNode == NULL){
        printf("Erro na alocacao de memoria ao criar novo no para lista.");
        exit(1);
    }
    
    novoNode->data = i;
    novoNode->next = NULL;
    novoNode->prev = l->tail;

    if(lista_isEmpty(l)){
        // Se a lista está vazia, head e tail são o mesmo nó
        l->head = novoNode;
        l->tail = novoNode;
    } else {
        // Se não, o tail antigo aponta 'next' para o novo nó
        l->tail->next = novoNode;
        l->tail = novoNode;
    }
    l->size++;
}

item lista_remove_inicio(Lista *l)
{
    if(lista_isEmpty(l)){
        printf("Erro: Tentativa de remocao de lista vazia.");
        exit(1);
    }

    NodeL *nodeRemover = l->head;
    item itemRetornar = nodeRemover->data;
    
    l->head = nodeRemover->next; // O novo head é o próximo
    l->size--;

    if(lista_isEmpty(l)){
        // Se a lista ficou vazia, tail também é NULL
        l->tail = NULL;
    } else {
        // Se não, o novo head não tem 'prev'
        l->head->prev = NULL;
    }
    
    free(nodeRemover);
    return itemRetornar;
}

item lista_remove_fim(Lista *l)
{
    if(lista_isEmpty(l)){
        printf("Erro: Tentativa de remocao de lista vazia.");
        exit(1);
    }

    NodeL *nodeRemover = l->tail;
    item itemRetornar = nodeRemover->data;
    
    l->tail = nodeRemover->prev; // O novo tail é o anterior
    l->size--;

    if(lista_isEmpty(l)){
        // Se a lista ficou vazia, head também é NULL
        l->head = NULL;
    } else {
        // Se não, o novo tail não tem 'next'
        l->tail->next = NULL;
    }
    
    free(nodeRemover);
    return itemRetornar;
}

void lista_passthrough(Lista *l, void (*acao)(item i, item aux_data), item aux_data)
{
    if (l == NULL || acao == NULL || lista_isEmpty(l)) {
        return;
    }

    NodeL *atual = l->head;

    while (atual != NULL) {
        acao(atual->data, aux_data);
        atual = atual->next;
    }
}

void lista_destroy(Lista *l)
{
    if (l == NULL) return;

    NodeL *atual = l->head;
    
    // Libera todos os nós
    while(atual != NULL){
        NodeL *temp = atual;
        atual = atual->next;
        free(temp); // Libera apenas o nó, não o 'data' (consistente com fila/pilha)
    }
    
    // Libera a struct da lista
    free(l);
}