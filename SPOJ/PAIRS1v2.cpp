// Count the Pairs
// https://www.spoj.com/problems/PAIRS1/en/
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, K, count = 0;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      if (a[i] == a[j] - abs(K))
      {
        count++;
        break;
      }
      else if (a[j] - abs(K) > a[i])
      {
        break;
      }
    }
  }
  cout << count << endl;

  return 0;
}