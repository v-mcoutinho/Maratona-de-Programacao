// Rare Order
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=136
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
  vector<string> a;
  string x;
  int aux1, aux2;
  while (cin >> x)
  {
    if (cin.eof())
      break;
    if (x == "#")
    {
      vector<vector<int>> graph(26);
      vector<int> visited(26, 1);
      for (int i = 0; i < a.size() - 1; i++)
      {
        for (int j = 0; j < a[i].size(); j++)
        {
          if (j == a[i + 1].size())
            break;
          if (a[i][j] != a[i + 1][j])
          {
            aux1 = a[i][j] - 'A';
            aux2 = a[i + 1][j] - 'A';
            graph[aux1].push_back(aux2);
            visited[aux1] = 0;
            visited[aux2] = 0;
            break;
          }
        }
      }
      stack<int> s;
      for (int i = 0; i < 26; i++)
      {
        topOrder(graph, s, visited, i);
      }
      while (!s.empty())
      {
        aux1 = s.top() + 'A';
        s.pop();
        cout << (char)aux1;
      }
      cout << endl;
      a.clear();
    }
    else
    {
      a.push_back(x);
    }
  }

  return 0;
}