// Pontos de Feno
// https://www.beecrowd.com.br/repository/UOJ_1261.html
#include <iostream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main()
{
  string aux, line;
  map<string, int> list;
  map<string, int>::iterator itr;
  int m, n, x, dot = 0, soma = 0;
  cin >> m >> n;
  while (m--)
  {
    cin >> aux >> x;
    list.insert(pair<string, int>(aux, x));
  }
  while (dot < n)
  {
    cin >> line;
    if (line == ".")
    {
      cout << soma << endl;
      soma = 0;
      dot++;
    }
    else
    {
      itr = list.find(line);
      if (itr != list.end())
        soma += itr->second;
    }
  }

  return 0;
}