#include <stdio.h>
#include <stdlib.h>

#define MAXN 10010

int main() {
    int n, m, i, j;
    char l;
    int bota[MAXN], qtd[MAXN];

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < MAXN; i++) {
            bota[i] = 0;
            qtd[i] = 0;
        }

        for (i = 0; i < n; i++) {
            scanf("%d %c", &m, &l);
            if (l == 'D') {
                bota[m]++;
            } else if (l == 'E') {
                qtd[m]++;
            }
        }

        int pares = 0;
        for (i = 0; i < MAXN; i++) {
            if (bota[i] > 0 && qtd[i] > 0) {
                pares += bota[i] < qtd[i] ? bota[i] : qtd[i];
            }
        }

        printf("%d\n", pares);
    }

    return 0;
}
