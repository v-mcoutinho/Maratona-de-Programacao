// The dominoes solitaire
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1444
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
  int a, b, c;
} domi;

bool veri(vector<domi> &x, pair<int, int> &las, int n, int current)
{
  if (n == 1)
  {
    for (int i = 0; i < x.size(); i++)
    {
      if (!x[i].c)
      {
        if (x[i].a == current)
        {
          if (x[i].b == las.first)
          {
            return true;
          }
        }
        else if (x[i].b == current)
        {
          if (x[i].a == las.first)
          {
            return true;
          }
        }
      }
    }
    return false;
  }
  else
  {
    for (int i = 0; i < x.size(); i++)
    {
      if (!x[i].c)
      {
        if (x[i].a == current)
        {
          x[i].c = 1;
          if (veri(x, las, n - 1, x[i].b))
            return true;
          x[i].c = 0;
        }
        else if (x[i].b == current)
        {
          x[i].c = 1;
          if (veri(x, las, n - 1, x[i].a))
            return true;
          x[i].c = 0;
        }
      }
    }
    return false;
  }
}

int main()
{
  int n, m, aux1, aux2;
  while (cin >> n, n)
  {
    cin >> m;
    pair<int, int> first, last;
    cin >> aux1 >> aux2;
    first = make_pair(aux1, aux2);
    cin >> aux1 >> aux2;
    last = make_pair(aux1, aux2);
    vector<domi> x;
    for (int i = 0; i < m; i++)
    {
      cin >> aux1 >> aux2;
      x.push_back({aux1, aux2, 0});
    }
    if (veri(x, last, n, first.second))
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}