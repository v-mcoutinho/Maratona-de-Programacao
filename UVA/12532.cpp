// Interval Product
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3977
#include <bits/stdc++.h>

using namespace std;

void build(vector<int> &X, int n)
{
  int aux;
  for (int i = n - 1; i > 0; i--)
  {
    aux = X[2 * i] * X[2 * i + 1];
    if (aux > 0)
      X[i] = 1;
    else if (aux < 0)
      X[i] = -1;
    else
      X[i] = 0;
  }
}

void update(vector<int> &X, int n, int place, int value)
{
  int aux;
  X[place + n] = value;
  for (int i = (place + n) / 2; i > 0; i /= 2)
  {
    aux = X[2 * i] * X[2 * i + 1];
    if (aux > 0)
      X[i] = 1;
    else if (aux < 0)
      X[i] = -1;
    else
      X[i] = 0;
  }
}

int operation(vector<int> &X, int n, int l, int r)
{
  int aux = 1;
  for (l = l + n, r = r + n; l < r; l /= 2, r /= 2)
  {
    if (l % 2)
    {
      aux *= X[l];
      l++;
    }
    if (r % 2)
    {
      r--;
      aux *= X[r];
    }
  }
  return aux;
}

int main()
{
  int n, k, I, V, aux;
  char c;
  queue<char> qu;
  while (cin >> n >> k)
  {
    vector<int> X(2 * n + 1);
    for (int i = 0; i < n; i++)
    {
      cin >> X[i + n];
    }
    build(X, n);
    while (k--)
    {
      cin >> c;
      if (c == 'C')
      {
        cin >> I >> V;
        update(X, n, I - 1, V);
      }
      else if (c == 'P')
      {
        cin >> I >> V;
        aux = operation(X, n, I - 1, V);
        if (aux > 0)
          qu.push('+');
        else if (aux < 0)
          qu.push('-');
        else
          qu.push('0');
      }
    }
    while (!qu.empty())
    {
      cout << qu.front();
      qu.pop();
    }
    cout << endl;
  }

  return 0;
}