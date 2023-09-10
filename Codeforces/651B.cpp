// Beautiful Paintings
// https://codeforces.com/problemset/problem/651/B
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
  int n;
  cin >> n;
  vector<int> PAINtings(n);
  for (int i = 0; i < n; i++)
  {
    cin >> PAINtings[i];
  }
  sort(PAINtings.begin(), PAINtings.end());
  vector<bool> picked(n, false);
  int cont = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (PAINtings[j] > PAINtings[i] && !picked[j])
      {
        picked[j] = true;
        cont++;
        break;
      }
    }
  }
  cout << cont << endl;

  return 0;
}
