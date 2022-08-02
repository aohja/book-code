/**
 * Author:  Aadi Ohja
 * Created: 01/08/2022 19:09:43
 * Problem: E. Add Modulo 10
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

ll find(ll x, ll tar) {
    ll y = x;
    ll tt = x % 10;
    while ((tt % 10 != 0 || tt % 10 != 2) && y > 0) {
        tt = (tt % 10) % 10;
        y -= tt;
    }
    if (y == 0) {
        return true;
    } 
    y -= 20 * (y / 20);
    if (y == 0 || y == 2 || y == 6 || y == 14) {
        return true;
    } else {
        return false;
    }
}

void sol() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    ll l = 1, r = 20;
    while (l <= r) {
        ll md = l + (r - l) / 2;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            ok &= find(a[i], md); 
        }
        debug(md);
        if (ok) {
            std::cout << "YES\n";
            return;
        } else {
            l = md + 1;
        }
    }
    std::cout << "NO\n";
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
