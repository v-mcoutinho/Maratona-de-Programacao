// Triple Fat Ladies
// https://www.spoj.com/problems/EIGHTS/en/
#include <iostream>

using namespace std;

int main()
{
  long long int n, k;
  cin >> n;
  for (long long int i = 0; i < n; i++)
  {
    cin >> k;
    cout << (k - 1) * 250 + 192 << endl;
  }

  return 0;
}