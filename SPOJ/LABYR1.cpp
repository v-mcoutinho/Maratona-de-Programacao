// Labyrinth
// https://www.spoj.com/problems/LABYR1/en/
#include <bits/stdc++.h>

using namespace std;

void searchIthink(vector<string> &L, int x, int y, int cont, int *maximum, int *xend, int *yend)
{
  L[x][y] = '#';
  if (L[x - 1][y] == '.')
    searchIthink(L, x - 1, y, cont + 1, maximum, xend, yend);
  if (L[x + 1][y] == '.')
    searchIthink(L, x + 1, y, cont + 1, maximum, xend, yend);
  if (L[x][y - 1] == '.')
    searchIthink(L, x, y - 1, cont + 1, maximum, xend, yend);
  if (L[x][y + 1] == '.')
    searchIthink(L, x, y + 1, cont + 1, maximum, xend, yend);
  L[x][y] = '.';
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
  int t, c, r;
  cin >> t;
  while (t--)
  {
    cin >> c >> r;
    vector<string> L(r);
    for (int i = 0; i < r; i++)
    {
      cin >> L[i];
    }
    bool broken = false;
    int maximumrope = 0, x = 0, y = 0;
    for (int i = 1; i < r - 1; i++)
    {
      for (int j = 1; j < c - 1; j++)
      {
        if (L[i][j] == '.')
        {
          searchIthink(L, i, j, 0, &maximumrope, &x, &y);
          broken = true;
          break;
        }
      }
      if (broken)
        break;
    }
    maximumrope = 0;
    searchIthink(L, x, y, 0, &maximumrope, &x, &y);
    cout << "Maximum rope length is " << maximumrope << "." << endl;
  }

  return 0;
}