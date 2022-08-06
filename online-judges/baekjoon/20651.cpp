/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 08:53:54
 * Problem: Daisy Chains
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
int p[NMAX];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int s = 0;
            for (int k = j; k <= i; k++) {
                s += p[k];
            }
            for (int k = j; k <= i; k++) {
                if (p[k] == s / (i - j + 1) && (s % (i - j + 1) == 0)) {
                    ans++;
                    break;
                }
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}
