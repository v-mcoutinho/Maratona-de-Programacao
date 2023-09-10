// Password
// https://codeforces.com/problemset/problem/126/B
#include <bits/stdc++.h>

using namespace std;

void computeLPSArray(string pat, int n, vector<int> &lps)
{
  int len = 0;
  lps[0] = 0;
  int i = 1;
  while (i < n)
  {
    if (pat[i] == pat[len])
    {
      len++;
      lps[i] = len;
      i++;
    }
    else
    {
      if (len != 0)
      {
        len = lps[len - 1];
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}

int func(vector<int> &lps, int n)
{
  if (!lps[n - 1])
    return -1;
  for (int i = 0; i < n - 1; i++)
  {
    if (lps[i] == lps[n - 1])
      return i;
  }
  if (lps[lps[n - 1] - 1])
    return lps[n - 1] - 1;
  return -1;
}

int main()
{
  string s;
  int aux;
  cin >> s;
  int n = s.size();
  vector<int> lps(n);
  computeLPSArray(s, n, lps);
  aux = func(lps, n);
  if (aux != -1)
  {
    cout << s.substr(aux - lps[aux] + 1, lps[aux]) << endl;
  }
  else
  {
    cout << "Just a legend" << endl;
  }

  return 0;
}