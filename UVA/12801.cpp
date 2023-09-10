// Grandpa Pepe's Pizza
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4666
#include <bits/stdc++.h>

using namespace std;

bool runv(vector<int> &x, int slice_size, int c, int start)
{
  int cont;
  for (int i = start; i < c; i += slice_size)
  {
    cont = 0;
    int k = i;
    for (int j = 0; j < slice_size; j++)
    {
      if (x[k])
      {
        cont++;
      }
      if (cont > 1)
      {
        break;
      }
      k++;
      if (k == c)
        k = 0;
    }
    if (cont != 1)
    {
      return false;
    }
  }
  return true;
}

bool isit(vector<int> &x, int slice_size, int c)
{
  for (int i = 0; i < slice_size; i++)
  {
    if (runv(x, slice_size, c, i))
      return true;
  }
  return false;
}

int main()
{
  int c, n, aux;
  while (true)
  {
    cin >> c >> n;
    if (cin.eof())
      break;
    vector<int> x(c, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> aux;
      a[i] = aux;
      x[aux] = 1;
    }
    int slice_size = c / n;
    if (isit(x, slice_size, c))
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }

  return 0;
}