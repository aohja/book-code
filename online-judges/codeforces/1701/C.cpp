/**
 * Author:  Aadi Ohja
 * Created: 10/08/2022 08:15:29
 * Problem: C. Schedule Management
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
int n, m, a[200005];

void sol() {
  std::cin >> n >> m;
  std::map<int, int> mp;
  For(i, 0, m) {
    std::cin >> a[i];
    mp[a[i]]++;
  }
  std::multiset<int> ms;
  for (int i = 1; i <= n; i++) {
    ms.insert(mp[i]);
  }
  while (true) {
    int mn = *(ms.begin()), mx = *(ms.rbegin());
    debug(mn, mx);
    if (mx - mn <= 2) {
      std::cout << mx << "\n";
      return;
    } else {
      ms.erase(ms.begin());
      ms.erase(ms.lower_bound(mx));
      mx--; mn+=2;
      ms.insert(mn); ms.insert(mx);
    }
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
