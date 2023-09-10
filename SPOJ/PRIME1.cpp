// Prime Generator
// https://www.spoj.com/problems/PRIME1/en/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isItAPrimeNumber(int x)
{
  int aux = sqrt(x);
  for (int i = 3; i <= aux; i += 2)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main()
{
  int m, n, t;
  cin >> t;
  for (int cont1 = 0; cont1 < t; cont1++)
  {
    cin >> m >> n;
    if (m == 1)
      m++;
    if (m % 2 == 0)
    {
      if (m == 2)
        cout << m << endl;
      m++;
    }
    for (int cont2 = m; cont2 <= n; cont2 += 2)
    {
      if (isItAPrimeNumber(cont2))
      {
        cout << cont2 << endl;
      }
    }
    if (cont1 != t - 1)
      cout << endl;
  }

  return 0;
}