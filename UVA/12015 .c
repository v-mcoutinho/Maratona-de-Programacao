// Google is Feeling Lucky
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3166
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int n, i, j, k;
  scanf(" %d", &n);
  int v[10];
  char c[10][101];
  for (i = 0; i < n; i++)
  {
    k = 0;
    for (j = 0; j < 10; j++)
    {
      scanf(" %s", c[j]);
      scanf(" %d", &v[j]);
      if (k < v[j])
        k = v[j];
    }
    printf("Case #%d:\n", i + 1);
    for (j = 0; j < 10; j++)
    {
      if (v[j] == k)
        printf("%s\n", c[j]);
    }
  }

  return 0;
}