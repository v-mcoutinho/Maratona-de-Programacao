// Dragon of Loowater
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2267
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  while (cin >> n >> m, (n || m))
  {
    vector<long long int> dragon(n), knight(m);
    for (int i = 0; i < n; i++)
      cin >> dragon[i];
    for (int i = 0; i < m; i++)
      cin >> knight[i];
    if (m < n)
    {
      cout << "Loowater is doomed!" << endl;
    }
    else
    {
      sort(dragon.begin(), dragon.end());
      sort(knight.begin(), knight.end());
      long long int gold = 0;
      int j = 0;
      bool possible = true;
      for (int i = 0; i < n; i++)
      {
        while (knight[j] < dragon[i] && j < m)
        {
          j++;
        }
        if (j == m)
        {
          possible = false;
          break;
        }
        gold += knight[j];
        j++;
      }
      if (!possible)
        cout << "Loowater is doomed!" << endl;
      else
        cout << gold << endl;
    }
  }

  return 0;
}