// Perfect Team
// https://codeforces.com/problemset/problem/1221/C
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int q, c, m, x, aux, aux1;
  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> c >> m >> x;
    aux1 = min(c, m);
    if (x + (c - aux1) + (m - aux1) >= aux1)
    {
      cout << aux1 << endl;
    }
    else
    {
      c -= x;
      m -= x;
      aux = x;
      aux += (c + m) / 3;
      cout << aux << endl;
    }
  }

  return 0;
}