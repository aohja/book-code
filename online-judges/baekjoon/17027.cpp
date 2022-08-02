/**
 * Author:  Aadi Ohja
 * Created: 28/07/2022 18:05:09
 * Problem: Shell Game 
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
int a[NMAX][2];
int guess[NMAX];

int sim(int start) {
    int x[3] = {0, 0, 0};
    x[start]++;
    int total = 0;
    for (int i = 0; i < N; i++) {
        std::swap(x[a[i][0]], x[a[i][1]]);
        if (x[guess[i]] == 1) {
            total++;
        }
    }
    return total;
}

int main() {
    read(N);
    for (int i = 0; i < N; i++) {
        read(a[i][0]); read(a[i][1]);
        --a[i][0]; --a[i][1];
        read(guess[i]);
        --guess[i];
    }
    int ans = std::max(sim(0), std::max(sim(1), sim(2)));
    print(ans, '\n');
    return 0;
}
