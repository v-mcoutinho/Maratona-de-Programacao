// T-primes
// https://codeforces.com/problemset/problem/230/B
#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long int x)
{
  if (x < 2)
    return false;
  if (x == 2)
    return true;
  for (int i = 2; i <= floor(sqrt(x)); i++)
  {
    if (x % i == 0)
      return false;
  }
  return true;
}

int main()
{
  int n;
  long long int x;
  cin >> n;
  map<long long int, string> check;
  while (n--)
  {
    cin >> x;
    if (check.count(x))
    {
      cout << check[x];
    }
    else
    {
      if (sqrt(x) == floor(sqrt(x)))
      {
        if (isPrime(sqrt(x)))
        {
          check.insert({x, "YES"});
          cout << "YES";
        }
        else
        {
          check.insert({x, "NO"});
          cout << "NO";
        }
      }
      else
      {
        check.insert({x, "NO"});
        cout << "NO";
      }
    }
    cout << endl;
  }

  return 0;
}