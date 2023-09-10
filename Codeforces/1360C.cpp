// Similar Pairs
// https://codeforces.com/problemset/problem/1360/C
#include <bits/stdc++.h>

using namespace std;

bool func(vector<int> &x)
{
  for (int i = 1; i < x.size(); i++)
  {
    if (x[i - 1] + 1 == x[i])
      return true;
  }
  return false;
}

int main()
{
  int t;
  vector<int> count(2);
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a(n);
    count[0] = 0;
    count[1] = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      count[a[i] % 2]++;
    }
    if (count[0] % 2 == 0)
    {
      cout << "YES" << endl;
    }
    else
    {
      sort(a.begin(), a.end());
      if (func(a))
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }

  return 0;
}