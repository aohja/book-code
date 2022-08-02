/**
 * Author:  Aadi Ohja
 * Created: 01/08/2022 18:15:36
 * Problem: D. Color with Occurrences
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

const int NMAX = 15;
const int SMAX = 105;
int T, n;
std::string s;
std::vector<std::string> w(NMAX);
int dp[SMAX];
int pre[SMAX], pre2[SMAX];

bool check(int idx, int j) {
    if (idx <= 0 || dp[idx - 1] == 1e9) {
        return false;
    }
    int l = sz(w[j]);
    for (int i = idx; i < l + idx; i++) {
        if (s[i] != w[j][i - idx]) {
            return false;
        }
    }
    return true;
}

void sol() {
    std::cin >> s >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }
    s = '-' + s;
    std::fill(dp, dp + SMAX, 1e9);
    std::fill(pre, pre + SMAX, 1e9);
    dp[0] = 0;
    pre[0] = 0;
    int m = sz(s);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int idx = i - sz(w[j]);
            if (check(idx + 1, j)) {
                for (int k = idx + 1; k < sz(w[j]) + idx + 1; k++) {
                    if (dp[k] > dp[idx] + 1) {
                        dp[k] = dp[idx] + 1;
                        pre[k] = j;
                        pre2[k] = idx;
                    }
                }
            }
        }
    }
    if (dp[m - 1] == 1e9) {
        std::cout << -1 << "\n";
    } else {
        std::cout << dp[m - 1] << "\n"; 
        std::vector<std::pair<int, int>> path;
        int idx = m - 1;
        while (idx != 0) {
            int word = pre[idx];
            path.push_back({word, pre2[idx] + 1});
            idx = pre2[idx];
        }
        std::reverse(path.begin(), path.end());
        for (auto [x, y] : path) {
            std::cout << x << " " << y << "\n";
        }
    }
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
