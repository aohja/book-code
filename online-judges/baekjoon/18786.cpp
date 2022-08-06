/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 10:38:08
 * Problem: Triangles (Bronze) 
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

const int NMAX = 101;
int N;
ll x[NMAX], y[NMAX];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < N; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (x[i] == x[j] && y[k] == y[i]) {
                    ans = std::max(ans, llabs((y[k] - y[j]) * (x[k] - x[j])));
                } 
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}
