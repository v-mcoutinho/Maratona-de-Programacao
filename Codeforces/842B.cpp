// Gleb And Pizza
// https://codeforces.com/problemset/problem/842/B
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int r, d, n, cont = 0, x, y, R;
  double a;
  cin >> r >> d >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y >> R;
    a = sqrt(pow(x, 2) + pow(y, 2));
    if (a - R >= r - d && a + R <= r)
    {
      cont++;
    }
  }
  cout << cont << endl;

  return 0;
}