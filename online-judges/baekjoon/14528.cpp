/**
 * Author:  Aadi Ohja
 * Created: 03/08/2022 10:38:21
 * Problem: Bovine Genomics (Silver) 
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

const int NMAX = 501, MMAX = 51;
int N, M;
char s[NMAX][MMAX], p[NMAX][MMAX];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        std::cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                std::map<std::string, bool> mp;
                for (int l = 0; l < N; l++) {
                    std::string t = "";
                    t += s[l][i]; t += s[l][j]; t += s[l][k];
                    mp[t] = 1;
                }
                bool ok = true;
                for (int l = 0; l < N; l++) {
                    std::string t = "";
                    t += p[l][i]; t += p[l][j]; t += p[l][k];
                    if (mp.count(t)) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    ans++;
                }
            } 
        }
    }
    std::cout << ans << "\n";
    return 0;
}
