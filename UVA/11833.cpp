// Route Change
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2933
#include <bits/stdc++.h>

using namespace std;

void dij(vector<vector<int>> &w, vector<int> &dist, vector<int> &visited, int start, int n, int c)
{
  int nodedist = INT_MAX, node = c;
  for (int i = 1; i < n; i++)
  {
    nodedist = INT_MAX;
    for (int j = 0; j < n; j++)
    {
      if (!visited[j] && dist[j] <= nodedist)
      {
        nodedist = dist[j];
        node = j;
      }
    }
    visited[node] = 1;
    if (node >= c)
    {
      for (int j = 0; j < n; j++)
      {
        if (!visited[j] && w[node][j] != -1 && dist[node] + w[node][j] < dist[j] && dist[node] != INT_MAX)
        {
          dist[j] = dist[node] + w[node][j];
        }
      }
    }
    else
    {
      if (!visited[node + 1] && w[node][node + 1] != -1 && dist[node] + w[node][node + 1] < dist[node + 1] && dist[node] != INT_MAX)
      {
        dist[node + 1] = dist[node] + w[node][node + 1];
      }
    }
  }
}

int main()
{
  int n, m, c, k, u, v, p;
  while (cin >> n >> m >> c >> k, n, m, c, k)
  {
    vector<vector<int>> w(n, vector<int>(n, -1));
    vector<int> dist(n, INT_MAX), visited(n, 0);
    for (int i = 0; i < m; i++)
    {
      cin >> u >> v >> p;
      w[u][v] = p;
      w[v][u] = p;
    }
    dist[k] = 0;
    dij(w, dist, visited, k, n, c);
    cout << dist[c - 1] << endl;
  }

  return 0;
}