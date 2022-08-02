/**
 * Author:  Aadi Ohja
 * Created: 28/07/2022 21:11:15
 * Problem: speeding 
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

int N, M;
int a[101];

int main() {
    read(N); read(M);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        int x, y;
        read(x); read(y);
        for (int j = idx; j < idx + x; j++) {
            a[j] = y;
        }
        idx += x;
    }
    idx = 0;
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int x, y;
        read(x); read(y);
        for (int j = idx; j < idx + x; j++) {
            ans = std::max(y - a[j], ans);
        }
        idx += x;
    }
    print(ans, '\n');
    return 0;
}
