// Ordering Tasks
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1246
#include <bits/stdc++.h>

using namespace std;

void topOrder(vector<vector<int>> &graph, stack<int> &s, vector<int> &visited, int current)
{
  if (visited[current])
    return;
  visited[current] = 1;
  for (int i = 0; i < graph[current].size(); i++)
  {
    if (!visited[graph[current][i]])
    {
      topOrder(graph, s, visited, graph[current][i]);
    }
  }
  s.push(current);
}

int main()
{
  int n, m, x, y;
  while (true)
  {
    cin >> n >> m;
    if (!n && !m)
      break;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
      cin >> x >> y;
      graph[x - 1].push_back(y - 1);
    }
    stack<int> s;
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
      topOrder(graph, s, visited, i);
    }
    while (!s.empty())
    {
      x = s.top() + 1;
      s.pop();
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}