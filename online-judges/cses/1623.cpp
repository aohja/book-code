/**
 * Author:  Aadi Ohja
 * Created: 06/08/2022 19:02:55
 * Problem: Apple Division
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

int n;
ll p[21];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
  }
  ll ans = 1e18;
  for (int i = 0; i < (1 << n); i++) {
    ll x = 0, y = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        x += p[j];
      } else {
        y += p[j];
      }
    }
    ans = std::min(ans, llabs(x - y));
  }
  std::cout << ans << "\n";
  return 0;
}
