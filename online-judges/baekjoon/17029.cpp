/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 14:09:48
 * Problem: Guess the Animal 
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
int N, K;
std::vector<std::map<std::string, bool>> v(NMAX);
char a[NMAX][101];
int c[NMAX];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i] >> c[i];
        for (int j = 0; j < c[i]; j++) {
            std::string s;
            std::cin >> s;
            v[i][s] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j || c[i] < c[j]) {
                continue;
            }
            int res = 0;
            for (auto [k, b] : v[i]) {
                if (v[j].count(k)) {
                    res++;
                }
            }
            ans = std::max(ans, res);
        }
    }
    std::cout << ans + 1 << "\n";
    return 0;
}
