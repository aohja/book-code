/**
 * Author:  Aadi Ohja
 * Created: 09/08/2022 21:17:07
 * Problem: Where Am I?
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

int N;
std::string str;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N >> str;
  for (int i = 1; i < N; i++) {
    std::set<std::string> s;
    bool ok = true;
    for (int j = i - 1; j < N; j++) {
      std::string t = "";
      for (int k = j - i + 1; k <= j; k++) {
        t += str[k];
      }
      if (s.count(t)) {
        ok = false;
      }
      s.insert(t);
    }
    if (ok) {
      std::cout << i << "\n";
      return 0;
    }
  }
  return 0;
}
