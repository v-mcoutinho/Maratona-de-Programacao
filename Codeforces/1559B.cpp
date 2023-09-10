// Mocha and Red and Blue
// https://codeforces.com/contest/1559/problem/B
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 0, n;
  cin >> t;

  while (t--)
  {
    string s;
    cin >> n;
    cin >> s;
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
      if (s[i] != '?')
      {
        pos = i;
        break;
      }
    }
    if (pos == -1)
    {
      s[0] = 'B';
      pos = 0;
    }
    for (int i = pos; i - 1 >= 0; i--)
    {
      if (s[i - 1] == '?')
      {
        if (s[i] == 'B')
        {
          s[i - 1] = 'R';
        }
        else
        {
          s[i - 1] = 'B';
        }
      }
    }
    for (int i = pos; i + 1 < n; i++)
    {
      if (s[i + 1] == '?')
      {
        if (s[i] == 'B')
        {
          s[i + 1] = 'R';
        }
        else
        {
          s[i + 1] = 'B';
        }
      }
    }
    cout << s << endl;
  }

  return 0;
}
