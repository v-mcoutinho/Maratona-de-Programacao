// Add All
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  while (cin >> n, n)
  {
    long long int T = 0, aux;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++)
    {
      aux = v[0] + v[1];
      T += aux;
      v.erase(v.begin() + 1);
      v.erase(v.begin());
      if (aux >= v[n - 3])
      {
        v.insert(v.end(), aux);
      }
      else
      {
        for (int j = 0; j < v.size(); j++)
        {
          if (aux <= v[j])
          {
            v.insert(v.begin() + j, aux);
            break;
          }
        }
      }
    }
    cout << T << endl;
  }

  return 0;
}