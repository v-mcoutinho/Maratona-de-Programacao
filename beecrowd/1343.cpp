// Runner Pawns
// https://www.beecrowd.com.br/repository/UOJ_1343.html
#include <bits/stdc++.h>

using namespace std;

void func(vector<pair<int, int>> &pawns, int pos, int *minimum, int cont, int turn)
{
  if (pos < 1 || pos > 64)
    return;
  bool isthere = false;
  int aux = -1;
  if (*minimum != 0 && turn > *minimum)
    return;
  if (turn > -1)
  {
    for (int i = 0; i < pawns.size(); i++)
    {
      if (pawns[i].second == 0)
      {
        if (pawns[i].first + turn * 8 > 64)
        {
          if (aux != -1)
            pawns[aux].second = 0;
          return;
        }
        if (pawns[i].first + turn * 8 == pos - 8)
        {
          if (aux != -1)
            pawns[aux].second = 0;
          return;
        }
        if (pawns[i].first + turn * 8 == pos)
        {
          pawns[i].second = 1;
          aux = i;
        }
        else
          isthere = true;
      }
    }
  }
  if (!isthere && turn > -1)
  {
    if (*minimum == 0)
      *minimum = cont;
    else
      *minimum = min(*minimum, cont);
    if (aux != -1)
      pawns[aux].second = 0;
    return;
  }
  if (pos > 16 && pos % 8 != 1)
    func(pawns, pos - 17, minimum, cont + 1, turn + 1);
  if (pos > 16 && pos % 8 != 0)
    func(pawns, pos - 15, minimum, cont + 1, turn + 1);
  if (pos > 8 && pos % 8 != 1 && pos % 8 != 2)
    func(pawns, pos - 10, minimum, cont + 1, turn + 1);
  if (pos > 8 && pos % 8 != 0 && pos % 8 != 7)
    func(pawns, pos - 6, minimum, cont + 1, turn + 1);
  if (pos < 57 && pos % 8 != 1 && pos % 8 != 2)
    func(pawns, pos + 6, minimum, cont + 1, turn + 1);
  if (pos < 57 && pos % 8 != 0 && pos % 8 != 7)
    func(pawns, pos + 10, minimum, cont + 1, turn + 1);
  if (pos < 49 && pos % 8 != 1)
    func(pawns, pos + 15, minimum, cont + 1, turn + 1);
  if (pos < 49 && pos % 8 != 0)
    func(pawns, pos + 17, minimum, cont + 1, turn + 1);
  if (aux != -1)
    pawns[aux].second = 0;
}

int main()
{
  int p, h;
  while (true)
  {
    cin >> p;
    if (!p)
      break;
    vector<pair<int, int>> pawns(p);
    for (int i = 0; i < p; i++)
    {
      cin >> pawns[i].first;
      pawns[i].second = 0;
    }
    cin >> h;
    int minimum = 0;
    func(pawns, h, &minimum, 0, -1);
    if (!minimum)
      cout << "impossible" << endl;
    else
      cout << minimum << endl;
  }

  return 0;
}