// Ada and Queue
// https://www.spoj.com/problems/ADAQUEUE/en/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q, k;
  string s;
  deque<int> deck;
  cin >> q >> ws;
  bool flag = 0;
  while (q--)
  {
    cin >> s;
    if ((s == "toFront" && flag) || (s == "push_back" && !flag))
    {
      cin >> k >> ws;
      deck.push_back(k);
    }
    else if ((s == "push_back" && flag) || (s == "toFront" && !flag))
    {
      cin >> k >> ws;
      deck.push_front(k);
    }
    else if ((s == "front" && flag) || (s == "back" && !flag))
    {
      if (deck.empty())
        cout << "No job for Ada?\n";
      else
      {
        cout << deck.back() << endl;
        deck.pop_back();
      }
    }
    else if ((s == "back" && flag) || (s == "front" && !flag))
    {
      if (deck.empty())
        cout << "No job for Ada?\n";
      else
      {
        cout << deck.front() << endl;
        deck.pop_front();
      }
    }
    else if (s == "reverse")
    {
      flag = !flag;
    }
  }

  return 0;
}