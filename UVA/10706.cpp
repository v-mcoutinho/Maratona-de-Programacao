// Number Sequence
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1647
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

int digi(int x)
{
  int aux = 0;
  while (x > 0)
  {
    aux++;
    x /= 10;
  }
  return aux;
}

int main()
{
  long long int n, x, aux1, aux3;
  string aux2;
  vector<long long int> lengs;
  vector<long long int>::iterator itr;
  lengs.push_back(1);
  lengs.push_back(3);
  for (int i = 2; lengs[i - 1] < 2147483648; i++)
  {
    lengs.push_back(lengs[i - 1] + lengs[i - 1] - lengs[i - 2] + digi(i + 1));
  }
  cin >> n;
  while (n--)
  {
    cin >> x;
    itr = lower_bound(lengs.begin(), lengs.end(), x);
    if (x == 1)
      cout << "1" << endl;
    else
    {
      aux1 = *(itr - 1);
      aux3 = 1;
      for (int i = 1; aux3 <= x - aux1; i++)
      {
        aux2 = to_string(i);
        for (int j = 0; j < aux2.length(); j++)
        {
          if (aux3 == x - aux1)
          {
            cout << aux2[j] << endl;
          }
          aux3++;
        }
      }
    }
  }

  return 0;
}