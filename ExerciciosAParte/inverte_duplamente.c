#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *proximo;
  struct node *anterior;
};

void inverter_lista_duplamente(struct node **lista) {
  struct node *aux = NULL;
  struct node *atual = *lista;

  while (atual != NULL) {
    aux = atual->anterior;
    atual->anterior = atual->proximo;
    atual->proximo = aux;
    atual = atual->anterior;
  }

  if (aux != NULL) {
    *lista = aux->anterior;
  }
}

void push(struct node **head_ref, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->data = data;
  new_node->anterior = NULL;
  new_node->proximo = (*head_ref);

  if ((*head_ref) != NULL) {
    (*head_ref)->anterior = new_node;
  }

  (*head_ref) = new_node;
}

void printList(struct node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->proximo;
  }
}

int main() {
  struct node *head = NULL;

  push(&head, 90);
  push(&head, 50);
  push(&head, 25);
  push(&head, 10);

  printf("Lista original: ");
  printList(head);

  inverter_lista_duplamente(&head);

  printf("\nLista invertida: ");
  printList(head);

  return 0;
}