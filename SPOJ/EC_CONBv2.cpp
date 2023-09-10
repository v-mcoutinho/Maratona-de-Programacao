// Even Numbers
// https://www.spoj.com/problems/EC_CONB/en/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  unsigned long int n, aux;
  string st;
  cin >> n;
  vector<unsigned long int> ve(n);
  for (int i = 0; i < n; i++)
  {
    cin >> ve[i];
    aux = 0;
    if (ve[i] % 2 == 0)
    {
      while (ve[i] > 0)
      {
        aux <<= 1;
        aux = aux | (ve[i] & 1);
        ve[i] >>= 1;
      }
      ve[i] = aux;
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << ve[i] << endl;
  }

  return 0;
}