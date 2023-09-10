// Making Jumps
// https://www.spoj.com/problems/MKJUMPS/en/
#include <iostream>
#include <vector>

using namespace std;

int maxim;

bool poss_valid(int x, int y, vector<vector<int>> &v)
{
  if (x < 0 || x > 9 || y < 0 || y > 9)
    return false;
  if (v[x][y] == 0 || v[x][y] == 2)
    return false;
  return true;
}

void func(vector<vector<int>> &v, int x, int y, int aux)
{
  aux += 1;
  v[x][y] = 2;
  if (poss_valid(x - 2, y - 1, v))
  {
    func(v, x - 2, y - 1, aux);
  }
  if (poss_valid(x - 2, y + 1, v))
  {
    func(v, x - 2, y + 1, aux);
  }
  if (poss_valid(x - 1, y - 2, v))
  {
    func(v, x - 1, y - 2, aux);
  }
  if (poss_valid(x - 1, y + 2, v))
  {
    func(v, x - 1, y + 2, aux);
  }
  if (poss_valid(x + 1, y - 2, v))
  {
    func(v, x + 1, y - 2, aux);
  }
  if (poss_valid(x + 1, y + 2, v))
  {
    func(v, x + 1, y + 2, aux);
  }
  if (poss_valid(x + 2, y - 1, v))
  {
    func(v, x + 2, y - 1, aux);
  }
  if (poss_valid(x + 2, y + 1, v))
  {
    func(v, x + 2, y + 1, aux);
  }
  v[x][y] = 1;
  if (aux > maxim)
    maxim = aux;
}

int main()
{
  int n, jum, squa, possible_spaces, start;
  for (int i = 1;; i++)
  {
    cin >> n;
    if (!n)
      break;
    vector<vector<int>> table(10, vector<int>(10, 0));
    possible_spaces = 0;
    maxim = 0;
    for (int j = 0; j < n; j++)
    {
      cin >> jum >> squa;
      if (!j)
        start = jum;
      possible_spaces += squa;
      for (int k = jum; k < squa + jum; k++)
        table[j][k] = 1;
    }
    func(table, start, 0, 0);
    cout << "Case " << i << ", " << possible_spaces - maxim << " square";
    if (possible_spaces - maxim != 1)
      cout << "s";
    cout << " can not be reached." << endl;
  }

  return 0;
}