/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 08:28:55
 * Problem: Milk Pails (Bronze) 
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

int X, Y, M;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> X >> Y >> M;
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (i * X + j * Y <= M) {
                ans = std::max(ans, i * X + j * Y);
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}
