/**
 * Author:  Aadi Ohja
 * Created: 29/07/2022 16:19:26
 * Problem: Circular Barn (Bronze) 
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

const int NMAX = 1001;
int N;
int r[NMAX];

int go(int s) {
    int res = 0;
    int d = 0;
    for (int i = s; i < s + N; i++) {
        res += d * r[i % N];
        d++;
    }
    return res;
}

int main() {
    read(N);
    for (int i = 0; i < N; i++) {
        read(r[i]);
    }
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        ans = std::min(ans, go(i));
    }
    print(ans, '\n');
    return 0;
}
