// Eachianos I
// https://www.beecrowd.com.br/repository/UOJ_2593.html
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <cctype>

using namespace std;

void show(vector<int> &x)
{
  for (int i = 0; i < x.size(); i++)
  {
    cout << x[i];
    if (i != x.size() - 1)
      cout << " ";
  }
}

int main()
{
  string line, word, word2;
  int num, i;
  map<string, vector<int>> list;
  map<string, vector<int>>::iterator itr;
  getline(cin, line);
  for (i = 0; i < line.length(); i++)
  {
    if (isalpha(line[i]))
    {
      word += line[i];
    }
    else
    {
      list[word].push_back(i - word.length());
      word.clear();
    }
  }
  if (!word.empty())
  {
    list[word].push_back(line.length() - word.length());
    word.clear();
  }
  cin >> num;
  for (int i = 0; i < num; i++)
  {
    cin >> word2;
    if (list.count(word2) > 0)
    {
      show(list[word2]);
      cout << endl;
    }
    else
    {
      cout << "-1" << endl;
    }
  }

  return 0;
}