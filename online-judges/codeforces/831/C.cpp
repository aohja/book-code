/**
 * Author:  Aadi Ohja
 * Created: 10/08/2022 21:33:23
 * Problem: C. Jury Marks
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

int k, n, a[2005], b[2005], pre[2005];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  read(k, n);
  std::map<int, bool> mp, seen;
  For(i, 0, k) {
    read(a[i]);
  }
  For(i, 0, n) {
    read(b[i]);
    mp[b[i]] = false;
  }
  pre[0] = 0;
  For(i, 1, k + 1) {
    pre[i] = pre[i-1] + a[i-1];
  }
  int ans = 0;
  For(i, 0, k) {
    int x = b[0] - pre[0] - pre[i+1];
    int cnt = 0;
    For(j, 0, k) {
      x += a[j];
      if (mp.count(x) && mp[x] == false) {
        cnt++;
        mp[x] = true;
      }
    }
    if (cnt == n && seen.count(x) == 0) {
      seen[x] = true;
      ans++;
    }
    For(i, 0, n) {
      mp[b[i]] = false;
    }
  }
  write(ans);
  return 0;
}
