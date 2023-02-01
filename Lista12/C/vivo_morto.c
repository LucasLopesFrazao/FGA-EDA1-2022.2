#include <stdio.h>

int main(void)
{
    int P, R, n, j, a, vencedor, teste = 0;
    while (scanf("%d %d", &P, &R) == 2 && P != 0 && R != 0)
    {
        int jogadores[P];
        for (int i = 0; i < P; i++)
        {
            scanf("%d", &jogadores[i]);
        }
        for (int i = 0; i < R; i++)
        {
            scanf("%d %d", &n, &j);
            int temp[n];
            int contador = 0;
            for (int k = 0; k < n; k++)
            {
                scanf("%d", &a);
                if (a == j)
                {
                    temp[contador++] = jogadores[k];
                }
            }
            P = contador;
            for (int k = 0; k < contador; k++)
            {
                jogadores[k] = temp[k];
            }
        }
        teste++;
        vencedor = jogadores[0];
        printf("Teste %d\n%d\n\n", teste, vencedor);
    }
    return 0;
}