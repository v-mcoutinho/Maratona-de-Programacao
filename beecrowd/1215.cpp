// Primeiro Dicionário de Andy
// https://www.beecrowd.com.br/repository/UOJ_1215.html
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <utility>
#include <cctype>

using namespace std;

int main()
{
  string line, word;
  map<string, int> resul;
  map<string, int>::iterator itr;
  while (true)
  {
    getline(cin, line);
    word.clear();
    for (int i = 0; i < line.length(); i++)
    {
      if (line[i] >= 'a' && line[i] <= 'z')
      {
        word += line[i];
      }
      else if (line[i] >= 'A' && line[i] <= 'Z')
      {
        word += tolower(line[i]);
      }
      else
      {
        if (!word.empty())
        {
          resul.insert({word, 1});
          word.clear();
        }
      }
    }
    if (!word.empty())
    {
      resul.insert({word, 1});
      word.clear();
    }
    if (cin.eof())
      break;
  }
  for (itr = resul.begin(); itr != resul.end(); itr++)
  {
    cout << itr->first << endl;
  }

  return 0;
}