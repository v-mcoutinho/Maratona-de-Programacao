// Passwords
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=569
#include <bits/stdc++.h>

using namespace std;

void p(vector<string> &d, string r, string printthis, int pos)
{
  if (pos == r.length())
  {
    cout << printthis << endl;
  }
  else
  {
    if (r[pos] == '0')
    {
      for (int i = 0; i < 10; i++)
      {
        p(d, r, printthis + to_string(i), pos + 1);
      }
    }
    else
    {
      for (int i = 0; i < d.size(); i++)
      {
        p(d, r, printthis + d[i], pos + 1);
      }
    }
  }
}

int main()
{
  int n, m, pos = 0;
  while (true)
  {
    cin >> n;
    if (cin.eof())
      break;
    vector<string> dictionary(n);
    for (int i = 0; i < n; i++)
      cin >> dictionary[i];
    cin >> m;
    vector<string> rules(m);
    for (int i = 0; i < m; i++)
      cin >> rules[i];
    cout << "--" << endl;
    for (int i = 0; i < m; i++)
    {
      p(dictionary, rules[i], "", 0);
    }
  }

  return 0;
}