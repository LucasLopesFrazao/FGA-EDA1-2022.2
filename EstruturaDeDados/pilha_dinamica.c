#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no {
    int dado;
    struct no *prox;
} no;

typedef struct pilha{
    no *topo;
} pilha;

void inicializa_pilha_dinamica(pilha *p){
    p->topo = NULL;
}

void adiciona_pilha_dinamica(pilha *p, int valor){
    no *novo = (no*) malloc(sizeof(no));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int vazia_pilha_dinamica(pilha *p){
    return p->topo == NULL;
}

int remove_pilha_dinamica(pilha *p){
    if(vazia_pilha_dinamica(p)){
        printf("Pilha vazia!");
        return -1;
    }
    no *aux = p->topo;
    p->topo = p->topo->prox;
    int valor = aux->dado;
    free(aux);
    return valor;
}

void imprime_pilha_dinamica(pilha *p){
    if(vazia_pilha_dinamica(p)){
        printf("Pilha vazia!");
        return;
    }

    no *aux = p->topo;
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    pilha p;
    inicializa_pilha_dinamica(&p);

    adiciona_pilha_dinamica(&p, 1);
    adiciona_pilha_dinamica(&p, 2);
    adiciona_pilha_dinamica(&p, 3);
    adiciona_pilha_dinamica(&p, 4);

    imprime_pilha_dinamica(&p);

}