// Jugs
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=512
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, n;
  while (true)
  {
    cin >> a >> b >> n;
    if (cin.eof())
      break;
    int ca = 0, cb = 0;
    while (cb != n)
    {
      if (!ca)
      {
        ca = a;
        cout << "fill A" << endl;
      }
      if (ca + cb <= b)
      {
        cb += ca;
        ca = 0;
      }
      else
      {
        ca -= b - cb;
        cb = b;
      }
      cout << "pour A B" << endl;
      if (cb == n)
        break;
      if (cb == b)
      {
        cb = 0;
        cout << "empty B" << endl;
      }
    }
    cout << "success" << endl;
  }

  return 0;
}