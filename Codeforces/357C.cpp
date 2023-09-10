// Knight Tournament
// https://codeforces.com/problemset/problem/357/C
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, l, r, x;
  cin >> n >> m;
  set<int> knights;
  set<int>::iterator itr;
  queue<int> eraseThese;
  vector<int> answers(n + 1, 0);
  for (int i = 1; i <= n; i++)
    knights.insert(i);
  while (m--)
  {
    cin >> l >> r >> x;
    for (itr = knights.lower_bound(l); itr != knights.end(); itr++)
    {
      int aux = *itr;
      if (aux > r)
        break;
      if (aux != x)
      {
        answers[aux] = x;
        eraseThese.push(aux);
      }
    }
    while (!eraseThese.empty())
    {
      knights.erase(eraseThese.front());
      eraseThese.pop();
    }
  }
  for (int i = 1; i < n; i++)
  {
    cout << answers[i] << " ";
  }
  cout << answers[n] << endl;

  return 0;
}