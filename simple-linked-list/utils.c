#include "utils.h"

void menu(){
    puts("-------------------");
    puts("0 - Desalocar lista e sair do programa");
    puts("1 - inserir item");
    puts("2 - exibir lista");
    puts("3 - excluir item");
    puts("4 - desalocar lista");
}

void inserir(LISTA *l, REGISTRO r) {
    int qtd;
    printf("Digite a quantidade de elementos que deseja cadastrar: ");
    scanf("%d", &qtd);
    for(int i = 0; i < qtd; i++){
        printf("Digite um número: ");
        scanf("%d", &r.n);
        inserirItem(l, r);
    }
}

void excluir(LISTA *l, REGISTRO r){
    int qtd;
    printf("Digite a quantidade de elementos que deseja excluir: ");
    scanf("%d", &qtd);
    for(int i = 0; i < qtd; i++){
        printf("Digite um número: ");
        scanf("%d", &r.n);
        excluirItem(l, r.n);
    }
}