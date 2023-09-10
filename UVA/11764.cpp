// Jumping Mario
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2864
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, n, x, y, high, low;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cin >> n;
    high = 0;
    low = 0;
    cin >> x;
    n--;
    while (n--)
    {
      cin >> y;
      if (y > x)
        high++;
      else if (y < x)
        low++;
      x = y;
    }
    cout << "Case " << i << ": " << high << " " << low << endl;
  }

  return 0;
}