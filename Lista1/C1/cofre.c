#include <stdio.h>

int main()
{

    int qtdDepositos, test;
    qtdDepositos = 5;
    test = 1;
    while (qtdDepositos != 0)
    {
        scanf("%d", &qtdDepositos);
        if (qtdDepositos != 0)
        {
            printf("Teste %d\n", test);
        }
        int a, b, i, difAnterior, dif;
        difAnterior = 0;
        for (i = 0; i < qtdDepositos; i++)
        {
            scanf("%d %d", &a, &b);
            dif = (a - b) + difAnterior;
            difAnterior = dif;
            printf("%d\n", dif);
        }
        test++;
    }

    return 0;
}