/**
 * Author:  Aadi Ohja
 * Created: 10/08/2022 20:49:32
 * Problem: Cities and States 
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
  std::map<std::string, std::vector<std::string>> mp;
  For(i, 0, N) {
    std::string city, state;
    read(city, state);
    mp[state].push_back(city);
  }
  std::map<std::pair<std::string, std::string>, int> data;
  int ans = 0;
  for (auto p : mp) {
    for (auto c : p.second) {
      std::string t1 = "", t2 = "";
      t1 += p.first[0]; t1 += p.first[1];
      t2 += c[0]; t2 += c[1];
      ans += data[std::make_pair(t2, t1)];
    }
    for (auto c : p.second) {
      std::string t1 = "", t2 = "";
      t1 += p.first[0]; t1 += p.first[1];
      t2 += c[0]; t2 += c[1];
      data[std::make_pair(t1, t2)]++;
    }
  }
  write(ans);
  return 0;
}
