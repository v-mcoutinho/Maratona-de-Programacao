// Transportation system.
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2169
#include <bits/stdc++.h>

using namespace std;

double distance(int x1, int y1, int x2, int y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void smoltree(vector<vector<double>> &table, vector<int> &visitado, vector<pair<int, bool>> &parent, vector<double> &key, int n, int r)
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
        parent[j].first = node;
        key[j] = table[node][j];
        if (key[j] < r)
          parent[j].second = false;
        else
          parent[j].second = true;
      }
    }
  }
}

int main()
{
  int t;
  cin >> t;
  for (int T = 1; T <= t; T++)
  {
    int n, r, states = 1;
    double sumE = 0, sumF = 0;
    cin >> n >> r;
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++)
    {
      cin >> c[i].first >> c[i].second;
    }
    vector<vector<double>> table(n, vector<double>(n, -1));
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        if (table[i][j] == -1)
        {
          table[i][j] = distance(c[i].first, c[i].second, c[j].first, c[j].second);
          table[j][i] = table[i][j];
        }
      }
    }
    vector<int> visitado(n, 0);
    vector<double> key(n, DBL_MAX);
    vector<pair<int, bool>> parent(n, {-1, false});
    key[0] = 0;
    parent[0].first = 0;
    smoltree(table, visitado, parent, key, n, r);
    for (int i = 1; i < n; i++)
    {
      if (parent[i].second == true)
      {
        states++;
        sumF += table[i][parent[i].first];
      }
      else
      {
        sumE += table[i][parent[i].first];
      }
    }
    cout << "Case #" << T << ": " << states << " " << setprecision(0) << fixed << sumE << " " << setprecision(0) << fixed << sumF << endl;
  }

  return 0;
}