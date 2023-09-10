// Connect the Campus
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1338
#include <bits/stdc++.h>

using namespace std;

double distance(int x1, int y1, int x2, int y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void smoltree(vector<vector<double>> &table, vector<int> &visitado, vector<int> &parent, vector<double> &key, int n)
{
  int node;
  double u;
  for (int i = 1; i < n; i++)
  {
    u = DBL_MAX;
    for (int j = 0; j < n; j++)
    {
      if (!visitado[j] && key[j] <= u)
      {
        u = key[j];
        node = j;
      }
    }
    visitado[node] = 1;
    for (int j = 0; j < n; j++)
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
  int n;
  while (cin >> n)
  {
    int m, auxx, auxy;
    double sum = 0;
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
    {
      cin >> b[i].first >> b[i].second;
    }
    cin >> m;
    vector<vector<double>> table(n, vector<double>(n, -1));
    for (int i = 0; i < m; i++)
    {
      cin >> auxx >> auxy;
      table[auxx - 1][auxy - 1] = 0;
      table[auxy - 1][auxx - 1] = 0;
    }
    vector<int> visitado(n, 0), parent(n, -1);
    vector<double> key(n, DBL_MAX);
    key[0] = 0;
    parent[0] = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        if (table[i][j] == -1)
        {
          table[i][j] = distance(b[i].first, b[i].second, b[j].first, b[j].second);
          table[j][i] = table[i][j];
        }
      }
    }
    smoltree(table, visitado, parent, key, n);
    for (int i = 1; i < n; i++)
    {
      sum += table[i][parent[i]];
    }
    printf("%.2lf\n", sum);
  }

  return 0;
}