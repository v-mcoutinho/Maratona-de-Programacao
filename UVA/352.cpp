// The Seasonal War
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=288
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void searchIthink(vector<string> &L, int x, int y, int cont, int *maximum, int *xend, int *yend, int n)
{
  L[x][y] = '0';
  if (x != 0)
    if (L[x - 1][y] == '1')
      searchIthink(L, x - 1, y, cont + 1, maximum, xend, yend, n);
  if (x != n - 1)
    if (L[x + 1][y] == '1')
      searchIthink(L, x + 1, y, cont + 1, maximum, xend, yend, n);
  if (y != 0)
    if (L[x][y - 1] == '1')
      searchIthink(L, x, y - 1, cont + 1, maximum, xend, yend, n);
  if (y != n - 1)
    if (L[x][y + 1] == '1')
      searchIthink(L, x, y + 1, cont + 1, maximum, xend, yend, n);
  if (x != 0 && y != 0)
    if (L[x - 1][y - 1] == '1')
      searchIthink(L, x - 1, y - 1, cont + 1, maximum, xend, yend, n);
  if (x != 0 && y != n - 1)
    if (L[x - 1][y + 1] == '1')
      searchIthink(L, x - 1, y + 1, cont + 1, maximum, xend, yend, n);
  if (x != n - 1 && y != 0)
    if (L[x + 1][y - 1] == '1')
      searchIthink(L, x + 1, y - 1, cont + 1, maximum, xend, yend, n);
  if (x != n - 1 && y != n - 1)
    if (L[x + 1][y + 1] == '1')
      searchIthink(L, x + 1, y + 1, cont + 1, maximum, xend, yend, n);
  if (*maximum == 0)
  {
    *maximum = cont;
    *xend = x;
    *yend = y;
  }
  else if (*maximum < cont)
  {
    *maximum = cont;
    *xend = x;
    *yend = y;
  }
}

int main()
{
  int n;
  for (int aux = 1;; aux++)
  {
    cin >> n;
    int count = 0;
    if (cin.eof())
      break;
    vector<string> M(n);
    for (int i = 0; i < n; i++)
    {
      cin >> M[i];
    }
    int x = 0, y = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (M[i][j] == '1')
        {
          count++;
          searchIthink(M, i, j, 0, &max, &x, &y, n);
        }
      }
    }
    cout << "Image number " << aux << " contains " << count << " war eagles." << endl;
  }

  return 0;
}
