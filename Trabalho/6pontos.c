#include <stdio.h>
#define MAX_N 5000
int total, primeiroId;
int id[MAX_N + 1], valor[MAX_N + 1], proximoId[MAX_N + 1];
int main()
{
    scanf("%d", &total);
    for (int i = 0; i < total; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        id[a] = a;
        valor[a] = b;
        proximoId[a] = c;
        if (i == 0)
        {
            primeiroId = a;
        }
    }
    int AtualId = primeiroId;
    while (AtualId != -1)
    {
        printf("%d\n", valor[AtualId]);
        AtualId = proximoId[AtualId];
    }
    return 0;
}
