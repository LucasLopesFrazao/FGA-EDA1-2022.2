#include <stdio.h>
#include <stdlib.h>

typedef struct fila_st {
    int elementos[100];
    int inicio, fim;
}fila_st;

int esta_vazia(struct fila_st *f) {
    return f->inicio == f->fim;
}

void enfilera(struct fila_st *f, int novo) {
    f->elementos[f->fim++] = novo;
}

int desenfilera(struct fila_st *f) {
    if(esta_vazia(f)) {
        printf("Fila vazia\n");
        return -1;
    }
    return f->elementos[f->inicio++];
}

void imprime_fila_ao_contrario(struct fila_st *f) {
    int aux = desenfilera(f);
    if(!esta_vazia(f)) {
        imprime_fila_ao_contrario(f);
    }
    printf("%d ", aux);
    enfilera(f, aux);
}

void imprime_fila(struct fila_st *f) {
    int aux = desenfilera(f);
    printf("%d ", aux);
    if(!esta_vazia(f)) {
        imprime_fila(f);
    }
    enfilera(f, aux);
}

int main()
{
    fila_st *fila = (fila_st *)malloc(sizeof(fila_st));
    fila->inicio = 0;

    enfilera(fila, 10);
    enfilera(fila, 20);
    enfilera(fila, -3);
    enfilera(fila, -15);
    enfilera(fila, 20);
    enfilera(fila, 50);

    imprime_fila_ao_contrario(fila);

    return 0;
}