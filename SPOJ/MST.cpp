// Minimum Spanning Tree
// https://www.spoj.com/problems/MST/en/
#include <bits/stdc++.h>

using namespace std;

void smoltree(vector<vector<long long int>> &table, vector<long long int> &visitado, vector<long long int> &parent, vector<long long int> &key, long long int n)
{
  long long int u, node;
  for (long long int i = 1; i < n; i++)
  {
    u = LLONG_MAX;
    for (long long int j = 0; j < n; j++)
    {
      if (!visitado[j] && key[j] <= u)
      {
        u = key[j];
        node = j;
      }
    }
    visitado[node] = 1;
    for (long long int j = 0; j < n; j++)
    {
      if (table[node][j] != -1 && !visitado[j] && table[node][j] < key[j])
      {
        parent[j] = node;
        key[j] = table[node][j];
      }
    }
  }
}

int main()
{
  long long int intaux, intaux2, m, n, cost;
  cin >> n >> m;
  vector<vector<long long int>> table(n, vector<long long int>(n, -1));
  for (long long int i = 0; i < m; i++)
  {
    cin >> intaux >> intaux2 >> cost;
    table[intaux - 1][intaux2 - 1] = cost;
    table[intaux2 - 1][intaux - 1] = cost;
  }
  vector<long long int> dist(n, LLONG_MAX), visitado(n, 0), dist2(n, -1);
  dist[0] = 0;
  dist2[0] = 0;
  smoltree(table, visitado, dist2, dist, n);
  long long int cont = 0;
  for (long long int i = 1; i < n; i++)
  {
    cont += table[i][dist2[i]];
  }
  cout << cont << endl;

  return 0;
}