// Party
// https://codeforces.com/problemset/problem/115/A
#include <bits/stdc++.h>

using namespace std;

void func(vector<pair<int, int>> &emp, int i)
{
  if (emp[emp[i].first - 1].second == -1)
    func(emp, emp[i].first - 1);
  emp[i].second = emp[emp[i].first - 1].second + 1;
}

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> emp(n);
  for (int i = 0; i < n; i++)
  {
    cin >> emp[i].first;
    if (emp[i].first == -1)
      emp[i].second = 0;
    else
      emp[i].second = -1;
  }
  for (int i = 0; i < n; i++)
  {
    if (emp[i].second == -1)
      func(emp, i);
  }
  int maxi = emp[0].second;
  for (int i = 1; i < n; i++)
  {
    maxi = max(maxi, emp[i].second);
  }
  cout << maxi + 1 << endl;

  return 0;
}