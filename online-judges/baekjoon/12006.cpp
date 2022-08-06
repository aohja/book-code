/**
 * Author:  Aadi Ohja
 * Created: 05/08/2022 16:29:52
 * Problem: Bull in a China Shop (Bronze) 
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

const int NMAX = 9, KMAX = 11;
int N, K;
char o[NMAX][NMAX], t[NMAX][NMAX];
std::vector<std::vector<std::string>> p(KMAX);

void print() {
  std::cout << "===========================\n";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << t[i][j];
    }
    std::cout << "\n";
  }
  std::cout << "===========================\n";
}

bool gogo(int q, int l, int r) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int x = i + l;
      int y = j + r;
      if (x < 0 || x >= N) {
        if (p[q][i][j] == '#') {
          return false;
        }
        continue;
      }
      if (y < 0 || y >= N) {
        if (p[q][i][j] == '#') {
          return false;
        }
        continue;
      }
      if (t[x][y] == '#' && p[q][i][j] == '#') {
        return false;
      }
      if (t[x][y] == '#') {
        continue;
      }
      t[x][y] = p[q][i][j];
    }
  }
  return true;
}

bool place(int a, int b, int l1, int r1, int l2, int r2) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      t[i][j] = '.';
    }
  }
  if (!gogo(a, l1, r1)) return false;
  if (!gogo(b, l2, r2)) return false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (t[i][j] != o[i][j]) {
        return false;
      }
    }
  }
  return true;
}

bool check(int a, int b) {
  for (int i = -N + 1; i < N; i++) {
    for (int j = -N + 1; j < N; j++) {
      for (int k = -N + 1; k < N; k++) {
        for (int l = -N + 1; l < N; l++) {
          if (place(a, b, i, j, k, l)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> N >> K;
  for (int i = 0; i < N; i++) {
    std::cin >> o[i];
  }
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < N; j++) {
      std::string s; 
      std::cin >> s;
      p[i].push_back(s);
    }
  }
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < i; j++) {
      if (check(i, j)) {
        std::cout << j + 1 << " " << i + 1 << "\n";
        return 0;
      }
    }
  }
  return 0;
}
