// Sonya and Queries
// https://codeforces.com/problemset/problem/714/C
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

string badfunc(ll x)
{
  string s = "000000000000000000";
  for (int i = 17; i >= 0; i--)
  {
    s[i] = x % 2 + '0';
    x /= 10;
    if (!x)
      break;
  }
  return s;
}

int main()
{
  map<string, ll> m;
  ll t, a;
  cin >> t;
  char c;
  while (t--)
  {
    cin >> c;
    cin >> a;
    if (c == '+')
    {
      m[badfunc(a)]++;
    }
    else if (c == '-')
    {
      m[badfunc(a)]--;
    }
    else
    {
      string aux = badfunc(a);
      if (m.count(aux))
      {
        cout << m[aux] << endl;
      }
      else
      {
        cout << "0" << endl;
      }
    }
  }

  return 0;
}