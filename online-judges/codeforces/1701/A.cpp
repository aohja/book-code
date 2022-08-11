/**
 * Author:  Aadi Ohja
 * Created: 10/08/2022 08:15:29
 * Problem: A. Grass Field
**/
#include <bits/stdc++.h>
#define For(i, x, y) for (int i = (int) x; i < (int) y; i++) 
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

#ifdef LOCAL
#include "ddebug.h"
#else
#define debug(...) 42
#endif

int T;
int a[4];

void sol() {
  int cnt = 0;
  For(i, 0, 4) {
    std::cin >> a[i];
    if (a[i] == 1) {
      cnt++;
    }
  }
  if (cnt == 0) {
    std::cout << 0 << "\n";
  } else if (cnt == 4) {
    std::cout << 2 << "\n";
  } else {
    std::cout << 1 << "\n";
  }
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
