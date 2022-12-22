#include <stdio.h>

int sum = 0;
int maximo = 0;

void ultrapassa(int *vetor){
    if(vetor[0] == 0){
        return;
    }

    if((vetor[0] + sum) > maximo){
        sum = 0;
        ultrapassa(vetor + 1);
        printf("%d\n", *vetor);
    }else{
        sum += *vetor;
        ultrapassa(vetor + 1);
    }
} // *vetor == vetor[0] == *(vetor + 0)


int main()
{
    int vetor[501] = {[0 ... 500]=0};
    int num, i = 0;
    scanf("%d", &num);
    while (num != 0)
    {
        vetor[i] = num;
        scanf("%d", &num);
        i++;
    }

    scanf("%d", &maximo);

    ultrapassa(vetor);
    return 0;
}