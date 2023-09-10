// Bits
// https://codeforces.com/problemset/problem/484/A
#include <bits/stdc++.h>

using namespace std;

unsigned long long int findit(unsigned long long int x)
{
  if (x == 0)
    return 0;
  return (unsigned long long int)((unsigned long long int)1 << (unsigned long long int)floor(log2(x + 1))) - 1;
}

unsigned long long int func(unsigned long long int l, unsigned long long int r)
{
  if (l == r)
    return l;
  unsigned long long int aux, aux2, h = 1;
  aux = findit(r);
  if (aux < l)
  {
    aux2 = func(l - aux - h, r - aux - h);
    return aux + aux2 + h;
  }
  else
  {
    return aux;
  }
}

int main()
{
  int n;
  unsigned long long int l, r, aux, aux2;
  cin >> n;
  while (n--)
  {
    cin >> l >> r;
    cout << func(l, r) << endl;
  }

  return 0;
}
