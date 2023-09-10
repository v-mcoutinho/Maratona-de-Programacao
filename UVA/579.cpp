// Clock Hands
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=520
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
  int h, m;
  char c;
  while (1)
  {
    cin >> h >> c >> m;
    if (h == 0 && m == 0)
      break;
    if (!h)
      h = 12;
    double x = ((30 * h) + m * 0.5) - m * 6;
    if (x < 0)
      x += 360;
    if (x > 180)
      x = 360 - x;
    cout << fixed << setprecision(3) << x << endl;
  }

  return 0;
}