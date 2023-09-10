// Stone Pile
// https://acm.timus.ru/problem.aspx?space=1&num=1005
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
  ll n, total = 0, current, closer;
  cin >> n;
  vector<int> rock(n);
  for (int i = 0; i < n; i++)
  {
    cin >> rock[i];
    total += rock[i];
  }
  current = total / 2;
  closer = total;
  ll aux = 1 << n, sum;
  for (ll i = 0; i < aux; i++)
  {
    sum = 0;
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        sum += rock[j];
      }
    }
    closer = min(closer, abs(current - sum));
  }
  cout << 2 * closer + total % 2 << endl;

  return 0;
}