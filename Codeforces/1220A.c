// Cards
// https://codeforces.com/problemset/problem/1220/A
#include <stdio.h>
#include <string.h>

int main()
{
  int k, s, d, x;
  scanf("%d", &k);
  char c[k + 1];
  scanf(" %s", c);
  int i, cont = 0, cont2 = 0;
  for (i = 0; i < strlen(c); i++)
  {
    if (c[i] == 'n')
      cont++;
    else if (c[i] == 'z')
      cont2++;
  }
  for (i = 0; i < cont; i++)
  {
    if (i > 0)
      printf(" ");
    printf("1");
  }
  if (cont > 0)
    printf(" ");
  for (i = 0; i < cont2; i++)
  {
    if (i > 0)
      printf(" ");
    printf("0");
  }
  printf("\n");

  return 0;
}