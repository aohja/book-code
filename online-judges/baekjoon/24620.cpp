/**
 * Author:  Aadi Ohja
 * Created: 03/08/2022 20:54:53
 * Problem: Sleeping in Class
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
const int NMAX = 100001;
int N, S;
int a[NMAX];

bool gogo(int tar) {
  int idx = 0, x = 0, cnt = 0;
  while (idx < N) {
    x += a[idx];
    if (x == tar) {
      x = 0;
      cnt++;
    }
    idx++;
  }
  if (cnt == S / tar) {
    return true;
  }
  return false;
}

void sol() {
  std::cin >> N;
  S = 0;
  for (int i = 0; i < N; i++) {
    std::cin >> a[i];
    S += a[i];
  }
  if (S == 0) {
    std::cout << 0 << "\n";
    return;
  }
  int ans = N - 1;
  for (int i = 1; i * i <= S; i++) {
    if (S % i) {
      continue;
    }
    if (gogo(i)) {
      ans = std::min(ans, N - S / i);
    }
    if (gogo(S / i)) {
      ans = std::min(ans, N - i);
    }
  }
  std::cout << ans << "\n";
  return;
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
