// Benches
// https://codeforces.com/problemset/problem/1042/A
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> &a, int n, int max, int *m)
{
  for (int i = 0; i < n - 1; i++)
  {
    if ((*m) <= max - a[i])
      return max;
    *m = *m - (max - a[i]);
  }
  if ((*m) % n != 0)
    return max + ((*m) / n) + 1;
  return max + ((*m) / n);
}

int main()
{
  int n, m, max1;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  max1 = a[n - 1] + m;
  cout << func(a, n, a[n - 1], &m) << " " << max1 << endl;

  return 0;
}