#include <stdlib.h>  // para rand() e srand()
#include <time.h>    // para time()
#include <stdio.h>

void insertion_sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            int t = a[j];
            a[j] = a[j - 1];
            a[j - 1] = t;
            j--;
        }
    }
}


// Função auxiliar para dividir a lista em duas sublistas, usando um pivot aleatório
int separa(int *v, int l, int r) {
    // escolhe pivot aleatório
    int pivot_index = l + rand() % (r - l + 1);
    int pivot = v[pivot_index];

    // coloca o pivot no final da lista
    int t = v[r];
    v[r] = v[pivot_index];
    v[pivot_index] = t;

    // inicializa os índices
    int i = l - 1;
    int j = r;

    // loop principal
    while (l < j) {
        // procura elemento maior que o pivot
        while (v[++i] < pivot);
        // procura elemento menor que o pivot
        while (v[--j] > pivot);
        if (i >= j) break;  // se os índices se cruzarem, para
        // troca os elementos
        t = v[i];
        v[i] = v[j];
        v[j] = t;
    }

    // coloca o pivot no lugar correto
    t = v[i];
    v[i] = v[r];
    v[r] = t;

    return i;
}

// Função de ordenação rápida iterativa
void quick_sort(int *v, int l, int r) {
    // inicializa o tamanho do corte rápido
    int s = 10;

    // aloca memória para a pilha de índices
    int *stack = (int*) malloc(sizeof(int) * (r - l + 1));
    int top = -1;

    // empilha os índices inicial e final
    stack[++top] = l;
    stack[++top] = r;

    // enquanto a pilha não estiver vazia
    while (top >= 0) {
        // desempilha os índices
        int right = stack[top--];
        int left = stack[top--];

        // se o tamanho da lista for menor ou igual ao tamanho do corte rápido, usa o insertion sort
        if (right - left <= s) {
            insertion_sort(v + left, right - left + 1);
            continue;
        }

        // divide a lista em duas sublistas
        int p = separa(v, left, right);

        // empilha os índices das sublistas
        stack[++top] = left;
        stack[++top] = p - 1;
        stack[++top] = p + 1;
        stack[++top] = right;
    }

    // libera a memória alocada para a pilha
    free(stack);
}

int main() {
    // inicializa o gerador de números aleatórios
    srand(time(NULL));

    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
