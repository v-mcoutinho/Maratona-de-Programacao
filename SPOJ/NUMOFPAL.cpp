// Number of Palindromes
// https://www.spoj.com/problems/NUMOFPAL/
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int manacher(string x)
{
  if (x.empty())
    return 0;
  vector<int> LPS(2 * x.length() + 1);
  LPS[0] = 0;
  LPS[1] = 1;
  int cenPos = 1;
  int cenRig = 2;
  int curRig = 0;
  int curLef;
  int maxLPSLength = 0;
  int maxLPSCenPos = 0;
  int diff = -1;
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
      maxLPSLength = LPS[curRig];
      maxLPSCenPos = curRig;
    }
    if (curRig + LPS[curRig] > cenRig)
    {
      cenPos = curRig;
      cenRig = curRig + LPS[curRig];
    }
  }
  int numPal = 0;
  for (int i = 0; i < LPS.size(); i++)
  {
    numPal += LPS[i] / 2 + LPS[i] % 2;
  }
  return numPal;
}

int main()
{
  string S;
  cin >> S;
  cout << manacher(S) << endl;

  return 0;
}