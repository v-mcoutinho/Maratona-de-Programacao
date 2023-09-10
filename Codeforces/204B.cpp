// Little Elephant and Cards
// https://codeforces.com/problemset/problem/204/B
#include <iostream>
#include <utility>
#include <map>
#include <iterator>

using namespace std;

int cards(map<int, pair<long long int, long long int>> &front, int n)
{
  map<int, pair<long long int, long long int>>::iterator itr;
  int half = n / 2, min = -1;
  bool flag = false;
  if (n % 2 != 0)
    half++;
  for (itr = front.begin(); itr != front.end(); ++itr)
  {
    if (itr->second.first >= half)
      return 0;
    if (itr->second.first + itr->second.second >= half)
    {
      if (!flag)
      {
        flag = true;
        min = half - itr->second.first;
      }
      else
      {
        if (min > half - itr->second.first)
          min = half - itr->second.first;
      }
    }
  }
  return min;
}

int main()
{
  int n, front, back;
  cin >> n;
  map<int, pair<long long int, long long int>> frontMap;
  map<int, pair<long long int, long long int>>::iterator itr;
  for (int i = 0; i < n; i++)
  {
    cin >> front >> back;
    if (front != back)
    {
      if (frontMap.count(front) > 0)
      {
        frontMap[front].first = frontMap[front].first + 1;
      }
      else
      {
        frontMap[front].first = 1;
      }
      if (frontMap.count(back) > 0)
      {
        frontMap[back].second = frontMap[back].second + 1;
      }
      else
      {
        frontMap[back].second = 1;
      }
    }
    else
    {
      if (frontMap.count(front) > 0)
      {
        frontMap[front].first = frontMap[front].first + 1;
      }
      else
      {
        frontMap[front].first = 1;
      }
    }
  }
  cout << cards(frontMap, n) << endl;

  return 0;
}