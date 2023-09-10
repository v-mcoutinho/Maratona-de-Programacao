// Sabotage
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1421
#include <bits/stdc++.h>

using namespace std;

void printpath(vector<vector<int>> &graph, vector<int> &visited)
{
  for (int i = 0; i < graph.size(); i++)
  {
    for (int j = 0; j < graph.size(); j++)
    {
      if (!visited[j] && visited[i] && graph[i][j])
      {
        cout << i + 1 << " " << j + 1 << endl;
      }
    }
  }
}

void dfs(vector<vector<int>> &graph, int s, vector<int> &visited)
{
  visited[s] = 1;
  for (int i = 0; i < graph.size(); i++)
  {
    if (graph[s][i] && !visited[i])
    {
      dfs(graph, i, visited);
    }
  }
}

bool bfs(vector<vector<int>> &graph, int s, int t, vector<int> &parent)
{
  vector<int> visited(graph.size(), 0);
  queue<int> que;
  que.push(s);
  visited[s] = 1;
  parent[s] = -1;
  while (!que.empty())
  {
    for (int i = 0; i < graph.size(); i++)
    {
      if (!visited[i] && graph[que.front()][i] > 0)
      {
        que.push(i);
        parent[i] = que.front();
        visited[i] = 1;
      }
    }
    que.pop();
  }
  return visited[t];
}

void minimumCut(vector<vector<int>> &graph, int s, int t)
{
  vector<vector<int>> residualgraph(graph.size(), vector<int>(graph.size()));
  for (int i = 0; i < graph.size(); i++)
  {
    for (int j = 0; j < graph.size(); j++)
    {
      residualgraph[i][j] = graph[i][j];
    }
  }
  vector<int> parent(graph.size());
  while (bfs(residualgraph, s, t, parent))
  {
    int pathFlow = INT_MAX;
    for (int i = t; i != s; i = parent[i])
    {
      pathFlow = min(pathFlow, residualgraph[parent[i]][i]);
    }
    for (int i = t; i != s; i = parent[i])
    {
      residualgraph[parent[i]][i] -= pathFlow;
      residualgraph[i][parent[i]] += pathFlow;
    }
  }
  vector<int> visited(graph.size(), 0);
  dfs(residualgraph, s, visited);
  printpath(graph, visited);
}

int main()
{
  int n, m, x, y, z;
  cin >> n >> m;
  while (n != 0 || m != 0)
  {
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
      cin >> x >> y >> z;
      graph[x - 1][y - 1] = z;
      graph[y - 1][x - 1] = z;
    }
    minimumCut(graph, 0, 1);
    cin >> n >> m;
    if (n != 0 || m != 0)
    {
      cout << endl;
    }
  }

  return 0;
}