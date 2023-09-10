// Mirror Strings !!!
// https://www.spoj.com/problems/MSUBSTR/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> manacher(string x)
{
  if (x.empty())
    return {0, 0};
  if (x.length() == 1)
  {
    return {1, 1};
  }
  vector<int> LPS(2 * x.length() + 1);
  LPS[0] = 0;
  LPS[1] = 1;
  int cenPos = 1;
  int cenRig = 2;
  int curRig = 0;
  int curLef;
  int maxLPSLength = 1;
  int maxLPSCenPos = 0;
  int diff = -1;
  int maxNumPals = 1;
  for (curRig = 2; curRig <= 2 * x.length(); curRig++)
  {
    curLef = 2 * cenPos - curRig;
    LPS[curRig] = 0;
    diff = cenRig - curRig;
    if (diff > 0)
    {
      LPS[curRig] = min(LPS[curLef], diff);
    }
    while (((curRig + LPS[curRig]) <= 2 * x.length() && (curRig - LPS[curRig]) > 0) &&
           (((curRig + LPS[curRig] + 1) % 2 == 0) ||
            (x[(curRig + LPS[curRig] + 1) / 2] == x[(curRig - LPS[curRig] - 1) / 2])))
    {
      LPS[curRig]++;
    }
    if (LPS[curRig] > maxLPSLength)
    {
      maxNumPals = 1;
      maxLPSLength = LPS[curRig];
      maxLPSCenPos = curRig;
    }
    else if (LPS[curRig] == maxLPSLength)
    {
      maxNumPals++;
    }
    if (curRig + LPS[curRig] > cenRig)
    {
      cenPos = curRig;
      cenRig = curRig + LPS[curRig];
    }
  }
  return {maxLPSLength, maxNumPals};
}

int main()
{
  int n;
  string st;
  cin >> n;
  while (n--)
  {
    cin >> st;
    pair<int, int> x;
    x = manacher(st);
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}