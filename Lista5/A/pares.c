#include <stdio.h>

int totalPares = 0;

void pares(char *a){

    if(a[0] == '\0') return;
    if(a[0] == a[2]){
        totalPares++;
    }
    pares(&a[1]);

}

int main(){

    char frase[200];
    scanf("%s", frase);
    pares(frase);
    printf("%d\n", totalPares);
    return 0;
}   