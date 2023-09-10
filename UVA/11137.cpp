// Ingenuous Cubrency
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2078
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  long long int v[10000] = {0};
  int i = 1, cube = 1;
  v[0] = 1;
  while (cube < 10000)
  {
    for (int j = cube; j < 10000; j++)
    {
      v[j] += v[j - cube];
    }
    i++;
    cube = ceil(pow(i, 3));
  }
  int n;
  while (true)
  {
    cin >> n;
    if (cin.eof())
      break;
    cout << v[n] << endl;
  }

  return 0;
}