// Bishops
// https://www.spoj.com/problems/BISHOPS/en/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  string x;
  int auxint;
  while (cin >> x)
  {
    if (x == "1")
    {
      cout << 1 << endl;
    }
    else
    {
      vector<int> ve;
      int va = 0;
      for (int i = 0; i < x.length(); i++)
      {
        if (x[i] != '0' || va == 1)
        {
          ve.push_back(x[i] - '0');
          va = 1;
        }
      }
      auxint = ve.back() * 2 - 2;
      if (auxint < 0)
      {
        auxint = 8;
        va = -1;
      }
      else if (auxint > 9)
      {
        auxint = auxint % 10;
        va = 1;
      }
      else
      {
        va = 0;
      }
      ve[ve.size() - 1] = auxint;
      for (int i = ve.size() - 2; i >= 0; i--)
      {
        auxint = ve[i] * 2 + va;
        if (auxint > 9)
        {
          auxint = auxint % 10;
          va = 1;
        }
        else if (auxint < 0)
        {
          auxint = 9;
          va = -1;
        }
        else
        {
          va = 0;
        }
        ve[i] = auxint;
      }
      if (va == 1)
        cout << va;
      for (int i = 0; i < ve.size(); i++)
        cout << ve[i];
      cout << endl;
    }
  }

  return 0;
}
