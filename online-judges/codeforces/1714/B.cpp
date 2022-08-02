/**
 * Author:  Aadi Ohja
 * Created: 01/08/2022 17:50:50
 * Problem: B. Remove Prefix
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
const int NMAX = 200005;
int n;
int a[NMAX];

void sol() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::map<int, bool> mp;
    for (int i = n - 1; i >= 0; --i) {
        if (mp.count(a[i])) {
            std::cout << i + 1 << "\n";
            return;
        }
        mp[a[i]] = 1;
    }
    std::cout << 0 << "\n";
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
