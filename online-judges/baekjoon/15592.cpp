/**
 * Author:  Aadi Ohja
 * Created: 26/07/2022 20:28:10
 * Problem: Blocked Billboard II 
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

int a[4], b[4];

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", b + i);
    }
    int area = (a[3] - a[1]) * (a[2] - a[0]);
    bool intersect = true;
    if (a[0] >= b[2] || b[0] >= a[2] || a[1] >= b[3] || b[1] >= a[3]) {
        intersect = false;
    }
    if (!intersect) {
        printf("%d\n", area);
        return 0;
    }
    int h = std::min(a[3], b[3]) - std::max(a[1], b[1]);
    int w = std::min(a[2], b[2]) - std::max(a[0], b[0]);
    if (h == a[3] - a[1] && (b[0] <= a[0] || b[2] >= a[2])) {
        printf("%d\n", area - h * w);
        return 0;
    }
    if (w == a[2] - a[0] && (b[1] <= a[1] || b[3] >= a[3])) {
        printf("%d\n", area - h * w);
        return 0;
    }
    printf("%d\n", area);
    return 0;
}
