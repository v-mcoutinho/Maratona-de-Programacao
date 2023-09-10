// Game
// https://codeforces.com/problemset/problem/984/A
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, x;
  vector<int> game;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    game.push_back(x);
  }
  sort(game.begin(), game.end());
  if (n % 2)
    cout << game[n / 2] << endl;
  else
    cout << game[n / 2 - 1] << endl;

  return 0;
}