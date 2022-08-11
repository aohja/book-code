/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 20:58:53
 * Problem: Sum of Two Values
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

int n, x;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> x;
  std::map<int, int> mp;
  bool ok = false;
  int a, b;
  for (int i = 0; i < n; i++) {
    int y;
    std::cin >> y;
    if (mp.count(x - y)) {
      ok = true;
      a = mp[x - y];
      b = i;
    }
    mp[y] = i;
  }
  if (ok) {
    std::cout << a + 1 << " " << b + 1 << "\n";
  } else {
    std::cout << "IMPOSSIBLE\n";
  }
  return 0;
}
