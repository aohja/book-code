/**
 * Author:  Aadi Ohja
 * Created: 29/07/2022 19:28:25
 * Problem: Block Game 
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
char s1[NMAX][11], s2[NMAX][11];

int main() {
    read(N);
    for (int i = 0; i < N; i++) {
        scanf("%s", s1[i]);
        scanf("%s", s2[i]);
    }
    int a[26], b[26], c[26];
    memset(a, 0, 4 * 26);
    for (int i = 0; i < N; i++) {
        memset(b, 0, 4 * 26);
        memset(c, 0, 4 * 26);
        int n = strlen(s1[i]);
        int m = strlen(s2[i]);
        for (int j = 0; j < n; j++) {
            b[s1[i][j] - 'a']++;
        }
        for (int j = 0; j < m; j++) {
            c[s2[i][j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            a[j] += std::max(b[j], c[j]);
        }
    }
    for (int i = 0; i < 26; i++) {
        print(a[i], '\n');
    }
    return 0;
}
