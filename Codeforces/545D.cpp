// Queue
// https://codeforces.com/problemset/problem/545/D
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  vector<int> v;
  int n, x;
  cin >> n;
  v.reserve(n);
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int cont = 0, time = 0;
  for (int i = 0; i < n; i++)
  {
    if (v[i] >= time)
    {
      cont++;
      time += v[i];
    }
  }
  cout << cont << endl;

  return 0;
}