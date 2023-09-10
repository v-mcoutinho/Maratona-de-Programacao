// Water Buying
// https://codeforces.com/problemset/problem/1118/A
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll q, n, a, b;
  cin >> q;
  while (q--)
  {
    cin >> n >> a >> b;
    if (b < 2 * a)
    {
      if (n % 2 == 1)
      {
        cout << n / 2 * b + a << endl;
      }
      else
      {
        cout << n / 2 * b << endl;
      }
    }
    else
    {
      cout << a * n << endl;
    }
  }

  return 0;
}