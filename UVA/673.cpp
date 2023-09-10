// Parentheses Balance
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

bool func(string x)
{
  stack<char> stck;
  for (int i = 0; i < x.length(); i++)
  {
    if (x[i] == ' ')
      continue;
    if (x[i] == '(' || x[i] == '[')
    {
      stck.push(x[i]);
    }
    else
    {
      if (stck.empty())
        return false;
      if (x[i] == ')')
      {
        if (stck.top() == '(')
          stck.pop();
        else
          return false;
      }
      else
      {
        if (stck.top() == '[')
          stck.pop();
        else
          return false;
      }
    }
  }
  if (stck.empty())
    return true;
  return false;
}

int main()
{
  int n;
  string x;
  cin >> n;
  getline(cin, x);
  for (int i = 0; i < n; i++)
  {
    getline(cin, x);
    if (x.empty())
      cout << "Yes" << endl;
    else
    {
      if (func(x))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }

  return 0;
}