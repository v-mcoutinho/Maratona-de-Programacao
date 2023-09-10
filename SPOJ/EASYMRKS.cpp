// Easy Marks
// https://www.spoj.com/problems/EASYMRKS/en/
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
  int t, n, k;
  cin >> t;
  for (int x = 1; x <= t; x++)
  {
    int aux, a = 0, total = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
      cin >> aux;
      a += aux;
    }
    total = k * (n + 1);
    total -= a;
    cout << "Case " << x << ": " << total << endl;
  }

  return 0;
}