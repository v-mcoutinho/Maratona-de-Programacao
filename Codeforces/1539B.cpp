// Love Song
// https://codeforces.com/contest/1539/problem/B
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void build(vector<int> &X, int n)
{
  int aux;
  for (int i = n - 1; i > 0; i--)
  {
    X[i] = X[2 * i] + X[2 * i + 1];
  }
}

int operation(vector<int> &X, int n, int l, int r)
{
  int aux = 0;
  for (l = l + n, r = r + n; l < r; l /= 2, r /= 2)
  {
    if (l % 2)
    {
      aux += X[l];
      l++;
    }
    if (r % 2)
    {
      r--;
      aux += X[r];
    }
  }
  return aux;
}

int main()
{
  int n, q, l, r;
  string s;
  cin >> n >> q;
  cin >> s;
  vector<int> V(2 * n + 1), result;
  for (int i = 0; i < s.length(); i++)
  {
    V[i + n] = s[i] - 'a' + 1;
  }
  build(V, n);
  while (q--)
  {
    cin >> l >> r;
    result.push_back(operation(V, n, l - 1, r));
  }
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << endl;
  }

  return 0;
}