// Bee
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1941
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void printsol(vector<ll> &x, ll v)
{
  ll aux = x[v] + x[v - 1] - 1;
  cout << aux << " " << aux + x[v] << endl;
}

void fillbee(vector<ll> &x, ll n)
{
  ll i = x.size();
  do
  {
    x.push_back(x[i - 1] + x[i - 2]);
    i++;
  } while (i <= n);
}

int main()
{
  ll n;
  vector<ll> bee;
  bee.push_back(1);
  bee.push_back(1);
  while (true)
  {
    cin >> n;
    if (n == -1)
    {
      break;
    }
    if (!n)
    {
      cout << "0 1" << endl;
    }
    else if (n >= bee.size())
    {
      fillbee(bee, n);
      printsol(bee, n);
    }
    else
    {
      printsol(bee, n);
    }
  }

  return 0;
}
