// Answer the boss!
// https://www.spoj.com/problems/RPLA/en/
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
  int rank, pos;
} boss;

typedef struct
{
  bool operator()(boss const &b1, boss const &b2)
  {
    if (b1.rank > b2.rank)
      return true;
    else if (b1.rank == b2.rank)
    {
      return b1.pos > b2.pos;
    }
    else
      return false;
  }
} CompareBoss;

void topOrder(vector<vector<int>> &graph, priority_queue<boss, vector<boss>, CompareBoss> &s, vector<int> &visited, int current, vector<int> &rank)
{
  if (visited[current])
    return;
  visited[current] = 1;
  for (int i = 0; i < graph[current].size(); i++)
  {
    if (!visited[graph[current][i]])
    {
      topOrder(graph, s, visited, graph[current][i], rank);
    }
  }
  int aux = 0;
  for (int i = 0; i < graph[current].size(); i++)
  {
    aux = max(aux, rank[graph[current][i]]);
  }
  rank[current] = aux + 1;
  s.push({rank[current], current});
}

int main()
{
  int t, n, r, r1, r2;
  boss x;
  cin >> t;
  for (int testcase = 1; testcase <= t; testcase++)
  {
    cin >> n >> r;
    vector<vector<int>> graph(n);
    for (int i = 0; i < r; i++)
    {
      cin >> r1 >> r2;
      graph[r1].push_back(r2);
    }
    vector<int> visited(n, 0), rank(n, 0);
    // queue<int> s;
    priority_queue<boss, vector<boss>, CompareBoss> s;
    for (int i = 0; i < n; i++)
    {
      topOrder(graph, s, visited, i, rank);
    }
    cout << "Scenario #" << testcase << ":" << endl;
    while (!s.empty())
    {
      x = s.top();
      s.pop();
      cout << x.rank << " " << x.pos << endl;
    }
  }

  return 0;
}