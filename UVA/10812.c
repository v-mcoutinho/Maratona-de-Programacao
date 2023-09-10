// Beat the Spread!
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1753
#include <stdio.h>

int main()
{
  int k, s, d, x;
  scanf("%d", &k);
  while (k--)
  {
    scanf(" %d %d", &s, &d);
    if (d > s)
      printf("impossible\n");
    else
    {
      if ((s + d) % 2 != 0)
        printf("impossible\n");
      else
      {
        x = (s + d) / 2;
        printf("%d %d\n", x, s - x);
      }
    }
  }

  return 0;
}