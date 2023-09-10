// Popes
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=898
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  while (true)
  {
    int y, p, max = 0, fyear, lyear, aux;
    cin >> y >> p;
    if (cin.eof())
      break;
    vector<int> x(p);
    for (int i = 0; i < p; i++)
      cin >> x[i];
    for (int i = 0; i < p; i++)
    {
      aux = distance(x.begin() + i, upper_bound(x.begin() + i, x.end(), x[i] + y - 1));
      if (max < aux)
      {
        max = aux;
        fyear = x[i];
        lyear = x[i + aux - 1];
      }
    }
    cout << max << " " << fyear << " " << lyear << endl;
  }

  return 0;
}