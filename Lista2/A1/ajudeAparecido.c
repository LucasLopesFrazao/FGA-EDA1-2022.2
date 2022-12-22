#include <stdio.h>

int main()
{

    int total, loops, i, num, sum = 0;

    scanf("%d", &loops);
    for (i = 0; i < loops; i++)
    {
        scanf("%d", &num);
        sum += num;
    }

    scanf("%d", &total);

    if (sum == total)
    {
        printf("Acertou\n");
    }
    else
    {
        printf("Errou\n");
    }

    return 0;
}