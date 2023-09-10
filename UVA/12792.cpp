// Shuffled Deck
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4657
#include <bits/stdc++.h>

using namespace std;

int teste(int a, int b)
{
  if (b == 0)
    return a;
  return teste(b, a % b);
}

int MO(int A, int N)
{
  if (teste(A, N) != 1)
    return -1;
  int R = 1, K = 1;
  while (K < N)
  {
    R = (R * A) % N;
    if (R == 1)
      return K;
    K++;
  }

  return -1;
}

int main()
{
  int n, t = 0;
  while (true)
  {
    cin >> n;
    if (cin.eof())
      break;
    cout << MO(2, n + 1) << endl;
  }

  return 0;
}