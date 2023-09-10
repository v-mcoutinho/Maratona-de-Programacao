// Roads not only in Berland
// https://codeforces.com/problemset/problem/25/D
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
  int parent, rank;
} subset;

int find(vector<subset> &friends, int a)
{
  if (friends[a].parent == -1)
    return a;
  int x = a;
  while (friends[x].parent != -1)
  {
    x = friends[x].parent;
  }
  friends[a].parent = x;
  return x;
}

void Union(vector<subset> &friends, int a, int b)
{
  int x, y;
  x = find(friends, a);
  y = find(friends, b);
  if (x == y)
    return;
  if (friends[x].rank > friends[y].rank)
  {
    friends[y].parent = x;
  }
  else if (friends[x].rank < friends[y].rank)
  {
    friends[x].parent = y;
  }
  else
  {
    friends[y].parent = x;
    friends[x].rank++;
  }
}

int main()
{
  int n, a, b;
  cin >> n;
  vector<subset> roads(n);
  vector<pair<int, int>> cycles, answers;
  for (int i = 0; i < n; i++)
  {
    roads[i].parent = -1;
    roads[i].rank = 0;
  }
  for (int i = 1; i < n; i++)
  {
    cin >> a >> b;
    a--;
    b--;
    if (find(roads, a) == find(roads, b))
    {
      cycles.push_back({a, b});
    }
    else
    {
      Union(roads, a, b);
    }
  }
  int startingpoint;
  for (int i = 0; i < cycles.size(); i++)
  {
    startingpoint = find(roads, cycles[i].first);
    for (int j = 0; j < n; j++)
    {
      if (startingpoint != find(roads, j))
      {
        answers.push_back(cycles[i]);
        answers.push_back({cycles[i].first + 1, j + 1});
        Union(roads, cycles[i].first, j);
        break;
      }
    }
  }
  cout << answers.size() / 2 << endl;
  for (int i = 0; i < answers.size(); i += 2)
  {
    cout << answers[i].first + 1 << " " << answers[i].second + 1 << " " << answers[i + 1].first << " " << answers[i + 1].second << endl;
  }

  return 0;
}