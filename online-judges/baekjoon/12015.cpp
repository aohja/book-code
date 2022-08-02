/**
 * Author:  Aadi Ohja
 * Created: 25/07/2022 08:51:14
 * Problem: longest increasing subsequence 2
**/
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

typedef long long int64;

const int AMAX = 1000001;
int N;
int A[AMAX], B[AMAX];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < AMAX; i++) {
        B[i] = AMAX;
    }
    B[0] = 0;
    for (int i = 0; i < N; i++) {
        int l = 0, r = i;
        int best = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (B[m] < A[i]) {
                l = m + 1;
                best = m;
            } else {
                r = m - 1;
            }
        }
        B[best + 1] = std::min(B[best + 1], A[i]);
    }
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        if (B[i] < AMAX) {
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
