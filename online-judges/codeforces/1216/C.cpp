/**
 * Author:  Aadi Ohja
 * Created: 28/07/2022 08:46:01
 * Problem: C. White Sheet
**/
#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

#ifdef LOCAL
#include "print.h"
#else
#define print(...) 42
#endif
 
int a[4], b[4], c[4];

bool check(bool g1, bool g2) {
    bool ok = false;
    if (g1 && b[1] <= a[1] && a[3] <= b[3]) {
        ok = true;
    }
    if (g2 && c[1] <= a[1] && a[3] <= c[3]) {
        ok = true;
    }
    if (g1 && g2 && b[3] >= c[1]) {
        int x = std::min(c[1], b[1]);
        int y = std::max(c[3], b[3]);
        if (x <= a[1] && a[3] <= y) {
            ok = true;
        }
    }
    return ok;
}

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", b + i);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", c + i);
    }
    if (b[1] > c[1]) {
        std::swap(b, c);
    }
    for (double i = a[0]; i < a[2]; i += 0.5) {
        bool g1 = false, g2 = false;
        if (b[0] <= i && i < b[2]) {
            g1 = true;
        }
        if (c[0] <= i && i < c[2]) {
            g2 = true;
        }
        if (!check(g1, g2)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

