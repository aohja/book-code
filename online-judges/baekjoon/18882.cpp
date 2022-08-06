/**
 * Author:  Aadi Ohja
 * Created: 04/08/2022 21:00:56
 * Problem: Cowntact Tracing
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

const int NMAX = 102, TMAX = 251;
int N, T;
char a[102];
int inf[NMAX];
int times[TMAX + 1][2];

bool sim(int c, int k) {
  int b[N + 1];
  for (int i = 1; i <= N; i++) {
    if (i == c) {
      b[i] = 1;
    } else {
      b[i] = 0;
    }
  }
  int cnt[N + 1];
  memset(cnt, 0, 4 * N + 4);
  for (int i = 0; i <= TMAX; i++) {
    int x = times[i][0]; int y = times[i][1];
    if (x == 0) {
        continue;
    }
    if (b[x] == 1) {
        cnt[x]++;
    }
    if (b[y] == 1) {
        cnt[y]++;
    }
    if (b[x] == 1 && cnt[x] <= k) {
      b[y] = 1;
    }
    if (b[y] == 1 && cnt[y] <= k) {
      b[x] = 1;
    }
  }
  for (int i = 1; i <= N; i++) {
    if (b[i] != inf[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N >> T;
  std::cin >> a;
  for (int i = 0; i < N; i++) {
    inf[i + 1] = a[i] - '0';
  }
  for (int i = 0; i < T; i++) {
    int t;
    std::cin >> t;
    std::cin >> times[t][0] >> times[t][1];
  }
  int ans = 0;
  int mnk = 1e9, mxk = 0;
  for (int i = 1; i <= N; i++) {
    bool ok = false;
    for (int j = 0; j <= TMAX; j++) {
      if (sim(i, j)) {
        ok = true;
        mnk = std::min(mnk, j);
        mxk = std::max(mxk, j);
      }
    }
    if (ok) {
      ans++;
    }
  }
  std::string ub = std::to_string(mxk);
  if (mxk == 251) {
    ub = "Infinity";
  }
  std::cout << ans << " " << mnk << " " << ub << "\n";
  return 0;
}
