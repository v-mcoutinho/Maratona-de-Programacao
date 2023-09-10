// Galactic Bonding
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3117
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
  int parent, rank;
  double x, y;
} subset;

double dist(double x1, double y1, double x2, double y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

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
  int t, n;
  double d, x, y;
  cin >> t;
  for (int a = 1; a <= t; a++)
  {
    cin >> n >> d;
    vector<subset> stars(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stars[i].x >> stars[i].y;
      stars[i].parent = -1;
      stars[i].rank = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (dist(stars[i].x, stars[i].y, stars[j].x, stars[j].y) < d)
        {
          Union(stars, i, j);
        }
      }
    }
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
      if (stars[i].parent == -1)
        cont++;
    }
    cout << "Case " << a << ": " << cont << endl;
  }

  return 0;
}