// Wine trading in Gergovia
// https://www.spoj.com/problems/GERGOVIA/en/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  while (cin >> n, n)
  {
    vector<int> v(n);
    long long int cont = 0, cont2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
      cin >> v[i];
      cont += v[i];
      cont2 += abs(cont);
    }
    cin >> v[n - 1];
    cout << cont2 << endl;
  }

  return 0;
}