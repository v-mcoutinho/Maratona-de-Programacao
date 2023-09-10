// Mocha and Math
// https://codeforces.com/contest/1559/problem/A
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 0;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    ll a, x;
    cin >> a;
    x = a;
    for (int i = 1; i < n; i++)
    {
      cin >> a;
      x = x & a;
    }
    cout << x << endl;
  }

  return 0;
}
