#include <stdio.h>

void trocarxy(char *a){
    if(a[0] == '\0') return;

    if(a[0] == 'x'){
        a[0] = 'y';
    }

    trocarxy(&a[1]);
}


int main(){

    char string[80];
    scanf("%s", string);
    trocarxy(string);
    printf("%s\n", string);

    return 0;
}