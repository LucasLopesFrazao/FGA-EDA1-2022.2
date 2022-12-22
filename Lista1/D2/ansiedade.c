#include <stdio.h>
#include <string.h>

int main()
{

    char escolha[3];
    int yes = 0;
    int triagem = 0, total = 0, contabilizado = 0;
    

    while (scanf("%s", escolha) == 1)
    {
        if(strcmp(escolha, "sim") == 0){
            yes++;
        }

        if(yes >= 2 && contabilizado == 0){
            triagem++;
            contabilizado = 1;
        }

        total++;
        if(total == 10){
            // printf("O total de sim é: %d\n", yes);
            // printf("O total é: %d\n", total);
            // printf("Resetado!");
            yes = 0;
            total = 0;
            contabilizado = 0;
        }
    }

    // printf("O total de triagens foi: %d\n", triagem);
    printf("%d\n", triagem);

    return 0;
}