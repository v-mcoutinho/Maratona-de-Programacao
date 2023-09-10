// Diving for Gold
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=931
#include <bits/stdc++.h>

using namespace std;

void tank(vector<int> &ti, vector<int> &v, int t, int n, vector<int> &x)
{
  int total = 0;
  vector<vector<int>> T(n + 1, vector<int>(t + 1, 0));
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= t; j++)
    {
      if (ti[i - 1] <= j)
      {
        T[i][j] = max(v[i - 1] + T[i - 1][j - ti[i - 1]], T[i - 1][j]);
      }
      else
      {
        T[i][j] = T[i - 1][j];
      }
    }
  }
  cout << T[n][t] << endl;
  int i = n, j = t;
  while (i > 0)
  {
    while (i && T[i][j] == T[i - 1][j])
    {
      i--;
    }
    if (!i)
      break;
    x.push_back(i - 1);
    j -= ti[i - 1];
    i--;
  }
}

int main()
{
  int w, t, n;
  bool fir = true;
  while (true)
  {
    cin >> t >> w >> n;
    if (cin.eof())
      break;
    vector<int> d(n), v(n), ti(n), x;
    for (int i = 0; i < n; i++)
    {
      cin >> d[i] >> v[i];
      ti[i] = 3 * w * d[i];
    }
    if (!fir)
    {
      cout << endl;
    }
    tank(ti, v, t, n, x);
    cout << x.size() << endl;
    for (int i = x.size() - 1; i >= 0; i--)
    {
      cout << d[x[i]] << " " << v[x[i]] << endl;
    }
    fir = false;
  }

  return 0;
}