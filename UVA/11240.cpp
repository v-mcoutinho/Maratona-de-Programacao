// Antimonotonicity
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2181
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
  int t, n, aux1, aux2, h, l;
  cin >> t;
  while (t--)
  {
    cin >> n;
    h = 0;
    l = 0;
    aux1 = 0;
    while (n--)
    {
      cin >> aux2;
      if (aux2 > aux1)
        h = l + 1;
      else if (aux2 < aux1)
        l = h + 1;
      aux1 = aux2;
    }
    cout << max(h, l) << endl;
  }

  return 0;
}