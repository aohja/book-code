/**
 * Author:  Aadi Ohja
 * Created: 01/08/2022 17:58:20
 * Problem: C. Minimum Varied Number
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
int s;

int query[46];

void prep() {
    std::fill(query, query + 46, 2e9);
    for (int i = 0; i < (1 << 9); i++) {
        std::string s = "";
        int total = 0;
        for (int j = 0; j < 9; j++) {
            if (i & (1 << j)) {
                s += std::to_string(j + 1);
                total += j + 1;
            }
        }
        if (total != 0) {
            query[total] = std::min(query[total], std::stoi(s));
        }
    }
}

void sol() {
    std::cin >> s;
    std::cout << query[s] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> T;
    prep();
    for (int i = 0; i < T; i++) {
        sol();
    }
    return 0;
}
