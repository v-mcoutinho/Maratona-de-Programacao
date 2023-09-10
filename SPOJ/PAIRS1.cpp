// Count the Pairs
// https://www.spoj.com/problems/PAIRS1/en/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, total = 0, c;
  cin >> n >> k;
  map<int, bool> v;
  map<int, bool>::iterator it;

  for (int i = 0; i < n; i++)
  {
    cin >> c;
    v[c] = false;
    it = v.find(c - k);
    if (it != v.end())
      total++;
    it = v.find(c + k);
    if (it != v.end())
      total++;
  }
  cout << total << endl;

  return 0;
}