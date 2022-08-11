/**
 * Author:  Aadi Ohja
 * Created: 10/08/2022 18:11:24
 * Problem: Don't Be Last!
**/
#include <bits/stdc++.h>
#define For(i, x, y) for (int i = (int) x; i < (int) y; i++) 
#define Rof(i, x, y) for (int i = (int) x; i >= (int) y; i--) 
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

int N;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  read(N);
  std::map<std::string, int> mp;
  For(i, 0, N) {
    std::string s;
    int x;
    read(s, x);
    mp[s] += x;
  }
  if (sz(mp) < 7) {
    mp["-"] = 0;
  }
  std::map<int, std::vector<std::string>> mp2;
  for (auto p : mp) {
    mp2[p.second].push_back(p.first);
  }
  int cnt = 0;
  for (auto p : mp2) {
    cnt++;
    if (cnt == 2) {
      if (sz(p.second) == 1) {
        write(p.second[0]);
        return 0;
      } 
    }
  }
  write("Tie");
  return 0;
}
