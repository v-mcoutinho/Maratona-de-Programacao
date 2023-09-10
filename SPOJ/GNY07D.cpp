// Decoding
// https://www.spoj.com/problems/GNY07D/en/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n, row, column;
  string st;
  cin >> n;
  for (int naux = 1; naux <= n; naux++)
  {
    cin >> row >> column;
    int ma[row][column];
    cin >> st;
    int aux = 0;
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < column; j++)
      {
        ma[i][j] = st[aux] - '0';
        aux++;
      }
    }
    aux = 4;
    int aux2 = 0, k = 0, l = 0, m = row, n = column;
    cout << naux << " ";
    while (k < m && l < n)
    {
      for (int i = l; i < n; ++i)
      {
        aux2 += ma[k][i] * pow(2, aux);
        aux--;
        if (aux < 0)
        {
          aux = 4;
          if (!aux2)
            cout << " ";
          else
            cout << (char)(aux2 + 'A' - 1);
          aux2 = 0;
        }
      }
      k++;
      for (int i = k; i < m; ++i)
      {
        aux2 += ma[i][n - 1] * pow(2, aux);
        aux--;
        if (aux < 0)
        {
          aux = 4;
          if (!aux2)
            cout << " ";
          else
            cout << (char)(aux2 + 'A' - 1);
          aux2 = 0;
        }
      }
      n--;
      if (k < m)
      {
        for (int i = n - 1; i >= l; --i)
        {
          aux2 += ma[m - 1][i] * pow(2, aux);
          aux--;
          if (aux < 0)
          {
            aux = 4;
            if (!aux2)
              cout << " ";
            else
              cout << (char)(aux2 + 'A' - 1);
            aux2 = 0;
          }
        }
        m--;
      }
      if (l < n)
      {
        for (int i = m - 1; i >= k; --i)
        {
          aux2 += ma[i][l] * pow(2, aux);
          aux--;
          if (aux < 0)
          {
            aux = 4;
            if (!aux2)
              cout << " ";
            else
              cout << (char)(aux2 + 'A' - 1);
            aux2 = 0;
          }
        }
        l++;
      }
    }
    cout << endl;
  }

  return 0;
}