/**
 * Author:  Aadi Ohja
 * Created: 10/08/2022 12:49:42
 * Problem: Year of the Cow 
**/
#include <bits/stdc++.h>
#define For(i, x, y) for (int i = (int) x; i < (int) y; i++) 
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

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

using ll = long long;
using Read::read;
using Write::write;

#ifdef LOCAL
#include "ddebug.h"
#else
#define debug(...) 42
#endif

int N, x[101];
std::vector<std::vector<std::string>> info(101);

std::map<std::string, int> mp {
    {"Ox", 0}, 
    {"Tiger", 1},
    {"Rabbit", 2},
    {"Dragon", 3},
    {"Snake", 4},
    {"Horse", 5},
    {"Goat", 6},
    {"Monkey", 7},
    {"Rooster", 8},
    {"Dog", 9},
    {"Pig", 10},
    {"Rat", 11},
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::map<std::string, std::string> ani = {{"Bessie", "Ox"}};
  read(N);
  For(i, 0, N) {
    For(j, 0, 8) {
      std::string s;
      read(s);
      info[i].push_back(s);
    }
    ani[info[i][0]] = info[i][4];
  }
  std::map<std::string, int> tt = {{"Bessie", 0}};
  For(i, 0, N) {
    For(j, 0, N) {
      std::string fir = info[j][0], sec = info[j][7];
      if (tt.count(sec) && !tt.count(fir)) {
        if (info[j][3] == "next") {
          int x = (mp[ani[fir]] - mp[ani[sec]]);
          if (x <= 0) {
            x += 12;
          }
          tt[fir] = tt[sec] + x;
        } else {
          int x = mp[ani[sec]] - mp[ani[fir]];
          if (x <= 0) {
            x += 12;
          }
          tt[fir] = tt[sec] - x;
        }
      }
    } 
  }
  write(abs(tt["Elsie"]));
  return 0;
}
