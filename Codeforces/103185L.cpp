// Lola's Schedule
// https://codeforces.com/gym/103185/problem/L
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x, s, d, t, c = INT_MAX;
  vector<int> act(200001, 0), con(200001); // s + d <= 2 * 100000
  cin >> n >> x;
  while (n--)
  {
    cin >> s >> d;
    for (int i = s; i <= s + d; i++)
      act[i] = 1;
  }
  for (int i = 200000; i >= 0; i--)
  {
    if (i + x > 200000)
      con[i] = 0;
    else
      con[i] = con[i + x];
    if (act[i])
      con[i]++;
    if (i <= 480)
    { // Antes de 8 horas
      if (con[i] <= c)
      {
        c = con[i];
        t = i;
      }
    }
  }
  cout << t << " " << c << endl;

  return 0;
}