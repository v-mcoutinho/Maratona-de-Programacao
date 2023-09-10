// Negative Score
// https://www.spoj.com/problems/RPLN/en
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

void buildSparseTable(vector<vector<int>> &x, int n)
{
  for (int i = 1; i < x.size(); i++)
  {
    for (int j = 0; j + (1 << i) <= n; j++)
    {
      x[i][j] = min(x[i - 1][j], x[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int main()
{
  int t, n, q;
  cin >> t;
  for (int cas = 1; cas <= t; cas++)
  {
    cin >> n >> q;
    vector<int> logTable(n + 1, 0);
    buildLogTable(logTable);
    vector<vector<int>> sparseTable(logTable.back() + 1, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
      cin >> sparseTable[0][i];
    }
    buildSparseTable(sparseTable, n);
    int x, y, aux;
    queue<int> qu;
    while (q--)
    {
      cin >> x >> y;
      x--;
      aux = logTable[y - x];
      qu.push(min(sparseTable[aux][x], sparseTable[aux][y - (1 << aux)]));
    }
    cout << "Scenario #" << cas << ":" << endl;
    while (!qu.empty())
    {
      cout << qu.front() << endl;
      qu.pop();
    }
  }

  return 0;
}