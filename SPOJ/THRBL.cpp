// Catapult that ball
// https://www.spoj.com/problems/THRBL/en/
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void buildLogTable(vector<int> &x)
{
  int n = x.size();
  for (int i = 2; i < n; i++)
  {
    x[i] = x[i / 2] + 1;
  }
}

void buildSparseTable(vector<vector<int> > &x, int n)
{
  for (int i = 1; i < x.size(); i++)
  {
    for (int j = 0; j + (1 << i) <= n; j++)
    {
      x[i][j] = max(x[i - 1][j], x[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> logTable(n + 1, 0);
  buildLogTable(logTable);
  vector<vector<int> > sparseTable(logTable.back() + 1, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    cin >> sparseTable[0][i];
  }
  buildSparseTable(sparseTable, n);
  int balls = 0;
  int x, y, aux;
  for (int i = 1; i <= m; i++)
  {
    cin >> x >> y;
    x--;
    y--;
    aux = logTable[y - x];
    int aux2 = max(sparseTable[aux][x], sparseTable[aux][y - (1 << aux)]);
    if (aux2 <= sparseTable[0][x])
    {
      balls++;
    }
  }
  cout << balls << endl;

  return 0;
}
