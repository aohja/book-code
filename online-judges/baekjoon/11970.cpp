/**
 * Author:  Aadi Ohja
 * Created: 26/07/2022 16:12:46
 * Problem: Fence Painting 
**/
#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using ll = long long;

int a, b, c, d;
int p[101];

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    for (int i = a; i < b; i++) {
        p[i] = 1;
    }
    for (int i = c; i < d; i++) {
        p[i] = 1;
    }
    int res = 0;
    for (int i = 0; i < 101; i++) {
        res += p[i];
    }
    printf("%d\n", res);
    return 0;
}

