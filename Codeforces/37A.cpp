// Towers
// https://codeforces.com/problemset/problem/37/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, total = 0, maior = 0;
  cin >> n;
  vector<int> v(1002, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> k;
    if (v[k] == 0)
      total++;
    v[k]++;
    maior = max(maior, v[k]);
  }
  cout << maior << " " << total << endl;

  return 0;
}