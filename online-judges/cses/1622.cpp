/**
 * Author:  Aadi Ohja
 * Created: 06/08/2022 21:12:52
 * Problem: Creating Strings
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

std::string s;
std::map<std::string, bool> mp;

void gen(std::string s1, std::string s2) {
  if (s2 == "") {
    mp[s1] = 1;
  } else {
    for (int i = 0; i < sz(s2); i++) {
      std::string cp1 = std::string(s1);
      std::string cp2 = std::string(s2);
      cp1 += s2[i];
      cp2.erase(cp2.begin() + i);
      gen(cp1, cp2);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> s;
  gen("", s);
  std::cout << sz(mp) << "\n";
  for (auto p : mp) {
    std::cout << p.first << "\n";
  }
  return 0;
}
