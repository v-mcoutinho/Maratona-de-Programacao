// Hyper Box
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3433
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll func(vector<ll> &fibo, ll x, ll cont)
{
  ll y = fibo[upper_bound(fibo.begin(), fibo.end(), x) - fibo.begin() - 1];
  if (x != y)
  {
    cont = func(fibo, x - y, cont + 1);
  }
  return cont;
}

int main()
{
  ll T, x = 3;
  cin >> T;
  vector<ll> fibo;
  fibo.push_back(1);
  fibo.push_back(2);
  for (ll i = 2; x <= 2000000000; i++)
  {
    fibo.push_back(x);
    x = fibo[i] + fibo[i - 1];
  }
  for (ll i = 1; i <= T; i++)
  {
    ll N, M;
    ll cont = 1;
    cin >> N;
    for (ll j = 0; j < N; j++)
    {
      cin >> M;
      cont *= func(fibo, M, 1);
    }
    cout << "Case " << i << ": " << cont << endl;
  }

  return 0;
}
