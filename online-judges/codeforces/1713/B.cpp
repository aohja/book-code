/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 17:07:35
 * Problem: B. Optimal Reduction
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
int n, a[100001];

void sol() {
  std::cin >> n;
  std::multiset<int> s;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
  }
  int l = 0, r = n - 1;
  while (l <= r) {
    int x = *(s.begin());
    if (a[l] == x) {
      l++;
    } else if (a[r] == x) {
      r--;
    } else {
      std::cout << "NO\n";
      return;
    }
    s.erase(s.begin());
  }
  std::cout << "YES\n";
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
