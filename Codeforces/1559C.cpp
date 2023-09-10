// Mocha and Hiking
// https://codeforces.com/contest/1559/problem/C
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 0, n;
  cin >> t;

  while (t--)
  {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    if (a[0] == 1)
    {
      cout << n + 1 << " ";
      for (int i = 1; i <= n; i++)
        cout << i << " ";
    }
    else if (a[n - 1] == 0)
    {
      for (int i = 1; i <= n + 1; i++)
        cout << i << " ";
    }
    else
    {
      int aux = 0;
      for (int i = 1; i < n; i++)
      {
        if (a[i] == 1)
        {
          aux = i;
          break;
        }
      }
      for (int i = 1; i <= n; i++)
      {
        cout << i << " ";
        if (i == aux)
        {
          cout << n + 1 << " ";
        }
      }
    }
    cout << endl;
  }

  return 0;
}