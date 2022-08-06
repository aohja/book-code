/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 08:43:18
 * Problem: Diamond Collector (Bronze) 
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

const int NMAX = 1001;
int N, K;
int a[NMAX];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i <= 10000; i++) {
        int res = 0;
        for (int j = 0; j < N; j++) {
            if (a[j] >= i && a[j] - i <= K) {
                res++;
            }
        }
        ans = std::max(res, ans);
    }
    std::cout << ans << "\n";
    return 0;
}
