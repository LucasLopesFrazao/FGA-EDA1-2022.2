#include <stdio.h>

int main (){

    int qtdJogos;
    qtdJogos = 5;
    while(qtdJogos != 0){
        scanf("%d", &qtdJogos);
        int i;
        int num;
        int alice, beto;
        alice = 0;
        beto = 0;
        for(i = 0; i < qtdJogos; i++){
            scanf("%d", &num);
            if(num == 0){
                alice++;
            }else if(num == 1){
                beto ++;
            }
        }
        if(qtdJogos != 0){
        printf("Alice ganhou %d e Beto ganhou %d\n", alice, beto);
        }
    }

    return 0;
}