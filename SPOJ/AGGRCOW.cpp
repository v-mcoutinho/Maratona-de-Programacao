// Aggressive cows
// https://www.spoj.com/problems/AGGRCOW/en/
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

bool isPossible(int m, vector<int> &x, int n, int c)
{
  int pos = x[0], cowsPlaced = 1;
  for (int i = 1; i < n; i++)
  {
    if (x[i] - pos >= m)
    {
      pos = x[i];
      cowsPlaced++;
    }
    if (cowsPlaced == c)
      return true;
  }
  return false;
}

int dist(vector<int> &x, int n, int c)
{
  int d = -1, l = 1, r = x[n - 1] - x[0];
  while (l < r)
  {
    int m = (l + r) / 2;
    if (isPossible(m, x, n, c))
    {
      d = max(d, m);
      l = m + 1;
    }
    else
    {
      r = m;
    }
  }
  return d;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, c;
  cin >> t;
  while (t--)
  {
    cin >> n >> c;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
      cin >> x[i];
    sort(x.begin(), x.end());
    cout << dist(x, n, c) << endl;
  }

  return 0;
}