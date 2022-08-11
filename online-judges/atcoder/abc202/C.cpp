/**
 * Author:  Aadi Ohja
 * Created: 10/08/2022 18:30:16
 * Problem: C - Made Up
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

int N, a[100005], b[100005], c[100005];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  read(N);
  For(i, 1, N + 1) {
    read(a[i]);
  }
  For(i, 1, N + 1) {
    read(b[i]);
  }
  For(i, 1, N + 1) {
    read(c[i]);
  }
  std::map<int, int> mp;
  For(i, 1, N + 1) {
    mp[b[c[i]]]++;
  }
  ll ans = 0;
  For(i, 1, N + 1) {
    ans += mp[a[i]];
  }
  write(ans);
  return 0;
}
