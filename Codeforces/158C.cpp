// Cd and pwd commands
// https://codeforces.com/problemset/problem/158/C
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int t;
  string x = "/", com;
  cin >> t;
  while (t--)
  {
    cin >> com;
    if (com == "pwd")
    {
      cout << x << endl;
    }
    else if (com == "cd")
    {
      string aux;
      cin >> aux;
      if (aux[0] == '/')
        x.clear();
      int i = 0;
      while (i <= aux.length())
      {
        if (aux[i] == '.')
        {
          int j = x.length() - 2;
          while (x[j] != '/' && j >= 0)
            j--;
          x.erase(x.begin() + j + 1, x.end());
          while (aux[i] != '/' && i < aux.length())
            i++;
        }
        else
        {
          int j = i;
          while (aux[j] != '/' && j < aux.length())
            j++;
          j = j - i;
          x = x + aux.substr(i, j + 1);
          while (aux[i] != '/' && i < aux.length())
            i++;
        }
        i++;
      }
      if (x[x.length() - 1] != '/')
        x = x + "/";
    }
  }

  return 0;
}