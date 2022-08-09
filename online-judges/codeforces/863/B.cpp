/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 10:10:58
 * Problem: B. Kayaking
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

int n, a[101];

int gogo(int u, int v) {
  int buf[2 * n - 1];
  int idx = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (i == u || i == v) {
      continue;
    }
    buf[idx] = a[i];
    idx++;
  }
  int res = 0;
  for (int i = 1; i < 2 * n - 1; i+=2) {
    res += buf[i] - buf[i-1];
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    std::cin >> a[i];
  }
  std::sort(a, a + 2 * n);
  int ans = 1e9;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < i; j++) {
      ans = std::min(ans, gogo(i, j));
    }
  }
  std::cout << ans << "\n";
  return 0;
}
