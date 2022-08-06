/**
 * Author:  Aadi Ohja
 * Created: 04/08/2022 18:21:28
 * Problem: Contaminated Milk
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

const int NMAX = 51, MMAX = 51, DMAX = 1001, SMAX = 51;
int N, M, D, S;
int d[DMAX][3], s[SMAX][2], a[NMAX][MMAX];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N >> M >> D >> S;
  for (int i = 0; i < D; i++) {
    std::cin >> d[i][0] >> d[i][1] >> d[i][2];
    --d[i][0]; --d[i][1];
  }
  for (int i = 0; i < S; i++) {
    std::cin >> s[i][0] >> s[i][1];
    --s[i][0];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      a[i][j] = 1e9;
    }
  }
  for (int i = 0; i < D; i++) {
    int p = d[i][0]; int m = d[i][1]; int t = d[i][2];
    a[p][m] = std::min(a[p][m], t);
  }
  bool bad[M];
  for (int i = 0; i < M; i++) {
    bool ok = true;
    for (int j = 0; j < S; j++) {
      if (s[j][1] <= a[s[j][0]][i]) {
        ok = false;
      }
    }
    bad[i] = ok;
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    if (bad[i]) {
      int res = 0;
      for (int j = 0; j < N; j++) {
        if (a[j][i] < 1e9) {
          res++;
        }
      }
      ans = std::max(ans, res);
    }
  }
  std::cout << ans << "\n";
  return 0;
}
