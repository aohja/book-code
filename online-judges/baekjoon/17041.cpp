/**
 * Author:  Aadi Ohja
 * Created: 29/07/2022 14:19:01
 * Problem: Measuring Traffic 
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

const int NMAX = 101;
int N;
char s[NMAX][5]; 
int a[NMAX][2];

std::pair<int, int> fow() {
    int l = 0, r = 1001;
    for (int i = 0; i < N; i++) {
        if (strcmp(s[i], "none") == 0) {
            l = std::max(l, a[i][0]);
            r = std::min(r, a[i][1]);
        } else if (strcmp(s[i], "on") == 0) {
            l = std::max(0, l + a[i][0]);
            r = std::max(0, r + a[i][1]);
        } else {
            l = std::max(0, l - a[i][1]);
            r = std::max(0, r - a[i][0]);
        }
    }
    return {l, r};
}

std::pair<int, int> bac() {
    int l = 0, r = 1001;
    for (int i = N - 1; i >= 0; --i) {
        if (strcmp(s[i], "none") == 0) {
            l = std::max(l, a[i][0]);
            r = std::min(r, a[i][1]);
        } else if (strcmp(s[i], "off") == 0) {
            l = std::max(0, l + a[i][0]);
            r = std::max(0, r + a[i][1]);
        } else {
            l = std::max(0, l - a[i][1]);
            r = std::max(0, r - a[i][0]);
        }
    }
    return {l, r};
}

int main() {
    read(N);
    for (int i = 0; i < N; i++) {
        scanf("%s", s[i]);
        read(a[i][0]); read(a[i][1]);
    }
    auto [x, y] = fow();
    auto [u, v] = bac();
    printf("%d %d\n", u, v);
    printf("%d %d\n", x, y);
    return 0;
}
