// A problem of Backtracking
// https://www.spoj.com/problems/BTCK/en/
#include <bits/stdc++.h>

using namespace std;

bool veri(vector<int> &lido, vector<int> &v, int k)
{
  long long int aux = 0;
  for (int i = 0; i < 10; i++)
    aux += lido[i] * v[i];
  if (aux > k)
    return false;
  return true;
}

bool conti(vector<int> &v)
{
  for (int i = 0; i < 10; i++)
    if (v[i] != i)
      return true;
  return false;
}

bool is_possible(vector<int> &lido, vector<int> &v, int k)
{
  do
  {
    if (veri(lido, v, k))
      return true;
    next_permutation(v.begin(), v.end());
  } while (conti(v));
  return false;
}

void show(vector<int> &v)
{
  for (int i = 0; i < 9; i++)
    cout << v[i] << " ";
  cout << v[9] << endl;
}

int main()
{
  int n, k;
  vector<int> v(10), lido(10);
  cin >> n;
  while (n--)
  {
    for (int i = 0; i < 10; i++)
    {
      cin >> lido[i];
      v[i] = i;
    }
    cin >> k;
    if (is_possible(lido, v, k))
    {
      show(v);
    }
    else
    {
      cout << "-1" << endl;
    }
  }

  return 0;
}