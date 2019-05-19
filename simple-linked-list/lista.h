#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
}REGISTRO;

typedef struct aux {
    REGISTRO r;
    struct aux * prox;
}ITEM;

typedef ITEM * PONT;

typedef struct {
    PONT inicio;
}LISTA;

void inicializar(LISTA * l);
PONT criarElemento(REGISTRO r);
PONT ultimoElemento(LISTA *l);
void inserirItem(LISTA *l, REGISTRO r);
void exibir(LISTA *l);
void excluirItem(LISTA *l, int ch);
void desalocarLista(LISTA *l);
