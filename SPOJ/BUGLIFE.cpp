// A Bug’s Life
// https://www.spoj.com/problems/BUGLIFE/en/
#include <bits/stdc++.h>

using namespace std;

bool bipartite(vector<vector<int>> &graph, vector<int> &color, int s)
{
  int aux, V;
  color[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    aux = q.front();
    q.pop();
    for (int i = 0; i < graph[aux].size(); i++)
    {
      V = graph[aux][i];
      if (!color[V])
      {
        color[V] = color[aux] % 2 + 1;
        q.push(V);
      }
      else if (color[V] == color[aux])
        return false;
    }
  }
  return true;
}

int main()
{
  int n, bugs, interactions, x, y;
  bool flag;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> bugs >> interactions;
    vector<vector<int>> graph(bugs);
    for (int j = 0; j < interactions; j++)
    {
      cin >> x >> y;
      x--;
      y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    vector<int> color(bugs, 0);
    flag = true;
    for (int j = 0; j < bugs; j++)
    {
      if (!color[j])
      {
        flag = bipartite(graph, color, j);
        if (!flag)
          break;
      }
    }
    if (flag)
    {
      cout << "Scenario #" << i << ":" << endl
           << "No suspicious bugs found!" << endl;
    }
    else
    {
      cout << "Scenario #" << i << ":" << endl
           << "Suspicious bugs found!" << endl;
    }
  }

  return 0;
}