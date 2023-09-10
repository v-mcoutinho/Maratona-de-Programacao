// Longest Common Subsequence
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1346
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int lcs(string a, string b)
{
  vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1));
  for (int i = 0; i <= a.length(); i++)
  {
    for (int j = 0; j <= b.length(); j++)
    {
      if (!i || !j)
      {
        dp[i][j] = 0;
      }
      else if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[a.length()][b.length()];
}

int main()
{
  string a, b;
  while (getline(cin, a))
  {
    getline(cin, b);
    cout << lcs(a, b) << endl;
  }

  return 0;
}