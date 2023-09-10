// Little Girl and Maximum Sum
// https://codeforces.com/problemset/problem/276/C
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
  ll n, q, l, r;
  cin >> n >> q;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  vector<ll> cont(n + 1, 0);
  while (q--)
  {
    cin >> l >> r;
    l--;
    r--;
    cont[l]++;
    cont[r + 1]--;
  }
  ll aux = 0;
  for (ll i = 0; i < n; i++)
  {
    aux += cont[i];
    cont[i] = aux;
  }
  sort(cont.begin(), cont.end());
  ll answer = 0;
  for (ll i = 0; i < n; i++)
  {
    answer += cont[i + 1] * a[i];
  }
  cout << answer << endl;

  return 0;
}
