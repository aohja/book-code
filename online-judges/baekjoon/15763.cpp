/**
 * Author:  Aadi Ohja
 * Created: 29/07/2022 22:01:37
 * Problem: Team Tic Tac Toe 
**/
#include <bits/stdc++.h>
#define For(i, x, y) for (int i = (int) x; i < (int) y; i++) 
#define Rof(i, x, y) for (int i = (int) x; i >= (int) y; --i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

#ifdef LOCAL
#include "ddebug.h"
#else
#define debug(...) 42
#endif

namespace Read {
template<class T> void Read(T& x) {
  std::cin >> x;
}
template<class T> void Read(std::vector<T>& v) {
  For(i, 0, sz(v)) {
    read(v[i]);
  } 
}
void read() {}
template<class H, class... T> void read(H& h, T&... t) {
  Read(h);
  read(t...);
}
}

namespace Write {
template<class T> void Write(const T& x) {
  std::cout << x;
}
template<typename T, typename V> void Write(const std::pair<T, V> x) {
  std::cout << x.first << " " << x.second;
}
template<typename T> void Write(const std::vector<T>& v) {
  For(i, 0, sz(v)) {
    Write(v[i]);
    if (i != sz(v) - 1) {
      Write(' ');
    }
  }
}
void write() {
  Write('\n');
};
template<class H, class... T> void write(const H& h, const T&... t) {
  Write(h);
  if (sizeof...(t))
    Write(' ');
  write(t...);
}
}

char board[3][3];

bool check_row(char a, char b) {
  For(i, 0, 3) {
    bool ok = true, seen_a = false, seen_b = false;
    For(j, 0, 3) {
      if (board[i][j] != a && board[i][j] != b) {
        ok = false;
        break;
      }
      if (board[i][j] == a) {
        seen_a =  true;
      }
      if (board[i][j] == b) {
        seen_b = true;
      }
    }
    if (ok && seen_a && seen_b) return true;
  }
  return false;
}

bool check_col(char a, char b) {
  For(i, 0, 3) {
    bool ok = true, seen_a = false, seen_b = false;
    For(j, 0, 3) {
      if (board[j][i] != a && board[j][i] != b) {
        ok = false;
        break;
      }
      if (board[j][i] == a) {
        seen_a =  true;
      }
      if (board[j][i] == b) {
        seen_b = true;
      }
    }
    if (ok && seen_a && seen_b) return true;
  }
  return false;
}

bool check_ldiag(char a, char b) {
  bool seen_a = false, seen_b = false;
  For(i, 0, 3) {
    if (board[i][i] != a && board[i][i] != b) {
      return false;
    }
    if (board[i][i] == a) {
      seen_a = true;
    }
    if (board[i][i] == b) {
      seen_b = true;
    }
  }
  return seen_a && seen_b;
}

bool check_rdiag(char a, char b) {
  bool seen_a = false, seen_b = false;
  For(i, 0, 3) {
    if (board[i][2 - i] != a && board[i][2 - i] != b) {
      return false;
    }
    if (board[i][2 - i] == a) {
      seen_a = true;
    }
    if (board[i][2 - i] == b) {
      seen_b = true;
    }
  }
  return seen_a && seen_b;
}

bool check(char a, char b) {
  return check_row(a, b) || check_col(a, b) || check_ldiag(a, b) || check_rdiag(a, b);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  For(i, 0, 3) {
    read(board[i]);
  }
  int sin = 0, dou = 0; 
  for (int i = 0; i < 26; i++) {
    char a = 'A' + i;
    sin += check(a, a);
    for (int j = 0; j < i; j++) {
      char b = (char) 'A' + j;
      dou += check(a, b);
    }
  }
  write(sin);
  write(dou);
  return 0;
}
