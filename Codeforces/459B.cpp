// Pashmak and Flowers
// https://codeforces.com/problemset/problem/459/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long int n;
  cin >> n;
  vector<long long int> b(n);
  for (long long int i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  long long int menor = 0, maior = 0;
  for (long long int i = 0; i < n; i++)
  {
    menor++;
    if (i == n - 1)
    {
      break;
    }
    if (b[i] != b[i + 1])
      break;
  }
  for (long long int i = n - 1; i >= 0; i--)
  {
    maior++;
    if (!i)
    {
      break;
    }
    if (b[i] != b[i - 1])
      break;
  }
  int r = b[n - 1] - b[0];
  if (r)
    cout << r << " " << menor * maior << endl;
  else
    cout << r << " " << n * (n - 1) / 2 << endl;

  return 0;
}