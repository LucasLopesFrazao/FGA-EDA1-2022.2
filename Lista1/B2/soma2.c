#include <stdio.h>

int main(){

    int loop, i, num, sum;
    sum = 0;
    i = 0;

    scanf("%d", &loop);
    while(i < loop){
        scanf("%d", &num);
        sum += num;
        i++;
    }
    printf("%d\n", sum);

    return 0;
}