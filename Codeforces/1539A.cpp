// Contest Start
// https://codeforces.com/contest/1539/problem/A
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
  int k;
  cin >> k;
  vector<ll> result;
  while (k--)
  {
    ll n, x, t;
    cin >> n >> x >> t;
    ll a = t / x;
    ll m = min(a, n - 1);
    result.push_back((m * (1 + m) / 2) + (n - 1 - m) * m);
  }
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }

  return 0;
}