/**
 * Author:  Aadi Ohja
 * Created: 29/07/2022 22:01:37
 * Problem: Team Tic Tac Toe 
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

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

char grid[3][4];

int row(int r) {
    int unq = 0;
    std::map<char, bool> mp;
    for (int i = 0; i < 3; i++) {
        if (!mp.count(grid[r][i])) {
            unq++;
        }
        mp[grid[r][i]] = 1;
    }
    return unq;
}

int col(int c) {
    int unq = 0;
    std::map<char, bool> mp;
    for (int i = 0; i < 3; i++) {
        if (!mp.count(grid[i][c])) {
            unq++;
        }
        mp[grid[i][c]] = 1;
    }
    return unq;
}

int ldiag() {
    int unq = 0;
    std::map<char, bool> mp;
    for (int i = 0; i < 3; i++) {
        if (!mp.count(grid[i][i])) {
            unq++;        
        }
        mp[grid[i][i]] = 1;
    }
    return unq;
}

int rdiag() {
    int unq = 0;
    std::map<char, bool> mp;
    for (int i = 0; i < 3; i++) {
        debug(i, 2 - i);
        if (!mp.count(grid[i][2 - i])) {
            unq++;        
        }
        mp[grid[i][2 - i]] = 1;
    }
    return unq;
}

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%s", grid[i]);
    }
    int ans[4];
    memset(ans, 0, 12);
    for (int i = 0; i < 3; i++) {
        ans[col(i)]++;
        ans[row(i)]++;
    }
    ans[ldiag()]++;
    ans[rdiag()]++;
    print(ans[1], '\n');
    print(ans[2], '\n');
    return 0;
}
