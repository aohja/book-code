/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 09:26:44
 * Problem: Counting Liars 
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

const int NMAX = 1001;
int N;
int p[NMAX];
char c[NMAX];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> c[i] >> p[i];
    }
    int ans = N;
    for (int i = 0; i < N; i++) {
        int res = 0;
        for (int j = 0; j < N; j++) {
            if (c[j] == 'L' && p[j] < p[i]) {
                res++;
            }
            if (c[j] == 'G' && p[j] > p[i]) {
                res++;
            }
        }
        ans = std::min(res, ans);
    }
    std::cout << ans << "\n";
    return 0;
}
