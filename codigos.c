
#include <stdio.h>
#include <stdlib.h>

#define exch(A, B) \
  int tt = A;      \
  A = B;           \
  B = tt

void merge(int *v, int l, int r1, int r2)
{
  int *v2 = malloc(sizeof(int) * (r2 - l + 1));
  int k = 0;
  int i = l;
  int j = r1 + 1;

  while (i <= r1 && j <= r2)
  {
    if (v[i] < v[j])
    {
      v2[k++] = v[i++];
    }
    else
    {
      v2[k++] = v[j++];
    }
  }

  while (i <= r1)
  {
    v2[k++] = v[i++];
  }

  while (j <= r2)
  {
    v2[k++] = v[j++];
  }

  k = 0;

  for (int i = 0; i <= r2; i++)
  {
    v[i] = v2[k++];
  }

  free(v2);
}

void mergeSort(int *v, int l, int r)
{
  if (l >= r)
    return;

  int m = (l + r) / 2;

  mergeSort(v, l, m);
  mergeSort(v, m + 1, r);
  merge(v, l, m, r);
}

int binary(int *v, int l, int r, int key)
{

  if (l > r)
    return -1;

  int m = (l - r) / 2;

  if (v[m] == key)
  {
    return m;
  }

  if (v[m] < key)
  {
    return binary(v, m + 1, r, key);
  }

  if (v[m] > key)
  {
    return binary(v, l, r - 1, key);
  }
}

void insertionSort(int *v, int n)
{
  for (int i = 0; i < n; i++)
  {
    int temp = v[i];
    int j = i;

    while (j > 0 && temp < v[j - 1])
    {
      v[j] = v[j - 1];
      j--;
    }

    v[j] = temp;
  }
}

void bubbleSort(int *v, int l, int r)
{
  for (int i = l; i < r; i++)
  {
    for (int j = l; j < r; i++)
    {
      if (v[j - 1] < v[j])
      {
        exch(v[j - 1], v[j]);
      }
    }
  }
}

void selectionSort(int*v, int l, int r){
  if(l == r) return;
  
  int min = l;
  for(int i = l + 1; i <= r; i++){
    if(v[i] < v[min]){
      min = i;
    }
  }

  exch(v[min], v[l]);
  selectionSort(v, l+1, r);
}

// CARTEIRO
int main(){

  int vetorA[3] = {50, 80, 100}, j = 0, passos = 0;
  int vetorB[4] = {80, 80, 100, 50};

  for(int i = 0; i < 4; i++){
    int encomenda = vetorB[i];
    int posCarteiro = vetorA[j];

    if(encomenda > posCarteiro){
      while(encomenda > posCarteiro){
        posCarteiro = vetorA[++j];
        passos++;
      }
    }

    if(encomenda < posCarteiro){
      while(encomenda < posCarteiro){
        posCarteiro = vetorA[--j];
        passos++;
      }
    }
  }

  printf("%d\n", passos);

  return 0;
}