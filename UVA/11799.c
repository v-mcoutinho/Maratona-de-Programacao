// Horror Dash
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2899
#include <stdio.h>

int main()
{
  int n, m, i, j, a, b;
  scanf(" %d", &n);
  for (i = 0; i < n; i++)
  {
    a = 0;
    scanf(" %d", &m);
    for (j = 0; j < m; j++)
    {
      scanf(" %d", &b);
      if (b > a)
        a = b;
    }
    printf("Case %d: %d\n", i + 1, a);
  }

  return 0;
}