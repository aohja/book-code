/**
 * Author:  Aadi Ohja
 * Created: 01/08/2022 09:14:10
 * Problem: Stuck in a Rut
**/
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

#ifdef LOCAL
#include "ddebug.h"
#else
#define debug(...) 42
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

const int NMAX = 51;
int N;
char dir[NMAX];
std::vector<std::array<ll, 3>> north;
std::vector<std::array<ll, 3>> east;

int main() {
    read(N);
    for (int i = 0; i < N; i++) {
        scanf("%c", &dir[i]);
        if (dir[i] == 'N') {
            ll x, y, z;
            read(x); read(y); z = i;
            north.push_back({x, y, z});
        } else {
            ll x, y, z;
            read(x); read(y); z = i;
            east.push_back({x, y, z});
        }
    }
    ll ans[NMAX];
    std::fill(ans, ans + N, 1e18);
    std::sort(all(north));
    std::sort(all(east), [](std::array<ll, 3> const &a, std::array<ll, 3> const &b) { return a[1] < b[1]; });
    for (int i = 0; i < sz(north); i++) {
        auto [x, y, z] = north[i];
        int idx = z;
        for (int j = 0; j < sz(east); j++) {
            auto [a, b, c] = east[j];
            int idx2 = c;
            if (ans[idx2] != 1e18 || b < y || a > x) {
                continue;
            }
            if (x - a < b - y) {
                ans[idx] = std::min(ans[idx], b - y);
                break;
            }
            if (x - a > b - y) {
                ans[idx2] = std::min(ans[idx2], x - a);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (ans[i] == 1e18) {
            printf("Infinity\n");
        } else {
            print(ans[i], '\n');
        }
    }
    return 0;
}
