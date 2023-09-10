// Oreon
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3649
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

typedef struct
{
  ll fc, lc, val;
} helpme;

bool comphelpme(helpme a, helpme b)
{
  if (a.val != b.val)
    return a.val < b.val;
  if (a.fc != b.fc)
    return a.fc < b.fc;
  return a.lc < b.lc;
}

void smoltree(vector<vector<long long int> > &table, vector<long long int> &visitado, vector<long long int> &parent, vector<long long int> &key, long long int n)
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
      if (table[node][j] != 0 && !visitado[j] && table[node][j] < key[j])
      {
        parent[j] = node;
        key[j] = table[node][j];
      }
    }
  }
}

int main()
{
  int t, n;
  char whycomma;
  cin >> t;
  for (int tests = 1; tests <= t; tests++)
  {
    cin >> n;
    vector<vector<long long int> > graph(n, vector<long long int>(n));
    for (int i = 0; i < n; i++)
    {
      cin >> graph[i][0];
      for (int j = 1; j < n; j++)
      {
        cin >> whycomma >> graph[i][j];
      }
    }
    vector<long long int> dist(n, LLONG_MAX), visitado(n, 0), dist2(n, -1);
    dist[0] = 0;
    dist2[0] = 0;
    smoltree(graph, visitado, dist2, dist, n);
    cout << "Case " << tests << ":" << endl;
    vector<helpme> vecaux;
    for (ll i = 1; i < n; i++)
    {
      vecaux.push_back({min(i, dist2[i]), max(i, dist2[i]), graph[i][dist2[i]]});
    }
    sort(vecaux.begin(), vecaux.end(), comphelpme);
    for (int i = 0; i < vecaux.size(); i++)
    {
      cout << (char)('A' + vecaux[i].fc) << "-" << (char)('A' + vecaux[i].lc) << " " << vecaux[i].val << endl;
    }
  }

  return 0;
}
