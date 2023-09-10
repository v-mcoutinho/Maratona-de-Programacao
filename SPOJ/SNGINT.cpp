// Encode Integer
// https://www.spoj.com/problems/SNGINT/en/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    if (!n)
      cout << "10" << endl;
    else if (n < 10)
      cout << n << endl;
    else
    {
      string aux = "";
      while (!(n % 2))
      {
        aux += "2";
        n /= 2;
      }
      while (!(n % 3))
      {
        aux += "3";
        n /= 3;
      }
      while (!(n % 5))
      {
        aux += "5";
        n /= 5;
      }
      while (!(n % 7))
      {
        aux += "7";
        n /= 7;
      }
      if (n > 2)
      {
        cout << "-1" << endl;
      }
      else
      {
        string aux2;
        aux2 = aux;
        for (int i = 0; i < aux.size() - 1; i++)
        {
          if (aux[i] == '2')
          {
            if (aux[i + 1] == '2')
            {
              aux[i] = '4';
              aux.erase(aux.begin() + i + 1);
              if (aux[i + 1] == '2')
              {
                aux[i] = '8';
                aux.erase(aux.begin() + i + 1);
              }
            }
            else if (aux[i + 1] == '3')
            {
              aux[i] = '6';
              aux.erase(aux.begin() + i + 1);
            }
          }
          else if (aux[i] == '3')
          {
            if (aux[i + 1] == '3')
            {
              aux[i] = '9';
              aux.erase(aux.begin() + i + 1);
            }
          }
        }
        reverse(aux2.begin(), aux2.end());
        for (int i = 0; i < aux2.size() - 1; i++)
        {
          if (aux2[i] == '2')
          {
            if (aux2[i + 1] == '2')
            {
              aux2[i] = '4';
              aux2.erase(aux2.begin() + i + 1);
              if (aux2[i + 1] == '2')
              {
                aux2[i] = '8';
                aux2.erase(aux2.begin() + i + 1);
              }
            }
          }
          else if (aux2[i] == '3')
          {
            if (aux2[i + 1] == '3')
            {
              aux2[i] = '9';
              aux2.erase(aux2.begin() + i + 1);
            }
            else if (aux2[i + 1] == '2')
            {
              aux2[i] = '6';
              aux2.erase(aux2.begin() + i + 1);
            }
          }
        }
        sort(aux.begin(), aux.end());
        sort(aux2.begin(), aux2.end());
        if (aux < aux2)
          cout << aux << endl;
        else
          cout << aux2 << endl;
      }
    }
  }

  return 0;
}