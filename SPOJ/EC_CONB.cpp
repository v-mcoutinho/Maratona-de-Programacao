// Even Numbers
// https://www.spoj.com/problems/EC_CONB/en/
#include <iostream>

using namespace std;

unsigned int reverse_bits(unsigned int a)
{
  unsigned int b = 0;
  while (a)
  {
    b = b << 1;
    if ((a & 1) == 1)
      b = b ^ 1;
    a = a >> 1;
  }
  return b;
}

int main()
{
  int n;
  unsigned int a;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if (a % 2 == 0)
      cout << reverse_bits(a) << endl;
    else
      cout << a << endl;
  }

  return 0;
}
