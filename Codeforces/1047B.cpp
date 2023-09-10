// Cover Points
// https://codeforces.com/problemset/problem/1047/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> x(n);
  for (int i = 0; i < n; i++)
    cin >> x[i].first >> x[i].second;
  int maxi;
  maxi = x[0].first + x[0].second;
  for (int i = 1; i < n; i++)
  {
    if (x[i].first + x[i].second > maxi)
    {
      maxi = x[i].first + x[i].second;
    }
  }
  cout << maxi << endl;

  return 0;
}