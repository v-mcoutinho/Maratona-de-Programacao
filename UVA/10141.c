// Request for Proposal
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1082
#include <stdio.h>

int main()
{
  int a, b;
  int aux = 1;
  while (1)
  {
    int i, j, k;
    scanf(" %d %d", &a, &b);
    if (a == 0 && b == 0)
      break;

    char c[81];
    for (i = 0; i < a; i++)
    {
      scanf(" %[^\n]s", c);
    }
    char nome[b][81];
    double p[b];
    int r[b];
    int m = 0;
    for (i = 0; i < b; i++)
    {
      scanf(" %[^\n]s", nome[i]);
      scanf(" %lf", &p[i]);
      scanf(" %d", &r[i]);
      if (r[i] > m)
        m = r[i];
      for (j = 0; j < r[i]; j++)
      {
        scanf(" %[^\n]s", c);
      }
    }
    double pp = 0;
    int cont = 0;
    for (i = 0; i < b; i++)
    {
      if (r[i] == m)
      {
        if (cont == 0)
        {
          pp = p[i];
          cont++;
        }
        else
        {
          if (p[i] < pp)
            pp = p[i];
        }
      }
    }

    for (i = 0; i < b; i++)
    {
      if (r[i] == m && p[i] == pp)
      {
        if (aux > 1)
          printf("\n");
        printf("RFP #%d\n%s\n", aux, nome[i]);
        break;
      }
    }
    aux++;
  }

  return 0;
}