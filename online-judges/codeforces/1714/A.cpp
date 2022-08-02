/**
 * Author:  Aadi Ohja
 * Created: 01/08/2022 17:41:46
 * Problem: A. Everyone Loves to Sleep
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

int T;
int n, H, M;
int h[11], m[11];

int con(int a, int b) {
    return 60 * a + b;
}

void sol() {
    std::cin >> n >> H >> M;
    for (int i = 0; i < n; i++) {
        std::cin >> h[i] >> m[i];
    }
    int best = 10000;
    int curr = con(H, M);
    for (int i = 0; i < n; i++) {
        int t = con(h[i], m[i]);
        best = std::min(best, ((t - curr) + 1440) % 1440);
    }
    std::cout << best / 60 << " " << best % 60 << "\n";
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        sol();
    }
    return 0;
}
