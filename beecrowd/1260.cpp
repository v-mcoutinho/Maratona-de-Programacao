// Espécies de Madeira
// https://www.beecrowd.com.br/repository/UOJ_1260.html
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <iomanip>

using namespace std;

int main()
{
  int n, h;
  string line;
  cin >> n;
  getline(cin, line);
  getline(cin, line);
  for (int zx = 0; zx < n; zx++)
  {
    map<string, int> arv;
    h = 0;
    while (true)
    {
      getline(cin, line);
      if (line == "" || cin.eof())
        break;
      h++;
      if (arv.count(line) > 0)
      {
        arv[line] += 1;
      }
      else
      {
        arv.insert({line, 1});
      }
    }
    map<string, int>::iterator itr;
    for (itr = arv.begin(); itr != arv.end(); itr++)
    { // xesque? dele
      cout << itr->first << " " << fixed << setprecision(4) << ((itr->second) / (double)h) * 100 << endl;
    }
    if (zx != n - 1)
      cout << endl;
  }

  return 0;
}