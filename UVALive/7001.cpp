// Bus Problem
// https://vjudge.net/problem/UVALive-7001
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void prim(vector<vector<int> > &roads, vector<int> &key, vector<int> &parent, vector<int> &visited, int start, int n)
{
  int minnode, node;
  for (int i = 1; i < n; i++)
  {
    minnode = INT_MAX;
    for (int j = 0; j < n; j++)
    {
      if (!visited[j] && key[j] < minnode)
      {
        minnode = key[j];
        node = j;
      }
    }
    visited[node] = 1;
    for (int j = 0; j < n; j++)
    {
      if (roads[node][j] != -1 && !visited[j] && roads[node][j] < key[j])
      {
        parent[j] = node;
        key[j] = roads[node][j];
      }
    }
  }
}

int primcost(vector<vector<int> > &roads, vector<int> &parent, int n)
{
  int cost = 0;
  for (int i = 1; i < n; i++)
  {
    cost += roads[i][parent[i]];
  }
  return cost;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int c, r, c1, c2, d, cost = 0;
    cin >> c >> r;
    vector<vector<int> > roads(c, vector<int>(c, -1));
    vector<int> key(c, INT_MAX), visited(c, 0), parent(c, -1);
    for (int i = 0; i < r; i++)
    {
      cin >> c1 >> c2 >> d;
      roads[c1][c2] = d;
      roads[c2][c1] = d;
      cost += d;
    }
    key[0] = 0;
    prim(roads, key, parent, visited, 0, c);
    cout << cost - primcost(roads, parent, c) << endl;
  }

  return 0;
}