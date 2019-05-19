#include "lista.h"

void inicializar(LISTA * l){
    l->inicio = NULL;
}

PONT criarElemento(REGISTRO r){
    PONT novoItem = (PONT) malloc(sizeof(ITEM));
    if(novoItem == NULL){
        fprintf(stderr, "Error in memory allocation");
        exit(-1);
    }
    novoItem->r = r;
    novoItem->prox = NULL;

    return novoItem; 
}

PONT ultimoElemento(LISTA *l){
    if(l->inicio == NULL){
        puts("[DEBUG] Lista vazia");
        return NULL;
    }

    PONT iter = l->inicio;
    PONT ultimo;

    while(iter != NULL){
        ultimo = iter;
        iter = iter->prox;
    }

    return ultimo;
}

void inserirItem(LISTA *l, REGISTRO r){
    PONT anterior, item;

    anterior = ultimoElemento(l);

    if(anterior == NULL){
        item = criarElemento(r);
        l->inicio = item;
        puts("[DEBUG] Primeiro item foi alocado");
        return;
    }else{
        item = criarElemento(r);
        anterior->prox = item;
        puts("[DEBUG] Item adicionado");
        return;
    }
}

void exibir(LISTA *l){
    if(l->inicio == NULL){
        puts("[DEBUG] Lista vazia!!!");
        return;
    }

    PONT iter = l->inicio;

    while(iter != NULL) {
        printf("Registro: %d\n", iter->r.n);
        iter = iter->prox;
    }
}

PONT auxiliar(LISTA *l, int ch){
    PONT anterior, aux;

    aux = l->inicio;
    while(aux != NULL && aux->r.n != ch)
    {
        anterior = aux;
        aux = aux->prox;
    }

    if(anterior == NULL){
        puts("[DEBUG] elemento não foi encontrado");
        return NULL;
    }

    printf("[DEBUG] Anterior ao possível item a ser excluido: %d\n", anterior->r.n);
    return anterior;
}

void excluirItem(LISTA *l, int ch){
    PONT anterior, iter;

    if(l->inicio == NULL){
        puts("[DEBUG] Lista vazia !!!!");
        exit(0);
    }

    anterior = auxiliar(l, ch);

    if(anterior != NULL){
        iter = l->inicio;

        while(iter != NULL)
        {
            if(iter->r.n == ch){
                anterior->prox = iter->prox;
                free(iter);
                puts("[DEBUG] elemento removido!!!");
                return;
            }
            iter = iter->prox;
        }

        puts("[DEBUG] elemento não foi encontrado....");
        return;
    }
}

void desalocarLista(LISTA *l){
    inicializar(l);
}