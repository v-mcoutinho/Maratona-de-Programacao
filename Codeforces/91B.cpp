// Queue
// https://codeforces.com/problemset/problem/91/B
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, minaux;
  cin >> n;
  vector<int> a(n), minA(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  minA[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    minA[i] = min(minA[i + 1], a[i]);
  }
  for (int i = 0; i < n; i++)
  {
    minaux = distance(minA.begin() + i, lower_bound(minA.begin(), minA.end(), a[i])) - 2;
    if (minaux < 0)
      cout << "-1";
    else
      cout << minaux;
    if (i != n - 1)
      cout << " ";
  }
  cout << endl;

  return 0;
}