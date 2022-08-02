/**
 * Author:  Aadi Ohja
 * Created: 29/07/2022 09:52:39
 * Problem: The Bucket List 
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
int a[NMAX][3];

int main() {
    read(N);
    for (int i = 0; i < N; i++) {
        read(a[i][0]); read(a[i][1]); read(a[i][2]);
    }
    int b[1005]; 
    std::fill(b, b + 1005, 0);
    for (int i = 0; i < N; i++) {
        for (int j = a[i][0]; j < a[i][1]; j++) {
            b[j] += a[i][2];
        }
    }
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        ans = std::max(ans, b[i]);
    }
    print(ans, '\n');
    return 0;
}
