// Flags
// https://acm.timus.ru/problem.aspx?space=1&num=1225
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll fibo(ll pos, vector<ll> &auxinacci)
{
  if (auxinacci[pos] != -1)
    return auxinacci[pos];
  auxinacci[pos] = fibo(pos - 1, auxinacci) + fibo(pos - 2, auxinacci);
  return auxinacci[pos];
}

int main()
{
  ll n, m;
  vector<ll> auxinacci(46, -1);
  auxinacci[0] = 0;
  auxinacci[1] = 1;
  cin >> n;
  cout << 2 * fibo(n, auxinacci) << endl;

  return 0;
}
