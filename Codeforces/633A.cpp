// Ebony and Ivory
// https://codeforces.com/problemset/problem/633/A
#include <bits/stdc++.h>

using namespace std;

bool func(int a, int b, int c)
{
  if (c % b == 0)
    return true;
  while (c > 0)
  {
    if (c % a == 0)
    {
      return true;
    }
    c -= b;
  }
  return false;
}

int main()
{
  int a, b, c, gc;
  cin >> a >> b >> c;
  gc = __gcd(a, b);
  if (c % gc != 0)
    cout << "No" << endl;
  else
  {
    if (func(min(a, b), max(a, b), c))
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }

  return 0;
}