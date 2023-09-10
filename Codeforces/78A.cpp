// Haiku
// https://codeforces.com/problemset/problem/78/A
#include <bits/stdc++.h>

using namespace std;

bool vog(char x)
{
  if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
    return true;
  return false;
}

bool func(string s[])
{
  int vogal;
  vogal = 0;
  for (int i = 0; i < s[0].size(); i++)
  {
    if (vog(s[0][i]))
      vogal++;
    if (vogal > 5)
      return false;
  }
  if (vogal != 5)
    return false;
  vogal = 0;
  for (int i = 0; i < s[1].size(); i++)
  {
    if (vog(s[1][i]))
      vogal++;
    if (vogal > 7)
      return false;
  }
  if (vogal != 7)
    return false;
  vogal = 0;
  for (int i = 0; i < s[2].size(); i++)
  {
    if (vog(s[2][i]))
      vogal++;
    if (vogal > 5)
      return false;
  }
  if (vogal != 5)
    return false;
  return true;
}

int main()
{
  string s[3];
  getline(cin, s[0]);
  getline(cin, s[1]);
  getline(cin, s[2]);
  if (func(s))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}