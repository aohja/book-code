/**
 * Author:  Aadi Ohja
 * Created: 08/08/2022 15:31:02
 * Problem: Livestock Lineup
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
int a[8], b[8];
std::vector<std::string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
std::vector<std::string> buf(6);
std::vector<int> perm = {0, 1, 2, 3, 4, 5, 6, 7};

bool check() {
  int pos[8];
  for (int i = 0; i < 8; i++) {
    pos[perm[i]] = i;
  }
  /*
  for (int i = 0; i < 8; i++) {
    debug(pos[i]);
  }
  */
  for (int i = 0; i < N; i++) {
    if (abs(pos[a[i]] - pos[b[i]]) != 1) {
      return false;
    }
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::map<std::string, int> mp;
  mp["Beatrice"] = 0;
  mp["Belinda"] = 1;
  mp["Bella"] = 2;
  mp["Bessie"] = 3;
  mp["Betsy"] = 4;
  mp["Blue"] = 5;
  mp["Buttercup"] = 6;
  mp["Sue"] = 7;
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    for (int i = 0; i < 6; i++) {
      std::cin >> buf[i];
    }
    a[i] = mp[buf[0]]; b[i] = mp[buf[5]];
  }
  do {
    if (check()) {
      for (int i = 0; i < 8; i++) {
        std::cout << cows[perm[i]] << "\n";
      }
      return 0;
    }
  } while (std::next_permutation(all(perm)));
  return 0;
}
