// Light, more light
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1051
#include <bits/stdc++.h>

using namespace std;

int main()
{
  long double n;
  while (cin >> n, n)
  {
    long double sr = sqrt(n);
    if (n = !0)
    {
      if (sr - floor(sr) == 0)
        cout << "yes" << endl;
      else
        cout << "no" << endl;
    }
  }

  return 0;
}