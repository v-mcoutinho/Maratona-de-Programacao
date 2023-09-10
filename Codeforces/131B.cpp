// Opposites Attract
// https://codeforces.com/problemset/problem/131/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long int n, aux;
  vector<long long int> x(21, 0);
  cin >> n;
  for (unsigned long long int i = 0; i < n; i++)
  {
    cin >> aux;
    if (aux <= 0)
    {
      x[-aux]++;
    }
    else
    {
      x[aux + 10]++;
    }
  }
  long long int cont = 0;
  for (unsigned long long int i = 1; i < 11; i++)
  {
    cont += x[i] * x[i + 10];
  }
  cont += x[0] * (x[0] - 1) / 2;
  cout << cont << endl;

  return 0;
}