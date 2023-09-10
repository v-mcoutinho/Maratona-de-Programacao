// Teams Forming
// https://codeforces.com/problemset/problem/1092/B
#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
  return (*(int *)b - *(int *)a);
}

int main()
{
  int n, i, j, k, cont = 0;
  scanf(" %d", &n);
  int v[n];
  for (i = 0; i < n; i++)
  {
    scanf(" %d", &v[i]);
  }
  qsort(v, n, sizeof(int), cmpfunc);
  for (i = 0; i < n; i += 2)
  {
    cont += v[i] - v[i + 1];
  }
  printf("%d\n", cont);

  return 0;
}