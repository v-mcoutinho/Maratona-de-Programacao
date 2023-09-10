// Crazy Town
// https://codeforces.com/problemset/problem/498/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long int x1, x2, y1, y2, a, b, c, n, cont = 0;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> n;
  while (n--)
  {
    cin >> a >> b >> c;
    if (signbit(a * x1 + b * y1 + c) != signbit(a * x2 + b * y2 + c))
    {
      cont++;
    }
  }
  cout << cont << endl;

  return 0;
}