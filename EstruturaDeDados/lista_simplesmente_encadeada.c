#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void lista_inicializa(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

void lista_insere_inicio(Lista *lista, int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tam++;
}

void lista_insere_final(Lista *lista, int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    No *aux = lista->inicio;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novo;
    lista->tam++;
}

void lista_imprime(Lista *lista){
    No *inicio = lista->inicio;
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

int lista_remove_final(Lista *lista){
    No *aux = lista->inicio;
    No *anterior = NULL;
    while(aux->proximo != NULL){
        anterior = aux;
        aux = aux->proximo;
    }
    anterior->proximo = NULL;
    int valor = aux->valor;
    free(aux);
    lista->tam--;
    return valor;
}

int lista_remove_inicio(Lista *lista){
    No *aux = lista->inicio;
    lista->inicio = aux->proximo;
    int valor = aux->valor;
    free(aux);
    lista->tam--;
    return valor;
}

int lista_vazia(Lista *lista){
    return lista->inicio == NULL;
}

void lista_destroi(Lista *lista){
    No *aux = lista->inicio;
    while(aux != NULL){
        No *proximo = aux->proximo;
        free(aux);
        aux = proximo;
    }
    lista->inicio = NULL;
    lista->tam = 0;
}

void lista_inverte(Lista *lista){
    No *aux = lista->inicio;
    No *anterior = NULL;
    No *proximo = NULL;
    while(aux != NULL){
        proximo = aux->proximo;
        aux->proximo = anterior;
        anterior = aux;
        aux = proximo;
    }
    lista->inicio = anterior;
}

void lista_remove_elemento(Lista *lista, int valor){
    No *aux = lista->inicio;
    No *anterior = NULL;
    while(aux != NULL){
        if(aux->valor == valor){
            if(anterior == NULL){
                lista->inicio = aux->proximo;
            } else {
                anterior->proximo = aux->proximo;
            }
            free(aux);
            lista->tam--;
            return;
        }
        anterior = aux;
        aux = aux->proximo;
    }
}

void lista_adiciona_posicao(Lista *lista, int valor, int posicao){
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    No *aux = lista->inicio;
    No *anterior = NULL;
    int i = 0;
    while(aux != NULL){
        if(i == posicao){
            if(anterior == NULL){
                lista->inicio = novo;
            } else {
                anterior->proximo = novo;
            }
            novo->proximo = aux;
            lista->tam++;
            return;
        }
        anterior = aux;
        aux = aux->proximo;
        i++;
    }
}

int lista_busca(Lista *lista, int valor){
    No *aux = lista->inicio;
    int i = 0;
    while(aux != NULL){
        if(aux->valor == valor){
            return i;
        }
        aux = aux->proximo;
        i++;
    }
    return -1;
}

int lista_tamanho(Lista *lista){
    return lista->tam;
}

int main(){
    Lista lista;
    lista_inicializa(&lista);
    lista_insere_inicio(&lista, 1);
    lista_insere_inicio(&lista, 2);
    lista_insere_inicio(&lista, 3);
    lista_insere_inicio(&lista, 4);

    lista_insere_final(&lista, 8);
    lista_insere_final(&lista, 9);
    lista_insere_final(&lista, 10);

    lista_remove_elemento(&lista, 1);
    lista_adiciona_posicao(&lista, 1, 3);
    lista_imprime(&lista);
}