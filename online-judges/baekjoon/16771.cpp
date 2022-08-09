/**
 * Author:  Aadi Ohja
 * Created: 08/08/2022 17:24:20
 * Problem: Back and Forth
**/
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

#ifdef LOCAL
#include "ddebug.h"
#else
#define debug(...) 42
#endif

int buc[20], where[20];
std::map<int, int> mp;

void sim(int day, int a, int b) {
  if (day ==  4) {
    mp[a]++;
  } else {
    for (int i = 0; i < 20; i++) {
      if (day & 1) {
        if (where[i] == 1) {
          where[i] = 0;
          sim(day + 1, a - buc[i], b + buc[i]);
          where[i] = 1;
        }
      } else {
        if (where[i] == 0) {
          where[i] = 1;
          sim(day + 1, a + buc[i], b - buc[i]);
          where[i] = 0;
        }
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  for (int i = 0; i < 20; i++) {
    std::cin >> buc[i];
    where[i] = (i < 10 ? 0 : 1);
  }
  sim(0, 1000, 1000);
  std::cout << (int) mp.size() << "\n";
  return 0;
}
