// The Festive Evening
// https://codeforces.com/problemset/problem/834/B
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

bool func(vector<int> &guests, vector<int> &numguests, vector<bool> &guarded, int k)
{
  int aux;
  for (int i = 0; i < guests.size(); i++)
  {
    aux = guests[i];
    if (!guarded[aux])
    {
      if (!k)
        return false;
      k--;
      guarded[aux] = true;
    }
    numguests[aux]--;
    if (!numguests[aux])
    {
      guarded[aux] = false;
      k++;
    }
  }
  return true;
}

int main()
{
  int n, k, intaux;
  cin >> n >> k;
  vector<int> guests(n), numguests(26, 0);
  vector<bool> guarded(26, false);
  char chaux;
  if (k == 26 || k >= n)
    cout << "NO" << endl;
  else
  {
    for (int i = 0; i < n; i++)
    {
      cin >> chaux;
      intaux = chaux - 'A';
      numguests[intaux]++;
      guests[i] = intaux;
    }
    if (func(guests, numguests, guarded, k))
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
    }
  }

  return 0;
}