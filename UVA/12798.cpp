// Handball
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4663
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int m, n, x, aux, T;
  while (true)
  {
    T = 0;
    cin >> n >> m;
    if (cin.eof())
      break;
    for (int i = 0; i < n; i++)
    {
      aux = 1;
      for (int j = 0; j < m; j++)
      {
        cin >> x;
        if (!x)
          aux = 0;
      }
      if (aux == 1)
        T++;
    }
    cout << T << endl;
  }

  return 0;
}