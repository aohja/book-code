/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 10:22:26
 * Problem: Bovine Genomics (Bronze) 
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

const int NMAX = 101, MMAX = 101;
int N, M;
char a[NMAX][MMAX], b[NMAX][MMAX];

int loc(char c) {
    if (c == 'A') {
        return 0;
    } else if (c == 'C') {
        return 1;
    } else if (c == 'G') {
        return 2;
    } else {
        return 3;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        bool seen[4] = {0, 0, 0, 0};
        for (int j = 0; j < N; j++) {
            seen[loc(a[j][i])] = 1;
        }
        bool ok = true;
        for (int j = 0; j < N; j++) {
            if (seen[loc(b[j][i])]) {
                ok = false;
            }
        }
        ans += ok;
    }
    std::cout << ans << "\n";
    return 0;
}
