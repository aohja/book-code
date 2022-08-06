/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 11:11:42
 * Problem: Lifeguards (Bronze) 
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
int a[NMAX], b[NMAX];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i] >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int grid[1000];
        memset(grid, 0, 4000);
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            for (int k = a[j]; k < b[j]; k++) {
                grid[k] = 1;
            }
        }
        int res = 0;
        for (int j = 0; j < 1000; j++) {
            if (grid[j]) {
                res++;
            }
        }
        ans = std::max(ans, res);
    }
    std::cout << ans << "\n";
    return 0;
}
