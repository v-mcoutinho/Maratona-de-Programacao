// String Tale
// https://acm.timus.ru/problem.aspx?space=1&num=1423
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

int KMPSearch(string pat, string txt, int n)
{
  int N = 2 * n;
  vector<int> lps(n);
  computeLPSArray(pat, n, lps);
  txt.append(txt);
  int i = 0;
  int j = 0;
  while (i < N)
  {
    if (pat[j] == txt[i])
    {
      j++;
      i++;
    }
    if (j == n)
    {
      return i - j;
      j = lps[j - 1];
    }
    else if (i < N && pat[j] != txt[i])
    {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
  return -1;
}

int main()
{
  int n;
  string s, t;
  cin >> n;
  cin >> s >> t;
  cout << KMPSearch(s, t, n) << endl;

  return 0;
}