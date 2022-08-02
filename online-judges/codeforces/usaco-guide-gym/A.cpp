/**
 * Author:  Aadi Ohja
 * Created: 01/08/2022 14:57:51
 * Problem: A. Maximum Distance
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

const int NMAX = 5005;
int N;
int x[NMAX], y[NMAX];

int sqr(int a) {
    return a * a;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> x[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> y[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans = std::max(sqr(x[i] - x[j]) + sqr(y[i] - y[j]), ans);
        }
    } 
    std::cout << ans << "\n";
    return 0;
}
