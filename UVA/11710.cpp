// Expensive subway
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2757
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
  int s, c, intaux;
  string straux, straux2, starting;
  while (true)
  {
    cin >> s >> c;
    if (!s && !c)
      break;
    map<string, int> names;
    for (int i = 0; i < s; i++)
    {
      cin >> straux;
      names.insert({straux, i});
    }
    vector<vector<int>> table(s, vector<int>(s, -1));
    vector<int> dist(s, INT_MAX), visitado(s, 0), dist2(s, -1);
    for (int i = 0; i < c; i++)
    {
      cin >> straux >> straux2 >> intaux;
      if (table[names[straux]][names[straux2]] == -1)
      {
        table[names[straux]][names[straux2]] = intaux;
        table[names[straux2]][names[straux]] = intaux;
      }
      else if (table[names[straux]][names[straux2]] > intaux)
      {
        table[names[straux]][names[straux2]] = intaux;
        table[names[straux2]][names[straux]] = intaux;
      }
    }
    cin >> starting;
    dist[names[starting]] = 0;
    dist2[names[starting]] = 0;
    smoltree(table, visitado, dist2, dist, s);
    int cont = 0;
    bool possible = true;
    for (int i = 0; i < s; i++)
    {
      if (i != names[starting])
      {
        if (dist2[i] == -1)
        {
          cout << "Impossible" << endl;
          possible = false;
          break;
        }
        cont += table[i][dist2[i]];
      }
    }
    if (possible)
      cout << cont << endl;
  }

  return 0;
}