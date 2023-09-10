// Cut Ribbon
// https://codeforces.com/problemset/problem/189/A
#include <bits/stdc++.h>

using namespace std;

int func(vector<int> &abc, int n)
{
  int ful;
  vector<int> x;
  bool aux = false, aux2 = false;
  if (n % abc[0] == 0)
    return n / abc[0];
  for (int i = 0;; i++)
  {
    for (int j = 0;; j++)
    {
      for (int k = 0;; k++)
      {
        ful = abc[2] * i + abc[1] * j + abc[0] * k;
        if (ful == n)
        {
          x.push_back(i + j + k);
        }
        else if (ful > n)
        {
          if (!k)
          {
            aux = true;
            if (!j)
              aux2 = true;
          }
          break;
        }
      }
      if (aux)
      {
        aux = false;
        break;
      }
      if (abc[0] == abc[1])
        break;
    }
    if (aux2)
    {
      aux2 = false;
      break;
    }
    if (abc[2] == abc[1])
      break;
  }
  return *max_element(x.begin(), x.end());
}

int main()
{
  int n;
  vector<int> abc(3);
  cin >> n >> abc[0] >> abc[1] >> abc[2];
  sort(abc.begin(), abc.end());
  cout << func(abc, n) << endl;

  return 0;
}