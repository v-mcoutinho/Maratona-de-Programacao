// Pérolas
// https://www.beecrowd.com.br/repository/UOJ_1975.html
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int main()
{
  int p, a, r, max;
  string nomeaux, nomeaux2;
  while (true)
  {
    cin >> p >> a >> r;
    if (!p && !a && !r)
      break;
    map<string, int> pero;
    getline(cin, nomeaux);
    for (int i = 0; i < p; i++)
    {
      getline(cin, nomeaux);
      pero.insert({nomeaux, 0});
    }
    map<string, int> nome;
    map<string, int>::iterator itr;
    for (int i = 0; i < a; i++)
    {
      getline(cin, nomeaux);
      nome.insert({nomeaux, 0});
      max = 0;
      for (int j = 0; j < r; j++)
      {
        getline(cin, nomeaux2);
        if (pero.count(nomeaux2) > 0)
        {
          max++;
        }
        if (max > nome[nomeaux])
          nome[nomeaux] = max;
      }
    }
    max = 0;
    for (itr = nome.begin(); itr != nome.end(); itr++)
    {
      if (max < itr->second)
        max = itr->second;
    }
    vector<string> maiores;
    for (itr = nome.begin(); itr != nome.end(); itr++)
    {
      if (itr->second == max)
      {
        maiores.push_back(itr->first);
      }
    }
    for (int i = 0; i < maiores.size(); i++)
    {
      cout << maiores[i];
      if (i != maiores.size() - 1)
        cout << ", ";
      else
        cout << endl;
    }
  }

  return 0;
}