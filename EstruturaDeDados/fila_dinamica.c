#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no
{
    int dado;
    struct no *prox;
} no;

typedef struct fila
{
    no *ini;
    no *fim;

} fila;

void inicializa_fila_dinamica(fila *f)
{
    f->ini = NULL;
    f->fim = NULL;
}

void adiciona_fila_dinamica(fila *f, int valor)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->dado = valor;
    novo->prox = NULL;
    if (f->ini == NULL)
    {
        f->ini = novo;
    }
    if (f->fim != NULL)
    {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

int remove_fila_dinamica(fila *f)
{
    if (f->ini == NULL)
    {
        printf("Fila vazia!");
        return -1;
    }
    no *aux = f->ini;
    f->ini = f->ini->prox;
    aux->prox = NULL;
    int valor = aux->dado;
    free(aux);
    return valor;
}

void imprime_fila_dinamica(fila *f)
{
    if (f->ini == NULL)
    {
        printf("Fila vazia!");
        return;
    }

    no *aux = f->ini;
    while (aux != NULL)
    {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    fila f;
    inicializa_fila_dinamica(&f);

    adiciona_fila_dinamica(&f, 1);
    adiciona_fila_dinamica(&f, 2);
    adiciona_fila_dinamica(&f, 3);
    adiciona_fila_dinamica(&f, 4);

    imprime_fila_dinamica(&f);

    remove_fila_dinamica(&f);

    imprime_fila_dinamica(&f);

}