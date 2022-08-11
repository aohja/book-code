/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 17:07:35
 * Problem: A. Traveling Salesman Problem
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

int T;
int n, x[101], y[101];

void sol() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  int min_x = 0, min_y = 0, max_x = 0, max_y = 0;
  for (int i = 0; i < n; i++) {
    min_x = std::min(min_x, x[i]);
    max_x = std::max(max_x, x[i]);
    min_y = std::min(min_y, y[i]);
    max_y = std::max(max_y, y[i]);
  }
  int res = 0;
  if (min_x < 0) {
    res += -2 * min_x;
  } 
  if (max_x > 0) {
    res += 2 * max_x;
  }
  if (min_y < 0) {
    res += -2 * min_y;
  }
  if (max_y > 0) {
    res += 2 * max_y;
  }
  std::cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> T;
  for (int i = 0; i < T; i++) {
    sol();
  }
  return 0;
}
