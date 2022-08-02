/**
 * Author:  Aadi Ohja
 * Created: 28/07/2022 19:08:44
 * Problem: Mixing Milk 
**/
#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

#ifdef LOCAL
#include "ddebug.h"
#endif

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

int c[3], m[3];

int main() {
    for (int i = 0; i < 3; i++) {
        read(c[i]); read(m[i]);
    }
    for (int i = 0; i < 100; i++) {
        int t = std::min(m[i % 3], c[(i + 1) % 3] - m[(i + 1) % 3]);
        m[i % 3] -= t;
        m[(i + 1) % 3] += t;
    }
    print(m[0], '\n');
    print(m[1], '\n');
    print(m[2], '\n');
    return 0;
}
