// Fox And Two Dots
// https://codeforces.com/problemset/problem/510/B
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
  vector<bool> possible;
  string color;
} dots;

bool possiblefromstart(int x, int y, vector<dots> &v, int n, int m)
{
  int cont = 0;
  if (x)
  {
    if (v[x].color[y] == v[x - 1].color[y])
      cont++;
  }
  if (x < n - 1)
  {
    if (v[x].color[y] == v[x + 1].color[y])
      cont++;
  }
  if (y)
  {
    if (v[x].color[y] == v[x].color[y - 1])
      cont++;
  }
  if (y < m - 1)
  {
    if (v[x].color[y] == v[x].color[y + 1])
      cont++;
  }
  if (cont < 2)
    return false;
  else
    return true;
}

bool searchgrid(vector<dots> &grid, int x, int y, int xog, int yog, int cont, int n, int m)
{
  if (x == xog && y == yog)
  {
    if (cont > 3)
      return true;
    return false;
  }
  grid[x].possible[y] = false;
  if (x)
  {
    if (grid[x - 1].possible[y] && grid[x].color[y] == grid[x - 1].color[y])
    {
      if (searchgrid(grid, x - 1, y, xog, yog, cont + 1, n, m))
        return true;
    }
  }
  if (x < n - 1)
  {
    if (grid[x + 1].possible[y] && grid[x].color[y] == grid[x + 1].color[y])
    {
      if (searchgrid(grid, x + 1, y, xog, yog, cont + 1, n, m))
        return true;
    }
  }
  if (y)
  {
    if (grid[x].possible[y - 1] && grid[x].color[y] == grid[x].color[y - 1])
    {
      if (searchgrid(grid, x, y - 1, xog, yog, cont + 1, n, m))
        return true;
    }
  }
  if (y < m - 1)
  {
    if (grid[x].possible[y + 1] && grid[x].color[y] == grid[x].color[y + 1])
    {
      if (searchgrid(grid, x, y + 1, xog, yog, cont + 1, n, m))
        return true;
    }
  }
  grid[x].possible[y] = true;
  return false;
}

bool startsearch(vector<dots> &grid, int x, int y, int n, int m)
{
  if (x)
  {
    if (searchgrid(grid, x - 1, y, x, y, 1, n, m))
      return true;
  }
  if (x < n - 1)
  {
    if (searchgrid(grid, x + 1, y, x, y, 1, n, m))
      return true;
  }
  if (y)
  {
    if (searchgrid(grid, x, y - 1, x, y, 1, n, m))
      return true;
  }
  if (y < m - 1)
  {
    if (searchgrid(grid, x, y + 1, x, y, 1, n, m))
      return true;
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<dots> grid(n);
  for (int i = 0; i < n; i++)
  {
    cin >> grid[i].color;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      grid[i].possible.push_back(possiblefromstart(i, j, grid, n, m));
    }
  }
  bool flag = false;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i].possible[j])
      {
        if (startsearch(grid, i, j, n, m))
        {
          flag = true;
          break;
        }
      }
      if (flag)
        break;
    }
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}