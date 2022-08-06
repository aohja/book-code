/**
 * Author:  Aadi Ohja
 * Created: 02/08/2022 10:02:38
 * Problem: Cow Gymnastics 
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

const int NMAX = 21, KMAX = 11;
int N, K;
int a[KMAX][NMAX];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> K >> N;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
            debug(a[i][j]);
        }   
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            int pi = -1, pj = -1;
            bool ok = true;
            for (int k = 0; k < K; k++) {
                for (int l = 0; l < N; l++) {
                    if (a[k][l] == i) {
                        pi = l;
                    }
                    if (a[k][l] == j) {
                        pj = l;
                    }
                }
                if (pj > pi) {
                    ok = false;
                }
            }
            if (ok) {
                ans++;
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}
