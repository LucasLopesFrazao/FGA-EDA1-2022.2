#include <stdio.h>;
#include <string.h>;


int main(){

    char nome[30];
    int marte = 0;
    while(scanf("%s", &nome) == 1){
        if(strcmp(nome, "marte") == 0){
            printf("Leonardo Cicero Marciano\n");
            marte = 1;
        }
    }

    if(marte == 0){
        printf("none\n");
    }

    return 0;
}