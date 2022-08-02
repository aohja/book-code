/**
 * Author:  Aadi Ohja
 * Created: 28/07/2022 12:01:08
 * Problem: B. Two Tables
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

int T;
int W, H, w, h;
int a[4];

bool intersect(int* r1, int* r2) {
    if (r1[0] >= r2[2] || r2[0] >= r1[2] || r1[1] >= r2[3] || r2[1] >= r1[3]) {
        return false;
    }
    return true;
}

int bl() {
    int b[4] = {0, 0, w, h};
    if (!intersect(a, b)) {
        return 0;
    }
    int ans = 1e9;
    if (w + a[2] - a[0] <= W) {
        ans = std::min(ans, w - a[0]);
    }
    if (h + a[3] - a[1] <= H) {
        ans = std::min(ans, h - a[1]);
    }
    return ans;
}

int tl() {
    int b[4] = {0, H - h, w, H};
    if (!intersect(a, b)) {
        return 0;
    }
    int ans = 1e9;
    if (w + a[2] - a[0] <= W) {
        ans = std::min(ans, w - a[0]);
    }
    if (h + a[3] - a[1] <= H) {
        ans = std::min(ans, a[3] - H + h);
    }
    return ans; 
}

int br() {
    int b[4] = {W - w, 0, W, h};
    if (!intersect(a, b)) {
        return 0;
    }
    int ans = 1e9;
    if (w + a[2] - a[0] <= W) {
        ans = std::min(ans, a[2] - W + w);
    }
    if (h + a[3] - a[1] <= H) {
        ans = std::min(ans, h - a[1]);
    }
    return ans;
}

int tr() {
    int b[4] = {W - w, H - h, W, H};
    if (!intersect(a, b)) {
        return 0;
    }
    int ans = 1e9;
    if (w + a[2] - a[0] <= W) {
        ans = std::min(ans, a[2] - W + w);
    }
    if (h + a[3] - a[1] <= H) {
        ans = std::min(ans, a[3] - H + h);
    }
    return ans;
}

void sol() {
    scanf("%d %d", &W, &H);
    for (int i = 0; i < 4; i++) {
        scanf("%d", a + i);
    }
    scanf("%d %d", &w, &h);
    int ans = std::min(std::min(bl(), tl()), std::min(br(), tr()));
    if (ans == 1e9) {
        ans = -1;
    }
    printf("%d\n", ans);
    return;
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        sol();
    }
    return 0;
}
