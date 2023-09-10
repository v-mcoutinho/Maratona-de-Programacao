// Cube Free Numbers
// https://www.spoj.com/problems/CUBEFR/en/
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void func(vector<ll> &x)
{
  ll aux = 8, i = 2;
  while (aux < 1000001)
  {
    for (ll j = aux; j < 1000001; j += aux)
    {
      x[j] = -1;
    }
    i++;
    aux = i * i * i;
  }
  aux = 1;
  for (ll i = 1; i < 1000001; i++)
  {
    if (x[i] != -1)
    {
      x[i] = aux;
      aux++;
    }
  }
}

int main()
{
  vector<ll> x(1000001, 0);
  ll n, t, aux = 0;
  cin >> t;
  func(x);
  for (ll i = 1; i <= t; i++)
  {
    cin >> n;
    if (x[n] == -1)
    {
      cout << "Case " << i << ": Not Cube Free" << endl;
    }
    else
    {
      cout << "Case " << i << ": " << x[n] << endl;
    }
  }

  return 0;
}