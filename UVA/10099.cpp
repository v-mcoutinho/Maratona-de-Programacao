// The Tourist Guide
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1040
#include <bits/stdc++.h>

using namespace std;

int maximumThreshold(vector<vector<int>> &graph, int s, int t, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        graph[j][k] = max(min(graph[j][i], graph[i][k]), graph[j][k]);
      }
    }
  }
  return graph[s][t];
}

int main()
{
  int n, r, x, y, c, starting, ending, tourists;
  for (int i = 1;; i++)
  {
    cin >> n >> r;
    if (!n && !r)
      break;
    int answer = 0;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int j = 0; j < r; j++)
    {
      cin >> x >> y >> c;
      x--;
      y--;
      graph[x][y] = c;
      graph[y][x] = c;
    }
    cin >> starting >> ending >> tourists;
    starting--;
    ending--;
    cout << "Scenario #" << i << endl
         << "Minimum Number of Trips = " << (long int)ceil((double)tourists / (maximumThreshold(graph, starting, ending, n) - 1)) << endl
         << endl;
  }

  return 0;
}