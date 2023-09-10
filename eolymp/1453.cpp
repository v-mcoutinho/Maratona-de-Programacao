// Ford-Bellman
// https://www.eolymp.com/en/problems/1453
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
  int x, y, weight;
} paths;

void BellmanFord(vector<paths> &graph, int source, int size)
{
  vector<int> dist(size, 30000);
  dist[source] = 0;
  for (int i = 1; i < size; i++)
  {
    for (int j = 0; j < graph.size(); j++)
    {
      if (dist[graph[j].x] != 30000 && dist[graph[j].y] > dist[graph[j].x] + graph[j].weight)
      {
        dist[graph[j].y] = dist[graph[j].x] + graph[j].weight;
      }
    }
  }
  for (int i = 0; i < size; i++)
  {
    cout << dist[i];
    if (i != size - 1)
      cout << " ";
    else
      cout << endl;
  }
}

int main()
{
  int n, m, x, y, w;
  cin >> n >> m;
  vector<paths> graph;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y >> w;
    graph.push_back({x - 1, y - 1, w});
  }
  BellmanFord(graph, 0, n);

  return 0;
}