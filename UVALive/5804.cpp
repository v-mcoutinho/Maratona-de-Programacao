// Route Redundancy
// https://vjudge.net/problem/UVALive-5804
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
  int flow, cap;
} node;

void maximumThreshold(vector<vector<node>> &graph, int s, int t, int *miniF, int mini, vector<int> &visited)
{
  if (s == t)
  {
    *miniF = max(mini, (*miniF));
    return;
  }
  for (int i = 0; i < graph.size(); i++)
  {
    if (graph[s][i].cap && !visited[i])
    {
      visited[s] = 1;
      maximumThreshold(graph, i, t, miniF, min(mini, graph[s][i].cap), visited);
      visited[s] = 0;
    }
  }
}

bool bfs(vector<vector<node>> &graph, int s, int t, vector<int> &level)
{
  for (int i = 0; i < level.size(); i++)
    level[i] = -1;
  level[s] = 0;
  list<int> lis;
  lis.push_back(s);
  while (!lis.empty())
  {
    for (int i = 0; i < graph.size(); i++)
    {
      if (level[i] == -1 && graph[lis.front()][i].flow < graph[lis.front()][i].cap)
      {
        level[i] = level[lis.front()] + 1;
        lis.push_back(i);
      }
    }
    lis.pop_front();
  }
  if (level[t] == -1)
    return false;
  return true;
}

int findFlow(vector<vector<node>> &graph, int current, int t, int flow, vector<int> &level, vector<int> start)
{
  if (current == t)
    return flow;
  for (; start[current] < graph.size(); start[current]++)
  {
    int i = start[current];
    if (level[i] == level[current] + 1 && graph[current][i].flow < graph[current][i].cap)
    {
      int tempFlow = findFlow(graph, i, t, min(flow, graph[current][i].cap - graph[current][i].flow), level, start);
      if (tempFlow > 0)
      {
        graph[current][i].flow += tempFlow;
        graph[i][current].flow -= tempFlow;
        return tempFlow;
      }
    }
  }
  return 0;
}

double maxFlow(vector<vector<node>> &graph, int s, int t, vector<int> &level)
{
  int tot = 0;
  while (bfs(graph, s, t, level))
  {
    vector<int> start(graph.size(), 0);
    int flow = findFlow(graph, s, t, INT_MAX, level, start);
    while (flow)
    {
      tot += flow;
      flow = findFlow(graph, s, t, INT_MAX, level, start);
    }
  }
  int miniF = 0;
  vector<int> visited(graph.size(), 0);
  maximumThreshold(graph, s, t, &miniF, INT_MAX, visited);
  return (double)tot / miniF;
}

int main()
{
  int p, d, n, e, a, b, u, v, w;
  cin >> p;
  while (p--)
  {
    cin >> d >> n >> e >> a >> b;
    vector<vector<node>> graph(n, vector<node>(n, {0, 0}));
    for (int i = 0; i < e; i++)
    {
      cin >> u >> v >> w;
      graph[u][v].cap = w;
    }
    vector<int> level(n);
    cout << d << " " << fixed << setprecision(3) << maxFlow(graph, a, b, level) << endl;
  }

  return 0;
}