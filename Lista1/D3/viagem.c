#include <stdio.h>

int main()
{
    int qtdRest, codRest, notaRest, i, dia = 1;
    int melhorNota = 0, melhorCode = 10000001;
    while(scanf("%d", &qtdRest) == 1){
        for(i = 0; i < qtdRest; i++){
            scanf("%d %d", &codRest, &notaRest);

            if(notaRest > melhorNota){
                melhorNota = notaRest;
                melhorCode = codRest;                
            }else if(notaRest == melhorNota){
                if(codRest < melhorCode){
                    melhorNota = notaRest;
                    melhorCode = codRest;
                }
            }            
        }
        printf("Dia %d\n", dia);
        printf("%d\n", melhorCode);
        printf("\n");
        dia++;
        melhorCode = 100000001;
        melhorNota = 0;
    }

    return 0;
}