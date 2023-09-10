// Two Rival Students
// https://codeforces.com/problemset/problem/1257/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t, n, x, a, b;
  cin >> t;
  while (t--)
  {
    cin >> n >> x >> a >> b;
    if (a > b)
      swap(a, b);
    if (x)
    {
      if (a > 1)
      {
        if (x < a - 1)
        {
          a -= x;
          x = 0;
        }
        else
        {
          x -= a - 1;
          a = 1;
        }
      }
    }
    if (x)
    {
      if (b < n)
      {
        if (x < n - b)
        {
          b += x;
          x = 0;
        }
        else
        {
          x += n - b;
          b = n;
        }
      }
    }
    cout << b - a << endl;
  }

  return 0;
}