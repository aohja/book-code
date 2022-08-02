/**
 * Author:  Aadi Ohja
 * Created: 31/07/2022 22:16:07
 * Problem: Censoring
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

const int SMAX = 1e6 + 5;
const int WMAX = 105;

char s[SMAX];
char w[WMAX];

std::vector<char> buf;

bool check(int idx) {
    for (int i = idx; i < sz(buf); i++) {
        if (buf[i] != w[i - idx]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%s %s", s, w);
    int n = strlen(s); int m = strlen(w);
    for (int i = 0; i < n; i++) {
        buf.push_back(s[i]);
        if (sz(buf) >= m && check(sz(buf) - m)) {
            for (int j = 0; j < m; j++) {
                buf.pop_back();
            }
        }
    }
    for (int i = 0; i < sz(buf) - 1; i++) {
        printf("%c", buf[i]);
    }
    printf("%c\n", buf[sz(buf) - 1]);
    return 0;
}
