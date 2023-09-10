// Lap
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4656
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x, y;
  while (true)
  {
    cin >> x >> y;
    if (cin.eof())
      break;
    int a = y - x;
    if (a >= x)
    {
      cout << "2" << endl;
    }
    else
    {
      cout << (int)ceil((double)x / a) + 1 << endl;
    }
  }

  return 0;
}