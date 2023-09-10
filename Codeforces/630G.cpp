// Challenge Pennants
// https://codeforces.com/problemset/problem/630/G
#include <bits/stdc++.h>

using namespace std;

int main()
{
  unsigned long long int n, cont;
  cin >> n;
  cout << setprecision(0) << fixed << ((n + 4) * (n + 3) / 2 * (n + 2) / 3 * (n + 1) / 4 * n / 5) * ((n + 2) * (n + 1) / 2 * n / 3) << endl;

  return 0;
}