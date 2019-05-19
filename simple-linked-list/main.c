#include <stdbool.h>
#include <unistd.h>
#include "utils.h"

int main(int argc, char const *argv[])
{
    LISTA l;
    REGISTRO r;
    int op;
    inicializar(&l);

    while(true){
        menu();
        printf("Digite uma operação: ");
        scanf("%d", &op);

        switch(op)
        {
            case 0:
                system("clear");
                desalocarLista(&l);
                exit(0);
            case 1:
                system("clear");
                inserir(&l, r);
                sleep(2);
                system("clear");
                break;
            case 2:
                system("clear");
                exibir(&l);
                sleep(4);
                system("clear");
                break;
            case 3:
                system("clear");
                excluir(&l, r);
                sleep(2);
                system("clear");
                break;
            case 4:
                system("clear");
                desalocarLista(&l);
                sleep(2);
                system("clear");
                break;
            default:
                puts("Opção inválida");
                break;
        }
    }
    
    return 0;
}
