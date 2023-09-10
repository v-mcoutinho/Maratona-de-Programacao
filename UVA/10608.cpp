// Friends
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
  int parent, height;
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
  return x;
}

void Union(vector<subset> &friends, int x, int y)
{
  int a, b;
  a = find(friends, x);
  b = find(friends, y);
  if (a == b)
    return;
  if (friends[a].height > friends[b].height)
  {
    friends[b].parent = a;
    friends[a].height += friends[b].height + 1;
  }
  else if (friends[a].height < friends[b].height)
  {
    friends[a].parent = b;
    friends[b].height += friends[a].height + 1;
  }
  else
  {
    friends[b].parent = a;
    friends[a].height += friends[b].height + 1;
  }
}

int main()
{
  int t, n, m, a, b;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    vector<subset> friends(n);
    for (int i = 0; i < n; i++)
    {
      friends[i].parent = -1;
      friends[i].height = 0;
    }
    for (int i = 0; i < m; i++)
    {
      cin >> a >> b;
      Union(friends, a - 1, b - 1);
    }
    int m = 0;
    for (int i = 0; i < n; i++)
    {
      m = max(m, friends[i].height);
    }
    cout << m + 1 << endl;
  }

  return 0;
}