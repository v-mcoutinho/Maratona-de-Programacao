// Binary search
// https://www.eolymp.com/en/problems/9016
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
  int n, q, x;
  cin >> n >> q;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < q; i++)
  {
    cin >> x;
    if (binary_search(v.begin(), v.end(), x))
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}