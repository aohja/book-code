/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 10:04:14
 * Problem: Distinct Numbers
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

int N, x[200005];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> x[i];
  }
  std::sort(x, x + N);
  int unq = 1;
  for (int i = 1; i < N; i++) {
    if (x[i] != x[i - 1]) {
      unq++;
    }
  }
  std::cout << unq << "\n";
  return 0;
}
