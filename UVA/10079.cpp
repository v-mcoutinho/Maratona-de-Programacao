// Pizza Cutting
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1020
#include <iostream>

using namespace std;

int main()
{
  int n;
  long long int cont;
  while (true)
  {
    cin >> n;
    if (n < 0)
      break;
    cont = 1;
    for (int i = 1; i <= n; i++)
    {
      cont += i;
    }
    cout << cont << endl;
  }

  return 0;
}