/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 10:30:42
 * Problem: Why Cows Crossed the Road 3 
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

int N;
std::vector<std::pair<int, int>> v;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++) {
    std::cin >> v[i].first >> v[i].second;
  }
  std::sort(all(v));
  int t = 0;
  for (int i = 0; i < N; i++) {
    int x = v[i].first, y = v[i].second;
    if (t < x) {
      t = x;
    }
    t += y;
  }
  std::cout << t << "\n";
  return 0;
}
