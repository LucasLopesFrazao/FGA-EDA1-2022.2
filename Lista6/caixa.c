#include <stdio.h>

int main()
{
    int bola, altura, largura, profundida;
    scanf("%d", &bola);
    scanf("%d %d %d", &altura, &largura, &profundida);

    if (altura >= bola && largura >= bola && profundida >= bola)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}