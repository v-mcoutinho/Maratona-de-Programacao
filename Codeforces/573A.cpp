// Bear and Poker
// https://codeforces.com/problemset/problem/573/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  bool flag = true;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    while (a[i] % 2 == 0 || a[i] % 3 == 0)
    {
      if (a[i] % 2 == 0)
      {
        a[i] /= 2;
      }
      else if (a[i] % 3 == 0)
      {
        a[i] /= 3;
      }
    }
  }
  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] != a[i + 1])
      flag = false;
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}