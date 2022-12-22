#include <stdio.h>

void re(char *a){

    if(a[0] == '\0') return;
    re(&a[1]);
    printf("%c", a[0]);

}

int main(){

    char frase[500];
    scanf("%s", frase);
    re(frase);
    // printf("%s\n", frase);

    return 0;
}