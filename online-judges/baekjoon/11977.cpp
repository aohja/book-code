/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 10:47:26
 * Problem: Angry Cows (Bronze) 
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

int N, a[101];

int sim(int idx) {
  int res = 1;
  int l = idx, r = idx;
  for (int t = 1; t <= N; t++) {
    int ls = l;
    bool ok = false;
    for (int i = ls - 1; i >= 0; i--) {
      if (a[ls] - a[i] <= t) {
        res++;
        l = i;
        ok = true;
      } else {
        break;
      }
    }
    if (!ok) {
      break;
    }
  }
  for (int t = 1; t <= N; t++) {
    int rs = r;
    bool ok = false;
    for (int i = rs + 1; i < N; i++) {
      if (a[i] - a[rs] <= t) {
        res++;
        r = i;
        ok = true;
      } else {
        break;
      }
    }
    if (!ok) {
      break;
    }
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> a[i];
  }
  std::sort(a, a + N);
  int res = 0;
  for (int i = 0; i < N; i++) {
    int x = sim(i);
    res = std::max(res, x);
  }
  std::cout << res << "\n";
  return 0;
}
