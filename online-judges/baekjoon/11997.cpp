/**
 * Author:  Aadi Ohja
 * Created: 06/08/2022 10:18:50
 * Problem: Load Balancing (Silver) 
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

const int NMAX = 1001;
int N;
std::vector<std::pair<int, int>> co;

int find(int a[4]) {
  return std::max(std::max(a[0], a[1]), std::max(a[2], a[3]));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N;
  co.resize(N);
  for (int i = 0; i < N; i++) {
    std::cin >> co[i].first >> co[i].second;
  }
  std::sort(all(co));
  int ans = N;
  for (int i = 0; i < N; i++) {
    int a[4] = {0, 0, 0, 0};
    int x = 0;
    int y = co[i].second - 1;
    for (int j = 0; j < N; j++) {
      int xx = co[j].first; int yy = co[j].second;
      if (xx < x && yy < y) a[0]++;
      if (xx < x && yy > y) a[1]++;
      if (xx > x && yy < y) a[2]++;
      if (xx > x && yy > y) a[3]++;
    }
    ans = std::min(ans, find(a));
    for (int j = 0; j < N; j++) {
      int yy = co[j].second;
      if (yy < y) {
        a[0]++; a[2]--;
      } else {
        a[1]++; a[3]--;
      }
      if (j == N - 1 || co[j].first != co[j + 1].first) {
        ans = std::min(ans, find(a));
      }
    }
  }
  std::cout << ans << "\n"; 
  return 0;
}
