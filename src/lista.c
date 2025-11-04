#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h" 



typedef struct nodeL {
    int id;      
    item data;    
    struct nodeL *next;
} NodeL;

struct lista {
    NodeL *head;  
    NodeL *tail;  
    int size;
};



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

void lista_insere(Lista *l, int id, item i)
{
    NodeL *novoNode = (NodeL*)malloc(sizeof(NodeL));
    if(novoNode == NULL){
        printf("Erro na alocacao de memoria ao criar novo no para lista.");
        exit(1);
    }
    
    novoNode->id = id;
    novoNode->data = i;
    novoNode->next = NULL;
    
    if(lista_isEmpty(l)){
        l->head = novoNode;
        l->tail = novoNode;
    } else {
        l->tail->next = novoNode;
        l->tail = novoNode;
    }

    l->size++;
}

item lista_get(Lista *l, int id)
{
    if (l == NULL) return NULL;

    NodeL *atual = l->head;
    
    
    while (atual != NULL) {
        if (atual->id == id) {
            return atual->data;
        }
        atual = atual->next;
    }
    
    return NULL;
}

item lista_remove(Lista *l, int id)
{
    if (l == NULL || lista_isEmpty(l)) return NULL;

    NodeL *atual = l->head;
    NodeL *anterior = NULL;

    while (atual != NULL && atual->id != id) {
        anterior = atual;
        atual = atual->next;
    }

    // 2. Se não encontrou, retorna NULL
    if (atual == NULL) {
        return NULL;
    }
    
    item dataToReturn = atual->data;

    // 3. Re-conecta os ponteiros da lista
    if (anterior == NULL) {
        // Caso 1: Removendo a cabeça (head)
        l->head = atual->next;
    } else {
        // Caso 2: Removendo do meio ou fim
        anterior->next = atual->next;
    }

    // 4. Se removeu a cauda (tail), atualiza a cauda
    if (l->head == NULL || atual->next == NULL) {
        l->tail = anterior; // Se anterior for NULL, tail vira NULL (lista vazia)
    }

    // 5. Libera o nó (mas não o 'data') e atualiza o tamanho
    free(atual);
    l->size--;

    return dataToReturn;
}

int lista_getSize(Lista *l)
{
    if(l == NULL) return 0;
    return l->size;
}

void lista_destroy(Lista* l)
{
    NodeL *atual = l->head;
    
    
    while(atual != NULL){
        NodeL *temp = atual;
        atual = atual->next;
        free(temp); 
    }
    
    
    free(l);
}

void lista_passthrough(Lista *l, void (*acao)(int id, item i, item aux_data), item aux_data)
{
    if (l == NULL || acao == NULL || lista_isEmpty(l)) {
        return;
    }

    NodeL *atual = l->head;

    while (atual != NULL) {
        acao(atual->id, atual->data, aux_data);
        atual = atual->next;
    }
}