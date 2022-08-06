/**
 * Author:  Aadi Ohja
 * Created: 03/08/2022 19:42:18
 * Problem: Load Balancing (Bronze) 
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
int N, B;
std::vector<std::pair<int, int>> p(NMAX);

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> B;
    for (int i = 0; i < N; i++) {
        std::cin >> p[i].first >> p[i].second;
    }
    int ans = NMAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a[4] = {0, 0, 0, 0};
            int x = p[i].first - 1;
            int y = p[j].second - 1;
            for (int k = 0; k < N; k++) {
                if (p[k].first < x && p[k].second < y) {
                    a[0]++;
                }
                if (p[k].first < x && p[k].second > y) {
                    a[1]++;
                }
                if (p[k].first > x && p[k].second < y) {
                    a[2]++;
                }
                if (p[k].first > x && p[k].second > y) {
                    a[3]++;
                }
            }
            ans = std::min(ans, std::max(std::max(a[0], a[1]), std::max(a[2], a[3])));
        }
    }
    std::cout << ans << "\n";
    return 0;
}
