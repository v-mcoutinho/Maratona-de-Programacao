// DNA Sorting
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=553
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int func(string x)
{
  int a = 0, c = 0, g = 0, t = 0, dif = 0;
  for (int i = x.length() - 1; i >= 0; i--)
  {
    switch (x[i])
    {
    case 'T':
      dif += a + c + g;
      t++;
      break;
    case 'G':
      dif += a + c;
      g++;
      break;
    case 'C':
      dif += a;
      c++;
      break;
    case 'A':
      a++;
      break;
    }
  }
  return dif;
}

int main()
{
  int M, n, m;
  cin >> M;
  for (int zx = 0; zx < M; zx++)
  {
    cin >> n >> m;
    vector<string> dna(m);
    multimap<int, int> strands;
    multimap<int, int>::iterator itr;
    for (int i = 0; i < m; i++)
    {
      cin >> dna[i];
      strands.insert({func(dna[i]), i});
    }
    for (itr = strands.begin(); itr != strands.end(); itr++)
    {
      cout << dna[itr->second] << endl;
    }
    if (zx != M - 1)
      cout << endl;
  }

  return 0;
}
