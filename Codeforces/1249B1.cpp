// Books Exchange (easy version)
// https://codeforces.com/problemset/problem/1249/B1
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int q;
  cin >> q;
  while (q--)
  {
    int n, pos;
    cin >> n;
    vector<int> books(n), answer(n, 0);
    for (int i = 0; i < n; i++)
    {
      cin >> books[i];
      books[i]--;
    }
    for (int i = 0; i < n; i++)
    {
      pos = i;
      do
      {
        pos = books[pos];
        answer[i]++;
      } while (pos != i);
    }
    for (int i = 0; i < n; i++)
    {
      cout << answer[i];
      if (i != n - 1)
        cout << " ";
      else
        cout << endl;
    }
  }

  return 0;
}