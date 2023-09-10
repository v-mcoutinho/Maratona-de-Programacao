// DZY Loves Chemistry
// https://codeforces.com/problemset/problem/445/B
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
  int n, m, a, b;
  cin >> n >> m;
  if (!m)
  {
    cout << 1 << endl;
  }
  else
  {
    vector<subset> v(n);
    for (int i = 0; i < n; i++)
    {
      v[i].parent = -1;
      v[i].height = 0;
    }
    for (int i = 0; i < m; i++)
    {
      cin >> a >> b;
      a--;
      b--;
      Union(v, a, b);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      if (v[i].parent == -1)
        maxi += v[i].height;
    }
    cout << (long long int)pow(2, maxi) << endl;
  }

  return 0;
}