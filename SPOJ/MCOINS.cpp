// Coins Game
// https://www.spoj.com/problems/MCOINS/en/
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int func(vector<int> &va, int k, int l, int pos)
{
  if (va[pos] != -1)
    return va[pos];
  vector<int> aux(3, INT_MAX);
  aux[0] = func(va, k, l, pos - 1);
  if (pos >= k)
    aux[1] = func(va, k, l, pos - k);
  if (pos >= l)
    aux[2] = func(va, k, l, pos - l);
  int x = 0;
  for (int i = 0; i < 3; i++)
  {
    if (x == aux[i])
      x++;
  }
  va[pos] = x;
  return va[pos];
}

int main()
{
  int k, l, m, n;
  cin >> k >> l >> m;
  string x;
  x.clear();
  vector<int> va(10000001, -1);
  va[0] = 0;
  for (int i = 0; i < m; i++)
  {
    cin >> n;
    if (!func(va, k, l, n))
    {
      x += "B";
    }
    else
    {
      x += "A";
    }
  }
  cout << x << endl;

  return 0;
}