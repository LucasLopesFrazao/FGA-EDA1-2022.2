#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
} no;

typedef struct{
    no *inicio;
    no *fim;
    int tam;
} lista;

void lista_duplamente_inicializa(lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void lista_duplamente_adiciona_inicio(lista *lista, int valor){
    no *novo = (no*) malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    novo->anterior = NULL;
    if(lista->inicio != NULL){
        lista->inicio->anterior = novo;
    }
    lista->inicio = novo;
    if(lista->fim == NULL){
        lista->fim = novo;
    }
    lista->tam++;
}

void lista_duplamente_adiciona_final(lista *lista, int valor){
    no *novo = (no*) malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->fim;
    if(lista->fim != NULL){
        lista->fim->proximo = novo;
    }
    lista->fim = novo;
    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
    lista->tam++;
}

void lista_duplamente_imprime(lista *lista){
    no *inicio = lista->inicio;
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

int lista_duplamente_remove_final(lista *lista){
    no *aux = lista->fim;
    no *anterior = aux->anterior;
    anterior->proximo = NULL;
    int valor = aux->valor;
    free(aux);
    lista->tam--;
    return valor;
}

int lista_duplamente_remove_inicio(lista *lista){
    no *aux = lista->inicio;
    no *proximo = aux->proximo;
    proximo->anterior = NULL;
    int valor = aux->valor;
    free(aux);
    lista->tam--;
    return valor;
}

int lista_duplamente_remove_elemento(lista *lista, int valor){
    no *aux = lista->inicio;
    no *anterior = NULL;
    while(aux != NULL){
        if(aux->valor == valor){
            if(anterior == NULL){
                lista_duplamente_remove_inicio(lista);
            }else if(aux->proximo == NULL){
                lista_duplamente_remove_final(lista);
            }else{
                anterior->proximo = aux->proximo;
                aux->proximo->anterior = anterior;
                free(aux);
                lista->tam--;
            }
            return 1;
        }
        anterior = aux;
        aux = aux->proximo;
    }
    return 0;
}

int main(){
    lista l;
    lista_duplamente_inicializa(&l);
    lista_duplamente_adiciona_inicio(&l, 1);
    lista_duplamente_adiciona_inicio(&l, 2);
    lista_duplamente_adiciona_inicio(&l, 3);

    lista_duplamente_adiciona_final(&l, 4);
    lista_duplamente_adiciona_final(&l, 5);
    lista_duplamente_adiciona_final(&l, 6);

    lista_duplamente_imprime(&l);
}