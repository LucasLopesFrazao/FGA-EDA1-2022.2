#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *proximo;
};

void inverter_lista_simplesmente(struct node **lista) {
  struct node *anterior = NULL;
  struct node *atual = *lista;
  struct node *proximo;

  while (atual != NULL) {
    proximo = atual->proximo;
    atual->proximo = anterior;
    anterior = atual;
    atual = proximo;
  }

  *lista = anterior;
}

void push(struct node **head_ref, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->data = data;
  new_node->proximo = (*head_ref);

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

  reverseList(&head);

  printf("\nLista invertida: ");
  printList(head);

  return 0;
}