/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 17:07:35
 * Problem: C. Build Permutation
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
ll n, a[100005];

ll find(int x) {
  ll i = 0;
  while (i * i < x) {
    i++;
  }
  return i * i;
}

void sol() {
  std::cin >> n;
  ll x = n - 1;
  while (x >= 0) {
    ll y = find(x);
    int idx = y - x;
    int stop = x;
    for (int i = idx; i <= stop; i++) {
      a[i] = x;
      x--;
    }
  }
  for (int i = 0; i < n; i++) {
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
