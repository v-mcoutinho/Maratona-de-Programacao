// Mountain Ranges
// https://codeforces.com/gym/102428/problem/M
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int cont = 1, maxi = 0;
  for (int i = 1; i < n; i++)
  {
    if (a[i] - a[i - 1] > x)
    {
      maxi = max(cont, maxi);
      cont = 0;
    }
    cont++;
  }
  maxi = max(cont, maxi);
  cout << maxi << endl;

  return 0;
}