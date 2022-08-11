/**
 * Author:  Aadi Ohja
 * Created: 10/08/2022 08:15:29
 * Problem: B. Permutation
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
int n, a[200005];

void sol() {
  std::cin >> n;
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  int idx = 0;
  while (sz(s) != 0) {
    int x = *(s.begin());
    for (int i = 0; x <= n; i++) {
      a[idx] = x;
      s.erase(x);
      x *= 2; idx++;
    }
  }
  std::cout << 2 << "\n";
  For(i, 0, n) {
    std::cout << a[i] << (i == n - 1 ? "\n" : " ");
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
