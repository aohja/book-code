/**
 * Author:  Aadi Ohja
 * Created: 26/07/2022 17:07:09
 * Problem: Square Pasture 
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

int p1[4], p2[4];

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d", p1 + i);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", p2 + i);
    }
    int s1 = std::max(p2[2], p1[2]) - std::min(p2[0], p1[0]);
    int s2 = std::max(p2[3], p1[3]) - std::min(p1[1], p2[1]);
    int ans = std::max(s1, s2) * std::max(s1, s2);
    printf("%d\n", ans);
    return 0;
}

