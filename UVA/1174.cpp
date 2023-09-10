// IP-TV
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3615
#include <bits/stdc++.h>

using namespace std;

void smoltree(vector<vector<int>> &table, vector<int> &visitado, vector<int> &parent, vector<int> &key, int n)
{
  int u, node;
  for (int i = 1; i < n; i++)
  {
    u = INT_MAX;
    for (int j = 0; j < n; j++)
    {
      if (!visitado[j] && key[j] <= u)
      {
        u = key[j];
        node = j;
      }
    }
    visitado[node] = true;
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
  int intaux;
  int t, m, n, cost;
  string straux, straux2, starting;
  cin >> t;
  for (int abc = 0; abc < t; abc++)
  {
    cin >> m >> n;
    map<string, int> names;
    vector<vector<int>> table(m, vector<int>(m, -1));
    intaux = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> straux >> straux2 >> cost;
      if (names.count(straux) == 0)
      {
        names.insert({straux, intaux});
        intaux++;
      }
      if (names.count(straux2) == 0)
      {
        names.insert({straux2, intaux});
        intaux++;
      }
      table[names[straux]][names[straux2]] = cost;
      table[names[straux2]][names[straux]] = cost;
    }
    vector<int> dist(m, INT_MAX), visitado(m, 0), dist2(m, -1);
    dist[0] = 0;
    dist2[0] = 0;
    smoltree(table, visitado, dist2, dist, m);
    int cont = 0;
    for (int i = 1; i < m; i++)
    {
      cont += table[i][dist2[i]];
    }
    cout << cont << endl;
    if (abc != t - 1)
      cout << endl;
  }

  return 0;
}