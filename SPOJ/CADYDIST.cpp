// Candy Distribution
// https://www.spoj.com/problems/CADYDIST/en/
#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

long long int func(long long int n, long long int c[], long long int p[])
{
  long long int x = 0;
  for (long long int i = 0; i < n; i++)
  {
    x += c[i] * p[i];
  }
  return x;
}

int main()
{
  long long int n = 0;
  while (true)
  {
    cin >> n;
    if (!n)
      break;
    long long int p[MAX], c[MAX];
    for (long long int i = 0; i < n; i++)
    {
      cin >> c[i];
    }
    for (long long int i = 0; i < n; i++)
    {
      cin >> p[i];
    }
    sort(p, p + n);
    sort(c, c + n, greater<long long int>());
    cout << func(n, c, p) << endl;
  }

  return 0;
}