/**
 * Author:  Aadi Ohja
 * Created: 01/08/2022 08:22:15
 * Problem: Milk Measurement 
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

const int NMAX = 101;
int N;
int d[NMAX], delta[NMAX];
char c[NMAX][9];
int m[3] = {7, 7, 7};
int l[3] = {1, 1, 1};

int find() {
    int t[3] = {0, 0, 0};
    if (m[0] >= std::max(m[1], m[2])) {
        t[0] = 1;
    } 
    if (m[1] >= std::max(m[0], m[2])) {
        t[1] = 1;
    } 
    if (m[2] >= std::max(m[0], m[1])) {
        t[2] = 1;
    }
    if (memcmp(t, l, 12) == 0) {
        return 0;
    } else {
        for (int i = 0; i < 3; i++) {
            l[i] = t[i];
        }
        return 1;
    }
}

int main() {
    read(N);
    for (int i = 0; i < N; i++) {
        char buf[1005];
        read(d[i]);
        scanf("%s %s", c[i], buf);
        delta[i] = atoi(buf);
    }
    bool used[N];
    memset(used, 0, N);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int idx = -1;
        for (int j = 0; j < N; j++) {
            if (used[j]) {
                continue;
            }
            if (idx == -1 || d[j] < d[idx]) {
                idx = j;
            }
        }
        if (strcmp(c[idx], "Mildred") == 0) {
            m[0] += delta[idx]; 
        } else if (strcmp(c[idx], "Elsie") == 0) {
            m[1] += delta[idx]; 
        } else {
            m[2] += delta[idx]; 
        }
        ans += find();
        used[idx] = true;
    }
    print(ans, '\n');
    return 0;
}
