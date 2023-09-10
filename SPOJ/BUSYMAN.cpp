// I AM VERY BUSY
// https://www.spoj.com/problems/BUSYMAN/en/
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
  int a, b;
} times;

bool comp(const times x, times y)
{
  return x.b < y.b;
}

int main()
{
  int t, n, a1, a2, Tmax, sec, Amax, j, h;
  cin >> t;
  while (t--)
  {
    cin >> n;
    vector<times> v;
    for (int i = 0; i < n; i++)
    {
      cin >> a1 >> a2;
      v.push_back({a1, a2});
    }
    sort(v.begin(), v.end(), comp);
    int cont = 1;
    int last = v[0].b;
    for (int i = 1; i < n; i++)
    {
      if (v[i].a >= last)
      {
        last = v[i].b;
        cont++;
      }
    }
    cout << cont << endl;
  }

  return 0;
}