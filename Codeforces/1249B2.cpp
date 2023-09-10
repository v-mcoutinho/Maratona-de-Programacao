// Books Exchange (hard version)
// https://codeforces.com/problemset/problem/1249/B2
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
  int q;
  cin >> q;
  while (q--)
  {
    int n, pos, aux;
    cin >> n;
    vector<int> books(n);
    vector<subset> booksets(n);
    for (int i = 0; i < n; i++)
    {
      cin >> books[i];
      books[i]--;
      booksets[i].height = 0;
      booksets[i].parent = -1;
    }
    for (int i = 0; i < n; i++)
    {
      if (booksets[i].parent == -1)
      {
        pos = i;
        do
        {
          Union(booksets, i, pos);
          pos = books[pos];
        } while (pos != i);
        cout << booksets[i].height + 1;
      }
      else
      {
        aux = find(booksets, i);
        cout << booksets[aux].height + 1;
      }
      if (i == n - 1)
      {
        cout << endl;
      }
      else
      {
        cout << " ";
      }
    }
  }

  return 0;
}