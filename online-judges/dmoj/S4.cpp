/**
 * Author:  Aadi Ohja
 * Created: 08/08/2022 17:48:25
 * Problem: S4 - Twenty-four
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
bool pos[25];
std::vector<int> a(4);

int parse(int i, int x, int y) {
  if (i == 0) {
    return x + y;
  } else if (i == 1) {
    return x - y;
  } else if (i == 2) {
    return x * y;
  } else {
    return (y != 0 && x % y == 0 ? x / y : 1e9); 
  }
}

void go1() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int x = parse(i, a[0], a[1]);
        if (x == 1e9) {
          continue;
        }
        int y = parse(j, x, a[2]);
        if (y == 1e9) {
          continue;
        }
        int z = parse(k, y, a[3]);
        if (z == 1e9) {
          continue;
        }
        if (0 <= z && z <= 24) {
          pos[z] = 1;
        }
      }
    }
  }
}

void go2() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        int x = parse(i, a[0], a[1]);
        if (x == 1e9) {
          continue;
        }
        int y = parse(j, a[2], a[3]);
        if (y == 1e9) {
          continue;
        }
        int z = parse(k, x, y);
        if (z == 1e9) {
          continue;
        }
        if (z >= 0 && z <= 24) {
          pos[z] = 1;
        }
      }
    }
  }
}

void sol() {
  memset(pos, 0, 25);
  for (int i = 0; i < 4; i++) {
    std::cin >> a[i];
  }
  std::sort(all(a));
  do {
    go1();
    go2();
  } while (std::next_permutation(all(a)));
  int ans = 0;
  for (int i = 0; i <= 24; i++) {
    if (pos[i]) {
      ans = std::max(ans, i);
    }
  }
  std::cout << ans << "\n";
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
