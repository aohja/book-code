/**
 * Author:  Aadi Ohja
 * Created: 28/07/2022 21:58:30
 * Problem: The Lost Cow 
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

int pow(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= 2;
    }
    return res;
}

int x, y;

int main() {
    read(x); read(y);
    int l = x, r = x;
    int idx = 0;
    int total = 0;
    while (true) {
        if (idx % 2 == 0) {
            r = x + pow(idx);
            total += r - l;
            if (r >= y && y >= x) {
                total -= r - y;
                break;
            }
        } else {
            l = x - pow(idx);
            total += r - l;
            if (l <= y && y <= x) {
                total -= y - l;
                break;
            }
        }
        idx++;
    }
    print(total, '\n');
    return 0;
}
