// Monitor
// https://codeforces.com/problemset/problem/16/C
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int gcdaux;
  gcdaux = __gcd(x, y);
  x /= gcdaux;
  y /= gcdaux;
  if (x > a || y > b)
    cout << "0 0" << endl;
  else
  {
    int aux = min(floor((double)a / x), floor((double)b / y));
    cout << x * aux << " " << y * aux << endl;
  }

  return 0;
}