/**
 * Author:  Aadi Ohja
 * Created: 28/07/2022 20:30:27
 * Problem: The Cow-Signal 
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

const int MMAX = 11;
const int NMAX = 11;
int M, N, K;
char s[MMAX][NMAX];

int main() {
    read(M); read(N); read(K);
    for (int i = 0; i < M; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < K * M; i++) {
        for (int j = 0; j < K * N; j++) {
            printf("%c", s[i / K][j / K]);
        }
        printf("\n");
    }
    return 0;
}
