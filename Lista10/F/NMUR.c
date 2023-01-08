#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define Item int

#define key(x) (x)

#define less(a, b) (a < b)

#define swap(a, b) \
  {                \
    Item t = a;    \
    a = b;         \
    b = t;         \
  }

int compare(const void *a, const void *b)
{
  Item x = *(Item *)a;
  Item y = *(Item *)b;
  if (x < y)
    return -1;
  else if (x > y)
    return 1;
  return 0;
}

void merge(Item *a, int sizea, Item *b, int sizeb)
{
  Item *temp = (Item *)malloc((sizea + sizeb) * sizeof(Item));
  int i = 0, j = 0, k = 0;
  for (; i < sizea && j < sizeb; k++)
  {
    if (key(a[i]) <= key(b[j]))
      temp[k] = a[i++];
    else
      temp[k] = b[j++];
  }

  while (i < sizea)
    temp[k++] = a[i++];
  while (j < sizeb)
    temp[k++] = b[j++];

  for (k = 0, i = 0; i < (sizea + sizeb); i++, k++)
    a[i] = temp[k];

  free(temp);
}

int remove_duplicados(Item *v, int n)
{
  int size = 1;
  for (int i = 1; i < n; i++)
    if (v[i] != v[size - 1])
      v[size++] = v[i];
  return size;
}

int main()
{
  int n;
  scanf(" %d", &n);
  int *v = (int *)malloc(sizeof(int) * (2 * n));
  for (int i = 0; i < n; i++)
    scanf(" %d", v + i);

  qsort(v, n, sizeof(Item), compare);

  int size = remove_duplicados(v, n);
  if (size % 2)
    v[size++] = 1000000000;

  int tamanho_numero_maluco = 0;
  for (int i = 0; i < size - 1; i += 2)
  {
    unsigned long long sum = (unsigned long long)v[i] + (unsigned long long)v[i + 1];
    v[size + tamanho_numero_maluco++] = (int)sum;
  }

  merge(v, size, v + size, tamanho_numero_maluco);
  size = remove_duplicados(v, size + tamanho_numero_maluco);
  for (int i = 0; i < size; i += 4)
    printf("%d\n", v[i]);
  printf("Elementos: %d\n", size);

  return 0;
}
