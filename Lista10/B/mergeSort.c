#include <stdio.h>
#include <stdlib.h>

void merge(int* v, int l, int r1, int r2){
    int* v2 = malloc(sizeof(int) * (r2 - l + 1));
    int i = l;
    int k = 0;
    int j = r1 + 1;

    while ( i <= r1 && j <= r2){
        if (v[i] < v[j]){
            v2[k++] = v[i++];
        }else{
            v2[k++] = v[j++];
        }
    }
    
    while(i <= r1){
        v2[k++] = v[i++];
    }

    while(j <= r2){
        v2[k++] = v[j++];
    }

    k = 0;

    for(int i = l; i <= r2; i++){
        v[i] = v2[k++];
    }

    free(v2);
}

void mergeSort(int *v, int l, int r){
    if(l >= r) return;

    int meio = ( l + r ) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int main(){
    int leitura, lido;
    scanf("%d", &leitura);
    int v[leitura];
    for(int i = 0; i < leitura; i++){
        scanf("%d", &v[i]);
    }

    mergeSort(v, 0, leitura - 1);

    for(int i = 0; i < leitura; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}