// Colourful Flowers
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2093
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
  double a, b, c;
  while (cin >> a >> b >> c)
  {
    double T = 0, C1 = 0, C2 = 0, p, r1, r2;
    p = (a + b + c) / 2.0;
    T = sqrt(p * (p - a) * (p - b) * (p - c));
    r2 = T / p;
    C2 = pow(r2, 2) * M_PI;
    r1 = (a * b * c) / (4 * T);
    C1 = pow(r1, 2) * M_PI;
    C1 -= T;
    T -= C2;
    cout << setprecision(4) << fixed << C1 << " " << T << " " << C2 << endl;
  }

  return 0;
}
