#include <stdio.h>

int main(){

    unsigned char v1, v2, v3;
    short int total, a;
    short int* soma;

    scanf("%hhd %hhd %hhd", &v1, &v2, &v3);
    scanf("%hd", &total);
    soma = &a;
    *soma += v1;
    *soma += v2;
    *soma += v3;

    if(*soma == total){
        printf("Acertou\n");
    }else{
        printf("Errou\n");

    }
    
    return 0;
}