// Plug-in
// https://codeforces.com/problemset/problem/81/A
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string x;
  cin >> x;
  for (int i = 1; i < x.length(); i++)
  {
    if (x[i] == x[i - 1])
    {
      x.erase(x.begin() + i);
      x.erase(x.begin() + i - 1);
      i -= 3;
      if (i < 0)
        i = 0;
    }
  }
  cout << x << endl;

  return 0;
}