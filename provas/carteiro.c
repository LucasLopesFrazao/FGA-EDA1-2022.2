#include <stdio.h>
#include <stdlib.h>

int main()
{
    int casas, pacotes;
    scanf("%d %d", &casas, &pacotes);

    int *casa = (int *)malloc(casas * sizeof(int));
    int *pacote = (int *)malloc(pacotes * sizeof(int));

    for (int i = 0; i < casas; i++) {
        scanf("%d", &casa[i]);
    }
    for (int i = 0; i < pacotes; i++) {
        scanf("%d", &pacote[i]);
    }

    int unidade = 0;
    int z = 0;
    for (int i = 0; i < pacotes; i++) {
        while (pacote[i] != casa[z]) {
            unidade++;
            if (pacote[i] > casa[z]) {
                z++;
            } else {
                z--;
            }
        }
    }
    printf("%d\n", unidade);

    free(casa);
    free(pacote);
    return 0;
}

