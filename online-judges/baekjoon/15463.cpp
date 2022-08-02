/**
 * Author:  Aadi Ohja
 * Created: 26/07/2022 16:22:38
 * Problem: Blocked Billboard
**/
#include <bits/stdc++.h>
#include <print.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

int f[4], s[4], t[4];

int main() {
    for (int i = 0; i < 4; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &t[i]);
    }
    int ans = (f[2] - f[0]) * (f[3] - f[1]) + (s[2] - s[0]) * (s[3] - s[1]);
    if ((f[0] <= t[2] && t[0] < f[2]) && (f[1] <= t[3] && t[1] < f[3])) {
        ans -= (std::min(t[2], f[2]) - std::max(t[0], f[0])) * (std::min(t[3], f[3]) - std::max(t[1], f[1]));
    }
    if ((s[0] <= t[2] && t[0] < s[2]) && (s[1] <= t[3] && t[1] < s[3])) {
        ans -= (std::min(t[2], s[2]) - std::max(t[0], s[0])) * (std::min(t[3], s[3]) - std::max(t[1], s[1]));
    }
    printf("%d\n", ans);
    return 0;
}

