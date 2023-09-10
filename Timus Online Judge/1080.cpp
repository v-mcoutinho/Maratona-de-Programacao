// Map Coloring
// https://acm.timus.ru/problem.aspx?space=1&num=1080
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
  int n, x;
  bool flag;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 0; i < n; i++)
  {
    do
    {
      cin >> x;
      if (!x)
        break;
      graph[i].push_back(x - 1);
      graph[x - 1].push_back(i);
    } while (x != 0);
  }
  vector<int> color(n, 0);
  flag = true;
  for (int j = 0; j < n; j++)
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
    for (int j = 0; j < n; j++)
    {
      cout << color[j] - 1;
    }
    cout << endl;
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}