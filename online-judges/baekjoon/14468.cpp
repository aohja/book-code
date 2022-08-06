/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 11:25:31
 * Problem: Why Cows Crossed the Road 2 
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

char s[53];
int pos[26][2];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> s;
    for (int i = 0; i < 26; i++) {
        pos[i][0] = -1; pos[i][1] = -1;
    }
    for (int i = 0; i < 52; i++) {
        int idx = s[i] - 'A';
        if (pos[idx][0] == -1) {
            pos[idx][0] = i;
        } else {
            pos[idx][1] = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < i; j++) {
            if (pos[i][0] < pos[j][0] && pos[j][0] < pos[i][1] && pos[i][1] < pos[j][1]) {
                ans++;
            }
            if (pos[j][0] < pos[i][0] && pos[i][0] < pos[j][1] && pos[j][1] < pos[i][1]) {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}
