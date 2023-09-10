// Chat Order
// https://codeforces.com/problemset/problem/637/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  stack<string> sta;
  map<string, bool> ma;
  string s;
  cin >> n;
  while (n--)
  {
    cin >> s;
    sta.push(s);
  }
  while (!sta.empty())
  {
    s = sta.top();
    sta.pop();
    if (!ma.count(s))
    {
      ma.insert({s, true});
      cout << s << endl;
    }
  }

  return 0;
}