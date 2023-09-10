// Stable Groups
// https://codeforces.com/contest/1539/problem/C
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> v(n), vaux;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  if (n == 1)
  {
    cout << "1" << endl;
  }
  else
  {
    for (int i = 1; i < n; i++)
    {
      ll a = v[i] - v[i - 1];
      ll aux = (a - 1) / x;
      if (aux > 0)
        vaux.push_back(aux);
    }
    sort(vaux.begin(), vaux.end());
    ll fin = 0;
    for (int i = 0; i < vaux.size(); i++)
    {
      if (k >= vaux[i])
      {
        k -= vaux[i];
      }
      else
      {
        fin = vaux.size() - i;
        break;
      }
    }
    cout << 1 + fin << endl;
  }

  return 0;
}